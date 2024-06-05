#include "netwindow.h"
#include "ui_netwindow.h"
netwindow::netwindow(Widget *parent)
    : Widget(parent)
    , ui(new Ui::netwindow)
{

    ui->setupUi(this);
    ui->ip_edit->setText(ip);
    ui->port_edit->setText(QString::number(port));
    ui->send_button->setEnabled(false);
    ui->disconnect_button->setEnabled(false);
    ui->receive_edit->setReadOnly(true);
    ui->BlackrBtn->setChecked(true);
    ui->groupBox->hide();
    ui->ALL_AI->setChecked(true);
    socket = new NetworkSocket(new QTcpSocket(this), this);

    connect(socket->base(), &QAbstractSocket::disconnected,this, [=]() {
        have_connected=false;
        QMessageBox::critical(this, tr("Connection lost"), tr("Connection to server has closed"));
        disconnectFromServer();
        ui->groupBox->hide();
    });

    connect(socket->base(), &QTcpSocket::connected, this, &netwindow::connected_successfully);
    connect(ui->connect_button, &QPushButton::clicked, this, &netwindow::connectToServer);
    connect(ui->disconnect_button, &QPushButton::clicked, this, &netwindow::disconnectFromServer);
    connect(ui->send_button, &QPushButton::clicked, this, &netwindow::sendMessage);
    connect(socket, &NetworkSocket::receive, this, &netwindow::receiveMessage);
}

netwindow::~netwindow()
{
    delete ui;
}
void netwindow::on_AI_clicked()
{

    if(!AIcan)
    {
        return;
    }
    if(!have_connected)
    {
        QMessageBox msg;
        msg.setText("请先连接到服务器 ？_？");
        msg.exec();
        return;
    }
    SurakartaMove move=game->myAI->CalculateMove();
    game->Move(move);
    QString s_from=board->pos2Qsting(move.from);
    QString s_to=board->pos2Qsting(move.to);
    socket->send(NetworkData(OPCODE::MOVE_OP, s_from,s_to, ""));
    ui->receive_edit->clear();
    AIcan=false;
    board->selectId = -1;
    update();
    return;
}
void netwindow::connected_successfully() {
    have_connected=true;
    ui->connect_button->setEnabled(false);
    ui->disconnect_button->setEnabled(true);
    ui->send_button->setEnabled(true);
    ui->port_edit->setReadOnly(true);
    ui->ip_edit->setText("Connected");
    ui->ip_edit->setReadOnly(true);
    msg.setText("已连接！请申请对局>_<");
    msg.exec();
    ui->groupBox->show();

}

void netwindow::connectToServer() {
    this->ip = ui->ip_edit->text();
    this->port = ui->port_edit->text().toInt();
    socket->hello(ip, port);
    this->socket->base()->waitForConnected(2000);
}

void netwindow::disconnectFromServer() {
    socket->send(NetworkData(OPCODE::LEAVE_OP, "", "", ""));
    socket->bye();
    have_connected=false;
    ui->connect_button->setEnabled(true);
    ui->disconnect_button->setEnabled(true);
    ui->connect_button->setEnabled(true);
    ui->disconnect_button->setEnabled(false);
    ui->send_button->setEnabled(false);
    ui->port_edit->setReadOnly(false);
    ui->ip_edit->setReadOnly(false);
    ui->BlackrBtn->setEnabled(true);
    ui->WhiterBtn->setEnabled(true);
    ui->ip_edit->setText(ip);
}

void netwindow::sendMessage() {
    QString message = ui->send_edit->text();
    socket->send(NetworkData(OPCODE::CHAT_OP, "", message, ""));
    ui->send_edit->clear();
}
//接收各种信息后的处理
void netwindow::receiveMessage(NetworkData data) {
    ui->receive_edit->setText(data.data2);
    switch (data.op) {
    case OPCODE::MOVE_OP:
        move_op(data);
        break;
    case OPCODE::READY_OP:
        ready_op(data);
        break;
    case OPCODE::REJECT_OP:
        reject_op(data);
        break;
    case OPCODE::END_OP:
        end_op(data);
        break;
    case OPCODE::CHAT_OP:

        chat_op(data);
    default:
        break;
    }
}
//各种op的实现
void netwindow::move_op(NetworkData data)
{
    AIcan=true;

    SurakartaPosition from=board->Qsting2pos(data.data1);
    SurakartaPosition to=board->Qsting2pos(data.data2);
    SurakartaMove move(from, to, game->game_info_->current_player_);
    game->Move(move);
    ui->receive_edit->clear();
    update();
    if(ui->ALL_AI->isChecked())
    {
        on_AI_clicked();
    }
    QFile file(".\\record\\client\\Team_5.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << data.data1 << "-" << data.data2 << " " ;
        file.close();
    }
}

