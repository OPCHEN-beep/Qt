#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置随机种子
    srand(time(0));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("女神女神，快来嘴一个~");
}


void Widget::on_pushButton_reject_clicked()
{

}

void Widget::on_pushButton_reject_pressed()
{
    //获取当前程序窗口的尺寸
    int width = this->geometry().width();
    int height = this->geometry().height();

    //重新生成按钮的位置
    int x = rand() % width;
    int y = rand() % height;

    //移动按钮的位置
    ui->pushButton_reject->move(x, y);
}
