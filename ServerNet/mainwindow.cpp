#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <string>
#include <QMap>
#include <unordered_map>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new NetworkServer(this); // 创建一个服务器对象，其父对象为当前窗口

    ui->ShowClient1->setReadOnly(true);
    ui->ShowClient2->setReadOnly(true);

    connect(ui->PortButton, &QPushButton::clicked, this, &MainWindow::listen_port); // 开启服务器监听
    connect(ui->restart, &QPushButton::clicked, this, &MainWindow::restart_server); // 重启服务器
    connect(server, &NetworkServer::receive, this, &MainWindow::receive_from_client);
    // receive 是服务端收到消息后发出的信号，receive_from_client 是处理这个信号的槽函数
}

void MainWindow::listen_port() {
    this->port = ui->PortEdit->text().toInt();
    server->listen(QHostAddress::Any, this->port);
    // 一行代码搞定监听，它会在所有 ip 地址上监听指定端口 port
    // 所谓监听，就是在网络上服务器要开始盯住某个端口，此时客户端可以通过这个端口和服务器取得联系
    // QHostAddress::Any 表示监听所有 ip 地址，在不考虑安全的情况下，这是一个比较方便的选择，你不用纠结为什么
    ui->PortButton->setEnabled(false);
    ui->PortEdit->setReadOnly(true);
    ui->PortEdit->setText("Listening...");
}

void MainWindow::remove_client(QTcpSocket* client) {
    if (client == client1) {
        client1 = nullptr;
        ui->ShowClient1->setText("");
    }
    else if (client == client2) {
        client2 = nullptr;
        ui->ShowClient2->setText("");
    }
    clients.remove(client);
}

void MainWindow::receive_from_client(QTcpSocket* client, NetworkData data) {
    // client 是发送消息的客户端，data 是消息内容
    // 以下代码首先处理客户端的连接和断开，然后处理从客户端收到的消息，显示在界面上并转发给另一个客户端
    // 你们在游戏里要做类似的事情，只不过处理不仅仅是显示，而是对应的游戏逻辑


    if (data.op == OPCODE::LEAVE_OP) {
        remove_client(client);
        return;
    }
    if (!clients.contains(client)) {
        if (clients.size() >= max_clients) {
            QMessageBox::warning(this, "Warning", "The server is full!");
            return;
        }
        clients.insert(client);
        if (!client1)
            client1 = client;
        else if (!client2)
            client2 = client;
    }
    if (client == client1) {
        this->ui->ShowClient1->setText(data.data2);
        if (client2 && data.op == OPCODE::CHAT_OP)
            send_to_another_client(client2, data);
    }
    else if (client == client2) {
        this->ui->ShowClient2->setText(data.data2);
        if (client1 && data.op == OPCODE::CHAT_OP)
            send_to_another_client(client1, data);
    }
    else
        QMessageBox::warning(this, "Warning", "Unknown client!");


    //QMap<QTcpSocket*, QVector<NetworkData>> ReadyData;

    if (data.op == OPCODE::READY_OP) {
        int ready=0;

        if (data.data3.toInt() > 255 || data.data3.toInt() < 0 || data.data3.length() > 3) {
            this->server->send(client, NetworkData(OPCODE::REJECT_OP, data.data1, "", ""));
        } else if (data.data2 != "0" && data.data2 != "1") {
            this->server->send(client, NetworkData(OPCODE::REJECT_OP, data.data1, "", ""));
        } else {
            ready++;
            if(ready<2){
                if(client == client1){
                    ReadyData[QPointer<QTcpSocket>(client1)].append(data);
                    return;
                }else{
                    ReadyData[QPointer<QTcpSocket>(client2)].append(data);
                    return;
                }

            }else{
                ReadyData[QPointer<QTcpSocket>(client)].append(data);
                //MainWindow(ReadyData[client1], ReadyData[client2]);
                dataVector1 = ReadyData[client1];
                dataVector2 = ReadyData[client2];
                username1 = dataVector1.last().data1;
                username2 = dataVector2.last().data1;
                color1 = (dataVector1.last().data2== "0") ? "0" : "1";
                color2 = (color1 == "0") ? "1" : "0";
                this->server->send(client2, NetworkData(OPCODE::READY_OP, username1, color2,dataVector2.last().data3 ));
                this->server->send(client1, NetworkData(OPCODE::READY_OP, username2, color1, dataVector1.last().data3));
            }

            // 检查是否收到了两个客户端的准备就绪消息
            /*if (roomReadyData[data.data3].size() == 2) {
                // 获取两个客户端的准备就绪数据
                NetworkData data1 = ReadyData[data.data2][0];
                NetworkData data2 = ReadyData[data.data2][1];

                // 分别发送 READY_OP 消息给双方客户端
                QString username1 = data1.data1;
                QString username2 = data2.data1;

                // 确定每个玩家的执棋颜色
                QString color1 = (data1.data2 == "0") ? "0" : "1";
                QString color2 = (color1 == "0") ? "1" : "0";

                // 向客户端发送 READY_OP 消息
                this->server->send(client2, NetworkData(OPCODE::READY_OP, username2, color2, data.data3));
                this->server->send(client1, NetworkData(OPCODE::READY_OP, username1, color1, data.data3));

                // 清除房间的准备就绪数据
                roomReadyData.remove(data.data3);
            }*/
        }
    }

    if(data.op == OPCODE::GIVEUP_OP){
        if(client == client1){
            this->server->send(client2, NetworkData(OPCODE::END_OP, "",QString::number(static_cast<int>(SurakartaEndReason::RESIGN)) , color2));
            this->server->send(client1, NetworkData(OPCODE::END_OP, "",QString::number(static_cast<int>(SurakartaEndReason::RESIGN)) , color2));
        }
        else{
            this->server->send(client2, NetworkData(OPCODE::END_OP, "",QString::number(static_cast<int>(SurakartaEndReason::RESIGN)) , color1));
            this->server->send(client1, NetworkData(OPCODE::END_OP, "",QString::number(static_cast<int>(SurakartaEndReason::RESIGN)) , color1));
        }
    }

    /*if(data.op==OPCODE::CHAT_OP){
        if(client == client1){
            ui->ShowClient1->setText("hello");
        }
    }*/

    if(data.op == OPCODE::MOVE_OP){
        QString b_from, b_to;
        int x1,y1,x2,y2;
        //int b_x1,b_y1,b_x2,b_y2;
        if(bothmoved){
            QFile file("./record/server/Team_X.txt");
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                // 写入客户端1的坐标
                out << "Client 1 Position: " << b_from << "," << b_to << "-";
                // 写入客户端2的坐标
                out << "Client 2 Position: " << data.data1 << "," << data.data2 << "N";\

                bothmoved = false;
            } else {
                qDebug() << "Failed to open file for writing.";
            }

            file.close();
        }else{
            b_from = data.data1;
            b_to = data.data2;
            bothmoved = true;
        }

        if (client == client1) {
            send_to_another_client(client2, data);
        }
        else{
            send_to_another_client(client1, data);
        }

        x1 = data.data1[0].toLatin1()-'A';
        y1 = data.data1.toInt();
        x2 = data.data2[0].toLatin1()-'A';
        y2 = data.data2.toInt();

        SurakartaPosition from(x1,y1);
        SurakartaPosition to(x2,y2);
        if(client == client1){
            SurakartaMove move(from, to, static_cast<PieceColor>(color1.toInt()));
            SurakartaMoveResponse response=game->Move(move);
            if(response.end_reason_==SurakartaEndReason::NONE){
                return;
            }else{
                QString movereason = QString::number(static_cast< int>(response.move_reason_));
                QString endreason = QString::number(static_cast<int>(response.end_reason_));
                QString winner = QString::number(static_cast<int>(response.winner_));
                this->server->send(client1, NetworkData(OPCODE::END_OP, movereason, endreason , winner));
                this->server->send(client2, NetworkData(OPCODE::END_OP, movereason, endreason , winner));

            }

        }else{
            SurakartaMove move(from, to, static_cast<PieceColor>(color2.toInt()));
            SurakartaMoveResponse response=game->Move(move);
            if(response.end_reason_==SurakartaEndReason::NONE){
                return;
            }else{
                QString movereason = QString::number(static_cast<int>(response.move_reason_));
                QString endreason = QString::number(static_cast<int>(response.end_reason_));
                QString winner = QString::number(static_cast<int>(response.winner_));
                this->server->send(client1, NetworkData(OPCODE::END_OP, movereason, endreason , winner));
                this->server->send(client2, NetworkData(OPCODE::END_OP, movereason, endreason , winner));

            }

        }

    }
}