void netwindow::ready_op(NetworkData data)
{
    ui->opponenter_name->setText(data.data1);
    ui->room->setText(data.data3);
    ui->BlackrBtn->setEnabled(false);
    ui->WhiterBtn->setEnabled(false);
    if(data.data2=="BLACK")
    {
        emit ui->BlackrBtn->clicked(true);
        msg.information(this, tr("开始了！"), tr("你执黑先行！"));
    }
    else
     {
         emit ui->WhiterBtn->clicked(true);
         //msg.information(this, tr("开始了！"), tr("你执白后行！"));
     }
    if(ui->ALL_AI->isChecked()&&AIcan)
    {
        on_AI_clicked();
        return;
    }
}
void netwindow::reject_op(NetworkData data)
{
    msg.information(this,tr("对局申请失败"),tr("申请失败原因：").arg(data.data2));
}
void netwindow::end_op(NetworkData data)
{
    msg.information(this,tr("对局结束"),tr("game end").arg(data.data2));
    board->reset();
    ui->BlackrBtn->setEnabled(true);
    ui->WhiterBtn->setEnabled(true);
    update();
    QFile file(".\\record\\client\\Team_5.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << data.data1 << "-" << data.data2 << " " ;
        if(data.data2 == "1") out<<"S#";
        else if(data.data2 == "2") out<<"C#";
        else if(data.data2 == "4") out <<"R#";
        else if(data.data2 == "5") out << "T#";
        else if(data.data2 == "6") out << "I#";
        file.close();
    }
}
void netwindow::chat_op(NetworkData data)
{
    ui->receive_edit->clear();
    ui->receive_edit->setText(data.data1);
}

//再来一局
void netwindow::on_restart_clicked()
{
    if(!have_connected)
    {
        QMessageBox msg;
        msg.setText("请先连接到服务器 -_-*");
        msg.exec();
        return;
    }
    else
    {
        msg.setText("就当您认输了，重开，请重新申请对局");
        msg.exec();
        this->socket->send(NetworkData(OPCODE::RESIGN_OP,"","",""));
        board->reset();
        update();
    }
}

// 点击“认输”按钮后的功能实现
void netwindow::on_admit_defeat_clicked()
{   if(!have_connected)
    {

        msg.setText("你向谁认输啊,请先连接到服务器 ~_~");
        msg.exec();
        return;
    }
    else
    {
        msg.setText("您认输了，再接再厉!(ง •̀_•́)ง");
        msg.exec();
        this->socket->send(NetworkData(OPCODE::RESIGN_OP,"","",""));
        board->reset();
        update();
    }
}

void netwindow::mouseReleaseEvent(QMouseEvent *ev)
{
    /*判断是否为鼠标左键*/
    if (ev->button() != Qt::LeftButton)
    {
        return;
    }
    /*判断点击的位置是否合法（是否在棋盘坐标的棋子范围内），同时计算出对应的棋盘行列坐标*/

    int row, col;
    if (!getRowCol(ev->pos(), row, col))
    {
        return;
    }
    else if(!have_connected)
    {
        msg.setText("请先连接到服务器 :D");
        msg.exec();
        return;
    }
    else if(game->game_info_->current_player_!=game->game_info_->player)
    {
        msg.setText("请等待对手落子 ╮( •́ω•̀ )╭");
        msg.exec();
        return;
    }
    /*获取当前坐标上的棋子*/
    int id = board->getPiecesID(row, col);
    if (board->selectId == -1)
    {
        /*选择棋子*/
        toSelectPieces(id);
    }
    else
    {
        if (board->piece[board->getPiecesID(row, col)].color_ == board->piece[board->selectId].color_)
        {
            id = board->getPiecesID(row, col);
            toSelectPieces(id);
        }
        else
        {

            SurakartaPosition from(board->piece[board->selectId].position_.x, board->piece[board->selectId].position_.y);
            SurakartaPosition to(row, col);
            SurakartaMove move(from, to, game->game_info_->current_player_);
            SurakartaMoveResponse response= game->Move(move);
            if(!response.IsLegal())
                return;
            else
            {
                QString s_from=board->pos2Qsting(from);
                QString s_to=board->pos2Qsting(to);
                socket->send(NetworkData(OPCODE::MOVE_OP, s_from,s_to, ""));
                AIcan=true;
            }
            ui->send_edit->clear();
            board->selectId = -1;
            update();
        }
    }
}


void netwindow::on_BlackrBtn_clicked(bool checked)
{

    if(checked)
    {
        game->game_info_->player=SurakartaPlayer::BLACK;
           AIcan=true;
    }
    else
       game->game_info_->player=SurakartaPlayer::WHITE;
}


void netwindow::on_WhiterBtn_clicked(bool checked)
{

    if(checked)
    {game->game_info_->player=SurakartaPlayer::WHITE;
        AIcan=false;
    }
    else
        game->game_info_->player=SurakartaPlayer::BLACK;
}

void netwindow::on_applyGame_clicked()
{
    // 将枚举变量转换为整数
    QString colorString;
    if(game->game_info_->player==PieceColor::BLACK)
        colorString="0";
    else
        colorString="1";
    // 将整数转换为 QString 类型的字符串
    QString roomSting= ui->room->text();
    socket->send(NetworkData(OPCODE::READY_OP, "team_5", colorString, roomSting));
    return;
}

