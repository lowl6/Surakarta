#ifndef NETWINDOW_H
#define NETWINDOW_H
#include "widget.h"
#include "NetworkLibrary/networkdata.h"
#include "NetworkLibrary/networksocket.h"
#include <QWidget>
#include <QString>

namespace Ui {
class netwindow;
}

class netwindow : public Widget
{
    Q_OBJECT

public:
    explicit netwindow(QWidget *parent = nullptr);
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
    void move_op(NetworkData data);
    void ready_op(NetworkData data);
    void reject_op(NetworkData data);
    void end_op(NetworkData data);
private slots:
    void connected_successfully();
    void connectToServer();
    void disconnectFromServer();
    void sendMessage();
    void receiveMessage(NetworkData);
    void on_BlackrBtn_clicked(bool checked);
    void on_WhiterBtn_clicked(bool checked);
    void on_applyGame_clicked();
};

#endif // NETWINDOW_H
