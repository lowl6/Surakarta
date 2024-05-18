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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *showAllgoalbtn;
    QPushButton *admit_defeat;
    QPushButton *restart;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(877, 569);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(570, 380, 171, 145));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        showAllgoalbtn = new QRadioButton(groupBox);
        showAllgoalbtn->setObjectName("showAllgoalbtn");

        verticalLayout->addWidget(showAllgoalbtn);

        admit_defeat = new QPushButton(groupBox);
        admit_defeat->setObjectName("admit_defeat");
        QFont font;
        font.setBold(true);
        admit_defeat->setFont(font);

        verticalLayout->addWidget(admit_defeat);

        restart = new QPushButton(groupBox);
        restart->setObjectName("restart");
        restart->setFont(font);
        restart->setAutoDefault(true);

        verticalLayout->addWidget(restart);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        showAllgoalbtn->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\346\211\200\346\234\211\345\217\257\350\265\260\344\275\215\347\275\256", nullptr));
        admit_defeat->setText(QCoreApplication::translate("Widget", "\350\256\244\350\276\223", nullptr));
        restart->setText(QCoreApplication::translate("Widget", "\345\206\215\346\235\245\344\270\200\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
