#include "mainbegin.h"
#include "ui_mainbegin.h"

mainbegin::mainbegin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainbegin)
{
    ui->setupUi(this);
}

mainbegin::~mainbegin()
{
    delete ui;
}


void mainbegin::on_online_clicked()
{
    netwindow *chessboard=new netwindow;
    chessboard->show();
    this->close();

}


void mainbegin::on_single_clicked()
{
    Widget *chessboard=new Widget;
    chessboard->show();
    this->close();
}

