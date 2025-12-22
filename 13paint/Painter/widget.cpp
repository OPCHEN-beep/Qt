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
    //绘图工作放到这里来执行
    (void) event;

    //定义在栈上，不用考虑释放的问题
    QPainter painter(this);

//    QFont font("微软雅黑", 24);
//    painter.setFont(font);

    QPen pen;
    //设置成红色的线条
    pen.setColor(QColor(255, 0, 0));
    //设置线条的粗细
    pen.setWidth(5);
    //设置线条的风格
    pen.setStyle(Qt::DashLine);

    //让painter对象应用pen对象
    painter.setPen(pen);

    //设置画刷
    QBrush brush;
    brush.setColor(QColor(0, 255, 0));
    //brush.setStyle(Qt::SolidPattern);
    brush.setStyle(Qt::CrossPattern);
    painter.setBrush(brush);

    //画一个线段
//    painter.drawLine(20, 20, 200, 20);
//    painter.drawLine(QPoint(20, 100), QPoint(200, 100));

    //    painter.drawLine(20, 20, 20, 300);
    //    painter.drawLine(20, 20, 100, 300);

    //画一个矩形
//    painter.drawRect(100, 100, 300, 200);

    //画圆形
    painter.drawEllipse(200, 200, 400, 100);

    //画文字
    //0：横坐标，表示文字最左侧的位置
    //100：纵坐标，表示文字的“基线位置”(四线格中的第三根线)
//    painter.drawText(0, 100, "hello");
}

