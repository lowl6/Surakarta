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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_netwindow
{
public:
    QLabel *label;
    QLineEdit *ip_edit;
    QPushButton *disconnect_button;
    QLineEdit *receive_edit;
    QPushButton *connect_button;
    QLineEdit *send_edit;
    QLineEdit *port_edit;
    QPushButton *send_button;
    QLabel *label_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *room;
    QLabel *label_4;
    QLineEdit *opponenter_name;
    QLabel *label_5;
    QRadioButton *BlackrBtn;
    QRadioButton *WhiterBtn;
    QPushButton *applyGame;

    void setupUi(QWidget *netwindow)
    {
        if (netwindow->objectName().isEmpty())
            netwindow->setObjectName("netwindow");
        netwindow->resize(912, 641);
        label = new QLabel(netwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 560, 171, 16));
        label->setAlignment(Qt::AlignCenter);
        ip_edit = new QLineEdit(netwindow);
        ip_edit->setObjectName("ip_edit");
        ip_edit->setGeometry(QRect(50, 500, 121, 20));
        ip_edit->setAlignment(Qt::AlignCenter);
        disconnect_button = new QPushButton(netwindow);
        disconnect_button->setObjectName("disconnect_button");
        disconnect_button->setGeometry(QRect(50, 590, 371, 21));
        receive_edit = new QLineEdit(netwindow);
        receive_edit->setObjectName("receive_edit");
        receive_edit->setGeometry(QRect(50, 560, 191, 20));
        connect_button = new QPushButton(netwindow);
        connect_button->setObjectName("connect_button");
        connect_button->setGeometry(QRect(250, 500, 171, 20));
        send_edit = new QLineEdit(netwindow);
        send_edit->setObjectName("send_edit");
        send_edit->setGeometry(QRect(50, 530, 191, 20));
        port_edit = new QLineEdit(netwindow);
        port_edit->setObjectName("port_edit");
        port_edit->setGeometry(QRect(180, 500, 61, 20));
        port_edit->setAlignment(Qt::AlignCenter);
        send_button = new QPushButton(netwindow);
        send_button->setObjectName("send_button");
        send_button->setGeometry(QRect(250, 530, 171, 21));
        label_2 = new QLabel(netwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 470, 191, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_2->setFont(font);
        groupBox = new QGroupBox(netwindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(540, 50, 301, 301));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 30, 216, 246));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        room = new QLineEdit(layoutWidget);
        room->setObjectName("room");

        verticalLayout->addWidget(room);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        opponenter_name = new QLineEdit(layoutWidget);
        opponenter_name->setObjectName("opponenter_name");
        opponenter_name->setReadOnly(true);

        verticalLayout->addWidget(opponenter_name);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);
        label_5->setScaledContents(true);

        verticalLayout->addWidget(label_5);

        BlackrBtn = new QRadioButton(layoutWidget);
        BlackrBtn->setObjectName("BlackrBtn");

        verticalLayout->addWidget(BlackrBtn);

        WhiterBtn = new QRadioButton(layoutWidget);
        WhiterBtn->setObjectName("WhiterBtn");

        verticalLayout->addWidget(WhiterBtn);

        applyGame = new QPushButton(layoutWidget);
        applyGame->setObjectName("applyGame");

        verticalLayout->addWidget(applyGame);


        retranslateUi(netwindow);

        QMetaObject::connectSlotsByName(netwindow);
    } // setupUi

    void retranslateUi(QWidget *netwindow)
    {
        netwindow->setWindowTitle(QCoreApplication::translate("netwindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("netwindow", "\346\216\245\346\224\266", nullptr));
        disconnect_button->setText(QCoreApplication::translate("netwindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        connect_button->setText(QCoreApplication::translate("netwindow", "\350\277\236\346\216\245", nullptr));
        send_button->setText(QCoreApplication::translate("netwindow", "\345\217\221\351\200\201\350\201\212\345\244\251", nullptr));
        label_2->setText(QCoreApplication::translate("netwindow", "\347\275\221\347\273\234\350\256\276\347\275\256\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("netwindow", "\345\257\271\345\261\200\344\277\241\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("netwindow", "\346\210\277\351\227\264\345\217\267  ([0,255]\345\206\205\347\232\204\346\225\264\346\225\260)\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("netwindow", "\346\202\250\347\232\204\345\257\271\346\211\213\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("netwindow", "\346\202\250\351\200\211\346\213\251\357\274\232", nullptr));
        BlackrBtn->setText(QCoreApplication::translate("netwindow", "\346\211\247\351\273\221\345\205\210\350\241\214", nullptr));
        WhiterBtn->setText(QCoreApplication::translate("netwindow", "\346\211\247\347\231\275\345\220\216\350\241\214", nullptr));
        applyGame->setText(QCoreApplication::translate("netwindow", "\347\224\263\350\257\267\345\257\271\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class netwindow: public Ui_netwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWINDOW_H
