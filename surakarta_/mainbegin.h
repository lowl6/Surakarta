#ifndef MAINBEGIN_H
#define MAINBEGIN_H
#include <QDialog>
#include <QImage>
#include <QString>
#include "netwindow.h"
//开始界面
namespace Ui {
class mainbegin;
}

class mainbegin : public QDialog
{
    Q_OBJECT

public:
    explicit mainbegin(QWidget *parent = nullptr);
    ~mainbegin();
   // QImage imgopena[29];//开场动画
// private:
//     QLabel *imageLabel;
//     QTimer *timer;
//     int currentIndex;
private slots:
    void on_online_clicked();
    void on_single_clicked();
   // void updateImage();
private:
    Ui::mainbegin *ui;
};

#endif // MAINBEGIN_H
