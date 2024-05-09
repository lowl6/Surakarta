#ifndef NETWINDOW_H
#define NETWINDOW_H
#include "widget.h"
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
    Ui::netwindow *ui;
};

#endif // NETWINDOW_H
