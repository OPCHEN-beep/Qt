#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置字体大小
    ui->pushButton->setStyleSheet("QPushButton { font-size: 50px; }");

    //全局样式和局部样式冲突时，局部样式优先级是更高的
    ui->pushButton_2->setStyleSheet("QPushButton { color : green; }");
}

Widget::~Widget()
{
    delete ui;
}

