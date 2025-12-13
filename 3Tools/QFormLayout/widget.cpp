#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置成3行2列
    QFormLayout* layout = new QFormLayout();
    this->setLayout(layout);

    //创建3个label作为第一列
    QLabel* label1 = new QLabel("姓名");
    QLabel* label2 = new QLabel("年龄");
    QLabel* label3 = new QLabel("电话");

    //创建3个linedit作为第二列
    QLineEdit* edit1 = new QLineEdit();
    QLineEdit* edit2 = new QLineEdit();
    QLineEdit* edit3 = new QLineEdit();

    //把上述控件添加到表单布局中
    layout->addRow(label1, edit1);
    layout->addRow(label2, edit2);
    layout->addRow(label3, edit3);

    //创建一个提交按钮
    QPushButton* button = new QPushButton("提交");
    layout->addRow(nullptr, button);
}

Widget::~Widget()
{
    delete ui;
}

