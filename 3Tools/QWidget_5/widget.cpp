#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //直接针对widget对象使用geometry和frameGeometry，观察区别
//    QRect rect1 = this->geometry();
//    QRect rect2 = this->frameGeometry();
//    qDebug() << rect1;
//    qDebug() << rect2;

    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(100, 100);

    connect(button, &QPushButton::clicked, this, &Widget::handle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    QRect rect1 = this->geometry();
    QRect rect2 = this->frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;
}

