#include "widget.h"
#include "ui_widget.h"
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置图标
    //QIcon icon("C:\\Users\\ASUS\\Pictures\\anno.png");
    QIcon icon(":/anno.png");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}

