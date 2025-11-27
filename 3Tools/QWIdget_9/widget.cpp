#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QCursor>  // 需包含QCursor头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 获取界面上的按钮（也可以用new动态创建）
    QPushButton* btn = ui->pushButton;

    // 2. 设置光标为“等待形状”（沙漏）
    // Qt::WaitCursor是系统内置的光标枚举值
    btn->setCursor(QCursor(Qt::WaitCursor));

    // 拓展：如果想设置全局光标（比如加载时）
    // QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    // 注意：全局光标使用后需手动恢复，否则会一直生效
    // QGuiApplication::restoreOverrideCursor();
}

Widget::~Widget()
{
    delete ui;
}

