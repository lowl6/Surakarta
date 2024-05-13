/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *admit_defeat;
    QPushButton *restart;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1136, 835);
        admit_defeat = new QPushButton(Widget);
        admit_defeat->setObjectName("admit_defeat");
        admit_defeat->setGeometry(QRect(700, 460, 121, 31));
        restart = new QPushButton(Widget);
        restart->setObjectName("restart");
        restart->setGeometry(QRect(700, 510, 121, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        admit_defeat->setText(QCoreApplication::translate("Widget", "\350\256\244\350\276\223", nullptr));
        restart->setText(QCoreApplication::translate("Widget", "\345\206\215\346\235\245\344\270\200\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
