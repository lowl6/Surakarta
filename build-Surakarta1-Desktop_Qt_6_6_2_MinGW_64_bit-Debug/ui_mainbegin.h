/********************************************************************************
** Form generated from reading UI file 'mainbegin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINBEGIN_H
#define UI_MAINBEGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mainbegin
{
public:
    QPushButton *single;
    QPushButton *online;

    void setupUi(QDialog *mainbegin)
    {
        if (mainbegin->objectName().isEmpty())
            mainbegin->setObjectName("mainbegin");
        mainbegin->resize(1387, 830);
        single = new QPushButton(mainbegin);
        single->setObjectName("single");
        single->setGeometry(QRect(460, 250, 351, 111));
        QFont font;
        font.setFamilies({QString::fromUtf8("Playbill")});
        font.setPointSize(19);
        font.setBold(false);
        single->setFont(font);
        single->setIconSize(QSize(20, 20));
        online = new QPushButton(mainbegin);
        online->setObjectName("online");
        online->setGeometry(QRect(460, 430, 351, 111));
        online->setFont(font);
        online->setIconSize(QSize(20, 20));

        retranslateUi(mainbegin);

        QMetaObject::connectSlotsByName(mainbegin);
    } // setupUi

    void retranslateUi(QDialog *mainbegin)
    {
        mainbegin->setWindowTitle(QCoreApplication::translate("mainbegin", "Dialog", nullptr));
        single->setText(QCoreApplication::translate("mainbegin", "\345\215\225\344\272\272\346\270\270\346\210\217", nullptr));
        online->setText(QCoreApplication::translate("mainbegin", "\350\201\224\346\234\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainbegin: public Ui_mainbegin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINBEGIN_H
