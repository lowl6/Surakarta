#include "netwindow.h"
#include "ui_netwindow.h"

netwindow::netwindow(QWidget *parent)
    : Widget(parent)
    , ui(new Ui::netwindow)
{
    ui->setupUi(this);
}

netwindow::~netwindow()
{
    delete ui;
}
