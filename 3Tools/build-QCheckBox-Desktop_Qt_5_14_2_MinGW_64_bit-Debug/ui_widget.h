/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCheckBox *checkBox_study;
    QLabel *label;
    QCheckBox *checkBox_game;
    QCheckBox *checkBox_work;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        checkBox_study = new QCheckBox(Widget);
        checkBox_study->setObjectName(QString::fromUtf8("checkBox_study"));
        checkBox_study->setGeometry(QRect(250, 260, 101, 31));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 190, 251, 41));
        checkBox_game = new QCheckBox(Widget);
        checkBox_game->setObjectName(QString::fromUtf8("checkBox_game"));
        checkBox_game->setGeometry(QRect(250, 300, 101, 31));
        checkBox_work = new QCheckBox(Widget);
        checkBox_work->setObjectName(QString::fromUtf8("checkBox_work"));
        checkBox_work->setGeometry(QRect(250, 340, 101, 31));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 390, 80, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        checkBox_study->setText(QCoreApplication::translate("Widget", "\345\255\246\344\271\240", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\273\212\345\244\251\344\275\240\347\232\204\345\256\211\346\216\222\346\230\257\357\274\232", nullptr));
        checkBox_game->setText(QCoreApplication::translate("Widget", "\346\211\223\346\270\270\346\210\217", nullptr));
        checkBox_work->setText(QCoreApplication::translate("Widget", "\346\211\223\345\267\245", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
