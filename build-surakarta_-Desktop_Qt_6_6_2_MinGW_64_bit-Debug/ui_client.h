/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *ip_edit;
    QLineEdit *port_edit;
    QPushButton *connect_button;
    QLineEdit *send_edit;
    QPushButton *send_button;
    QLineEdit *receive_edit;
    QLabel *label;
    QPushButton *disconnect_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(346, 205);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ip_edit = new QLineEdit(centralwidget);
        ip_edit->setObjectName("ip_edit");
        ip_edit->setGeometry(QRect(30, 30, 111, 20));
        ip_edit->setAlignment(Qt::AlignCenter);
        port_edit = new QLineEdit(centralwidget);
        port_edit->setObjectName("port_edit");
        port_edit->setGeometry(QRect(160, 30, 51, 20));
        port_edit->setAlignment(Qt::AlignCenter);
        connect_button = new QPushButton(centralwidget);
        connect_button->setObjectName("connect_button");
        connect_button->setGeometry(QRect(230, 30, 80, 20));
        send_edit = new QLineEdit(centralwidget);
        send_edit->setObjectName("send_edit");
        send_edit->setGeometry(QRect(30, 60, 181, 20));
        send_button = new QPushButton(centralwidget);
        send_button->setObjectName("send_button");
        send_button->setGeometry(QRect(230, 60, 81, 21));
        receive_edit = new QLineEdit(centralwidget);
        receive_edit->setObjectName("receive_edit");
        receive_edit->setGeometry(QRect(30, 90, 181, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 90, 81, 16));
        label->setAlignment(Qt::AlignCenter);
        disconnect_button = new QPushButton(centralwidget);
        disconnect_button->setObjectName("disconnect_button");
        disconnect_button->setGeometry(QRect(30, 120, 281, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 346, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        connect_button->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        send_button->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Receive", nullptr));
        disconnect_button->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
