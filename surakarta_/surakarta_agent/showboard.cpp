#include "showboard.h"
#include "ui_showboard.h"

showboard::showboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::showboard)
{
    ui->setupUi(this);
}

showboard::~showboard()
{
    delete ui;
}
