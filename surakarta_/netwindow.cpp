#include "netwindow.h"
#include "ui_netwindow.h"

netwindow::netwindow(QWidget *parent)
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

    socket = new NetworkSocket(new QTcpSocket(this), this);

    connect(socket->base(), &QAbstractSocket::disconnected,this, [=]() {
       have_connected=false;
       QMessageBox::critical(this, tr("Connection lost"), tr("Connection to server has closed"));
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
    ui->disconnect_button->setEnabled(false);
    ui->send_button->setEnabled(false);
    ui->port_edit->setReadOnly(false);
    ui->ip_edit->setReadOnly(false);
    ui->ip_edit->setText(ip);
}

void netwindow::sendMessage() {
    QString message = ui->send_edit->text();
    socket->send(NetworkData(OPCODE::CHAT_OP, "", message, ""));
    ui->send_edit->clear();
}

void netwindow::receiveMessage(NetworkData data) {
    ui->receive_edit->setText(data.data2);
}

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
        board->reset();
        update();
    }
}

// 点击“认输”按钮后的功能实现
void netwindow::on_admit_defeat_clicked()
{   if(!have_connected)
    {

        msg.setText("请先连接到服务器 ~_~");
        msg.exec();
        return;
    }
    else
    {
        msg.setText("您认输了，再接再厉!");
        msg.exec();
        this->socket->send(NetworkData(OPCODE::GIVEUP_OP,"","",""));
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
            game->Move(move);
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
    }
}


void netwindow::on_WhiterBtn_clicked(bool checked)
{
    if(checked)
        game->game_info_->player=SurakartaPlayer::WHITE;
    else
        game->game_info_->player=SurakartaPlayer::BLACK;
}




void netwindow::on_applyGame_clicked()
{
    // 将枚举变量转换为整数
    int colorInt = static_cast<int>(game->game_info_->player);
    // 将整数转换为 QString 类型的字符串
    QString colorString = QString::number(colorInt);
    QString roomSting= ui->room->text();
    socket->send(NetworkData(OPCODE::READY_OP, "team5", colorString, roomSting));
    return;
}