SurakartaMoveResponse SurakartaGame::Move(const SurakartaMove& move) {
    SurakartaIllegalMoveReason move_reason = rule_manager_->JudgeMove(move);
    auto [end_reason, winner] = rule_manager_->JudgeEnd(move_reason);
    /*UpdateGameInfo(move_reason, end_reason, winner);
    int move_toID=(*board_).getPiecesID(move.to.x,move.to.y);
    int  move_fromID=(*board_).getPiecesID(move.from.x,move.from.y);
    // std::cout<<"move_fromID: "<<move_fromID<<std::endl;
    //    std::cout<<move_reason<<std::endl;
    if (move_reason == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
        board_->piece[move_fromID].SetPosition(move.to);

        board_->isBlackTurn = !board_->isBlackTurn;
        // rule_manager_->OnUpdateBoard();
    } else if (move_reason == SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE) {
        (*board_).piece[move_toID].SetColor(PieceColor::NONE);
        (*board_).piece[move_fromID].SetPosition(move.to);
        board_->isBlackTurn = !board_->isBlackTurn;
        // rule_manager_->OnUpdateBoard();
    }
    // std::cout<<"???move.from: "<< board_->piece[move_fromID].position_<<std::endl;*/
    SurakartaMoveResponse response(move_reason, end_reason, winner);
    return response;
}




void MainWindow::send_to_another_client(QTcpSocket* another, NetworkData data) {
    // 发送消息给一个客户端，这个程序里实际上做的事情是转发消息
    this->server->send(another, data);
}

void MainWindow::restart_server() {
    // 如果你要重启服务器，就像其他 QObject 一样，你需要 disconnect 再 connect 回来一些信号槽
    server->close();
    clients.clear();
    client1 = nullptr;
    client2 = nullptr;
    disconnect(server, &NetworkServer::receive, this, &MainWindow::receive_from_client);
    delete server;
    server = new NetworkServer(this);
    ui->PortButton->setEnabled(true);
    ui->PortEdit->setReadOnly(false);
    ui->PortEdit->setText(QString::number(this->port));
    ui->ShowClient1->setText("");
    ui->ShowClient2->setText("");
    connect(server, &NetworkServer::receive, this, &MainWindow::receive_from_client);
}

MainWindow::~MainWindow() {
    delete ui;
    delete server;
}
