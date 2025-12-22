#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    (void) event;

    QPainter painter(this);

    QPixmap pixmap(":/cat.jpg");

    //基础绘制
//    painter.drawPixmap(100, 100, pixmap);

    //图片缩放
//    painter.drawPixmap(100, 100, 400, 300, pixmap);

    //图片旋转，本质上十八QPainter对象进行了旋转，绘制出来的内容也就产生了旋转了
    painter.rotate(180);    //绕着（0，0）这个坐标系原点进行旋转——>可以把坐标系原点平移到窗口右下角
    painter.translate(-800, -600);
    painter.drawPixmap(100, 100, 400, 300, pixmap);
}

