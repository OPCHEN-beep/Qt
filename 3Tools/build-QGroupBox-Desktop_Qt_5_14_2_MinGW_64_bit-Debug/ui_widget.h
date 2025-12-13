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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_2;
    QSpinBox *spinBox_2;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_3;
    QSpinBox *spinBox_3;
    QGroupBox *groupBox_4;
    QComboBox *comboBox_4;
    QSpinBox *spinBox_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(110, 20, 491, 121));
        groupBox->setFlat(false);
        groupBox->setCheckable(true);
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 50, 231, 41));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(340, 50, 91, 41));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(110, 170, 491, 121));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(30, 50, 231, 41));
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(340, 50, 91, 41));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 491, 121));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(30, 50, 231, 41));
        spinBox_3 = new QSpinBox(groupBox_3);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(340, 50, 91, 41));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(110, 320, 491, 121));
        comboBox_4 = new QComboBox(groupBox_4);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(30, 50, 231, 41));
        spinBox_4 = new QSpinBox(groupBox_4);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(340, 50, 91, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\261\211\345\240\241", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "\351\272\246\350\276\243\351\270\241\350\205\277\345\240\241", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "\345\237\271\346\240\271\350\224\254\350\220\203\351\270\241\350\205\277\345\240\241", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "\345\267\250\346\227\240\351\234\270", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\345\260\217\351\243\237", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Widget", "\344\270\255\350\226\257\346\235\241", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Widget", "\351\272\246\350\276\243\351\270\241\347\277\205", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Widget", "\351\272\246\350\276\243\351\270\241\345\235\227", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\345\260\217\351\243\237", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Widget", "\344\270\255\350\226\257\346\235\241", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Widget", "\351\272\246\350\276\243\351\270\241\347\277\205", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Widget", "\351\272\246\350\276\243\351\270\241\345\235\227", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("Widget", "\351\245\256\346\226\231", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("Widget", "\345\217\257\344\271\220", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Widget", "\351\233\252\347\242\247", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("Widget", "\345\222\226\345\225\241", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
