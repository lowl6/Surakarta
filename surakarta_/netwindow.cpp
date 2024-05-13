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

   socket = new NetworkSocket(new QTcpSocket(this), this);

    connect(socket->base(), &QTcpSocket::connected, this, &netwindow::connected_successfully);
    connect(ui->connect_button, &QPushButton::clicked, this, &netwindow::connectToServer);
    connect(ui->disconnect_button, &QPushButton::clicked, this, &netwindow::disconnectFromServer);
    connect(ui->send_button, &QPushButton::clicked, this, &netwindow::sendMessage);
    connect(socket, &NetworkSocket::receive, this, &netwindow::receiveMessage);
}

void netwindow::connected_successfully() {
    ui->connect_button->setEnabled(false);
    ui->disconnect_button->setEnabled(true);
    ui->send_button->setEnabled(true);
    ui->port_edit->setReadOnly(true);
    ui->ip_edit->setText("Connected");
    ui->ip_edit->setReadOnly(true);
    socket->send(NetworkData(OPCODE::READY_OP, "", "", ""));
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

netwindow::~netwindow()
{
    delete ui;
}
