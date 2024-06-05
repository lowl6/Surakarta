#ifndef NETWINDOW_H
#define NETWINDOW_H
#include "widget.h"
#include "NetworkLibrary/networkdata.h"
#include "NetworkLibrary/networksocket.h"
#include <QWidget>
#include <QString>
//联机界面，继承自Widget
namespace Ui {
class netwindow;

}

class netwindow : public Widget
{
    Q_OBJECT

public:
    explicit netwindow(Widget *parent = nullptr);
    void on_restart_clicked() override;
    void on_admit_defeat_clicked() override;
    void mouseReleaseEvent(QMouseEvent*ev) override;
    ~netwindow();

private:
    int port = 10086;
    QString ip = "10.46.84.233";
    NetworkSocket *socket;
    bool have_connected=false;
    Ui::netwindow *ui;
    QMessageBox msg;
    QPushButton *restart;
     bool AIcan;
    //对接收到的各种指令的响应
    void move_op(NetworkData data);
    void ready_op(NetworkData data);
    void reject_op(NetworkData data);
    void end_op(NetworkData data);
    void chat_op(NetworkData data);   


private slots:
    void connected_successfully();//连接成功后
    void connectToServer();//连接
    void disconnectFromServer();//断开连接
    void sendMessage();//发送信息到服务端（聊天信息）
    void receiveMessage(NetworkData);//接收服务端信息
    //选择棋子颜色
    void on_BlackrBtn_clicked(bool checked);
    void on_WhiterBtn_clicked(bool checked) ;
    void on_applyGame_clicked() ;//申请对局
    void on_AI_clicked() override;//手动AI代打
};

#endif // NETWINDOW_H
