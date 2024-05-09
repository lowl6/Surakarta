/********************************************************************************
** Form generated from reading UI file 'netwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWINDOW_H
#define UI_NETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_netwindow
{
public:

    void setupUi(QWidget *netwindow)
    {
        if (netwindow->objectName().isEmpty())
            netwindow->setObjectName("netwindow");
        netwindow->resize(400, 300);

        retranslateUi(netwindow);

        QMetaObject::connectSlotsByName(netwindow);
    } // setupUi

    void retranslateUi(QWidget *netwindow)
    {
        netwindow->setWindowTitle(QCoreApplication::translate("netwindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class netwindow: public Ui_netwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWINDOW_H
