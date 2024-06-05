#include "mainbegin.h"
#include "ui_mainbegin.h"
#include <QLabel.h>
mainbegin::mainbegin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainbegin)
{

     ui->setupUi(this);

    ui->online->setStyleSheet ("border:0.5px groove gray;border-radius:10px;padding:2px 4px;"     "color:rgb(110,174,248)");
    ui->single->setStyleSheet ("border:0.5px groove gray;border-radius:10px;padding:2px 4px;"   "color:rgb(110,174,248)");


}

mainbegin::~mainbegin()
{
    delete ui;
}


void mainbegin::on_online_clicked()
{
    netwindow *n=new netwindow;
    n->show();
    this->close();

}


void mainbegin::on_single_clicked()
{
    Widget *chessboard=new Widget;
    chessboard->show();
    this->close();
}

