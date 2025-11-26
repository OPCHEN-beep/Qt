#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //访问到图片文件
    QPixmap pixmap(":/anno.png");
    pixmap.scaled(10, 10);  //缩放图片
    //构造光标对象
    QCursor cursor(pixmap, 10, 10);
    //把光标设置进去
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

