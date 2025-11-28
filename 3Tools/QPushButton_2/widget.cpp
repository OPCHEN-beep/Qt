#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置这些按钮的图标
    ui->pushButton_target->setIcon(QIcon(":/anno.png"));
    ui->pushButton_target->setIconSize(QSize(160, 160));

    ui->pushButton_up->setIcon(QIcon(":/UP.png"));
    ui->pushButton_up->setIconSize(QSize(50, 50));

    ui->pushButton_down->setIcon(QIcon(":/Down.png"));
    ui->pushButton_down->setIconSize(QSize(50, 50));

    ui->pushButton_right->setIcon(QIcon(":/Right.png"));
    ui->pushButton_right->setIconSize(QSize(50, 50));

    ui->pushButton_left->setIcon(QIcon(":/Left.png"));
    ui->pushButton_left->setIconSize(QSize(50, 50));

    //直接通过按键名字来设置
//    ui->pushButton_up->setShortcut(QKeySequence("w"));
//    ui->pushButton_down->setShortcut(QKeySequence("s"));
//    ui->pushButton_right->setShortcut(QKeySequence("d"));
//    ui->pushButton_left->setShortcut(QKeySequence("a"));

    //通过按键的枚举来设置
    ui->pushButton_up->setShortcut(QKeySequence(Qt::Key_W));
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));

    //开启鼠标点击连发功能
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_up_clicked()
{
    //获取到target的位置
    QRect rect = ui->pushButton_target->geometry();
    //基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x(), rect.y() - 5, rect.width(), rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    //获取到target的位置
    QRect rect = ui->pushButton_target->geometry();
    //基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x(), rect.y() + 5, rect.width(), rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    //获取到target的位置
    QRect rect = ui->pushButton_target->geometry();
    //基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());
}
void Widget::on_pushButton_right_clicked()
{
    //获取到target的位置
    QRect rect = ui->pushButton_target->geometry();
    //基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());
}
