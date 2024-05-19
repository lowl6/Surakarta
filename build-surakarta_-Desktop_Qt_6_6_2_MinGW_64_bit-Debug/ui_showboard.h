/********************************************************************************
** Form generated from reading UI file 'showboard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWBOARD_H
#define UI_SHOWBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showboard
{
public:

    void setupUi(QWidget *showboard)
    {
        if (showboard->objectName().isEmpty())
            showboard->setObjectName("showboard");
        showboard->resize(400, 300);

        retranslateUi(showboard);

        QMetaObject::connectSlotsByName(showboard);
    } // setupUi

    void retranslateUi(QWidget *showboard)
    {
        showboard->setWindowTitle(QCoreApplication::translate("showboard", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showboard: public Ui_showboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWBOARD_H
