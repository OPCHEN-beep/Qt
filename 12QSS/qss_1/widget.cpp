#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //setStyleSheet会针对子控件生效
    //ui->pushButton->setStyleSheet("QPushButton {color : red;}");
    this->setStyleSheet("QPushButton {color : red;}");
}

Widget::~Widget()
{
    delete ui;
}

