/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

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
    QLineEdit *PortEdit;
    QPushButton *PortButton;
    QLineEdit *ShowClient1;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ShowClient2;
    QPushButton *restart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(378, 212);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        PortEdit = new QLineEdit(centralwidget);
        PortEdit->setObjectName("PortEdit");
        PortEdit->setGeometry(QRect(60, 20, 111, 21));
        PortEdit->setAlignment(Qt::AlignCenter);
        PortButton = new QPushButton(centralwidget);
        PortButton->setObjectName("PortButton");
        PortButton->setGeometry(QRect(200, 20, 111, 21));
        ShowClient1 = new QLineEdit(centralwidget);
        ShowClient1->setObjectName("ShowClient1");
        ShowClient1->setGeometry(QRect(60, 60, 111, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 60, 111, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 100, 111, 20));
        label_2->setAlignment(Qt::AlignCenter);
        ShowClient2 = new QLineEdit(centralwidget);
        ShowClient2->setObjectName("ShowClient2");
        ShowClient2->setGeometry(QRect(60, 100, 111, 20));
        restart = new QPushButton(centralwidget);
        restart->setObjectName("restart");
        restart->setGeometry(QRect(60, 140, 251, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 378, 17));
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
        PortEdit->setText(QCoreApplication::translate("MainWindow", "10086", nullptr));
        PortButton->setText(QCoreApplication::translate("MainWindow", "Listen Port", nullptr));
        ShowClient1->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Client 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Client 2", nullptr));
        ShowClient2->setText(QString());
        restart->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
