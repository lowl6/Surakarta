#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>
#include <QMap>
#include <QMessageBox>
//#include <unordered_map>
#include <QVector>
#include "NetworkLibrary/networkdata.h"
#include "NetworkLibrary/networkserver.h"
#include "surakarta/surakarta_rule_manager.h"
#include "surakarta/surakarta_game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*MainWindow(QVector<NetworkData>& _dataVector1, QVector<NetworkData>& _dataVector2)
        : dataVector1(_dataVector1), dataVector2(_dataVector2) {
        // 其他构造函数的初始化操作
    }*/


    unsigned int board_size_;
    std::shared_ptr<SurakartaGame> game;
    std::shared_ptr<SurakartaBoard> board_;
    std::shared_ptr<SurakartaGameInfo> game_info_;
    std::shared_ptr<SurakartaRuleManager> rule_manager_;
    bool bothmoved = false;
    //std::unordered_map<QPointer<QTcpSocket>, QVector<NetworkData>> ReadyData;
    QMap<QPointer<QTcpSocket>, QVector<NetworkData>> ReadyData;
    QVector<NetworkData> dataVector1;
    QVector<NetworkData> dataVector2;


    QString username1;
    QString username2;
    QString color1;
    QString color2;


private:
    int port = 10086;
    const int max_clients = 2;
    Ui::MainWindow *ui;
    QSet<QTcpSocket*> clients;
    NetworkServer* server = nullptr;
    QTcpSocket* client1 = nullptr;
    QTcpSocket* client2 = nullptr;
    //QMap<QTcpSocket*, NetworkData> readyData;
    void send_to_another_client(QTcpSocket* another, NetworkData data);
    void remove_client(QTcpSocket* client);

private slots:
    void listen_port();
    void restart_server();
    void receive_from_client(QTcpSocket* client, NetworkData data);

};





#endif // MAINWINDOW_H
