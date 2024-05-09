#ifndef MAINBEGIN_H
#define MAINBEGIN_H
 #include "widget.h"
#include <QDialog>
 #include "netwindow.h"

namespace Ui {
class mainbegin;
}

class mainbegin : public QDialog
{
    Q_OBJECT

public:
    explicit mainbegin(QWidget *parent = nullptr);
    ~mainbegin();

private slots:
    void on_online_clicked();
    void on_single_clicked();

private:
    Ui::mainbegin *ui;
};

#endif // MAINBEGIN_H
