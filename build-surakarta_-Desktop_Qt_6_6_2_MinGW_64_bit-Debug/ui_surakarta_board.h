/********************************************************************************
** Form generated from reading UI file 'surakarta_board.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURAKARTA_BOARD_H
#define UI_SURAKARTA_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *begin;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(933, 516);
        begin = new QPushButton(Form);
        begin->setObjectName("begin");
        begin->setGeometry(QRect(290, 240, 241, 91));

        retranslateUi(Form);
        QObject::connect(begin, &QPushButton::clicked, Form, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        begin->setText(QCoreApplication::translate("Form", "666", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURAKARTA_BOARD_H
