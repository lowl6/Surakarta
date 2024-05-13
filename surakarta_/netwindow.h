#ifndef NETWINDOW_H
#define NETWINDOW_H
#include "widget.h"
#include "NetworkLibrary/networkdata.h"
#include "NetworkLibrary/networksocket.h"
#include <QWidget>

namespace Ui {
class netwindow;
}

class netwindow : public Widget
{
    Q_OBJECT

public:
    explicit netwindow(QWidget *parent = nullptr);
    ~netwindow();

private:
    int port = 10086;
    QString ip = "127.0.0.1";
    NetworkSocket *socket;
    Ui::netwindow *ui;
private slots:
    void connected_successfully();
    void connectToServer();
    void disconnectFromServer();
    void sendMessage();
    void receiveMessage(NetworkData);
};

#endif // NETWINDOW_H
