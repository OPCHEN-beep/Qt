#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //把第一个label设置成显示纯文本
    ui->label->setTextFormat(Qt::PlainText);
    ui->label->setText("这是一段纯文本");

    //把第二个label设置成显示富文本
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<b>这是一段富文本"); //<b>：让文本加粗

    //把第一个label设置成显示markdown
    ui->label_3->setTextFormat(Qt::MarkdownText);
    ui->label_3->setText("# 这是一段markdown文本");   //#：一级标题
}

Widget::~Widget()
{
    delete ui;
}

