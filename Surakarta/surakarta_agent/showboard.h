#ifndef SHOWBOARD_H
#define SHOWBOARD_H

#include <QWidget>

namespace Ui {
class showboard;
}

class showboard : public QWidget
{
    Q_OBJECT

public:
    explicit showboard(QWidget *parent = nullptr);
    ~showboard();

private:
    Ui::showboard *ui;
};

#endif // SHOWBOARD_H
