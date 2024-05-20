#include "mainbegin.h"
#include "ui_mainbegin.h"
#include <QLabel.h>
mainbegin::mainbegin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainbegin)
{

     ui->setupUi(this);
    // imageLabel = new QLabel(this);
    // // imageLabel->setFixedSize(1196, 670);
    // imageLabel->setAlignment(Qt::AlignCenter); //让图片在QLabel中居中显示
    // // 加载并显示图片的定时器
    // QTimer *timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &mainbegin::updateImage);
    //  timer->start(80);
    ui->online->setStyleSheet ("border:0.5px groove gray;border-radius:10px;padding:2px 4px;"     "color:rgb(110,174,248)");
    ui->single->setStyleSheet ("border:0.5px groove gray;border-radius:10px;padding:2px 4px;"   "color:rgb(110,174,248)");


}
// void mainbegin::updateImage() {
//     // 构建当前图片路径
//     QString imagePath = QString(":/Resources/yuanshen/%1.png").arg(currentIndex + 1);
//     // 加载图片
//     QPixmap pixmap(imagePath);
//     // 显示图片到QLabel
//     imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));
//     // 更新索引
//     currentIndex = (currentIndex + 1) % 29;
// }
mainbegin::~mainbegin()
{
    delete ui;
}


void mainbegin::on_online_clicked()
{
    netwindow *net=new netwindow;
    net->show();
    this->close();

}


void mainbegin::on_single_clicked()
{
    Widget *chessboard=new Widget;
    chessboard->show();
    this->close();
}

