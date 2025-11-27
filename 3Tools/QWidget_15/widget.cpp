// widget.cpp
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 编写QSS样式字符串
    QString btnStyle = R"(
        /* 默认状态 */
        QPushButton {
            background-color: #E0E0E0;  /* 浅灰色背景 */
            color: #333333;            /* 深灰色文本 */
            border: none;              /* 取消默认边框 */
            border-radius: 8px;        /* 8px圆角 */
            font-family: "微软雅黑";    /* 字体 */
            font-size: 14px;           /* 字体大小 */
            padding: 8px 16px;         /* 内边距：上下8px，左右16px */
        }

        /* 鼠标悬停状态 */
        QPushButton:hover {
            background-color: #2196F3;  /* 蓝色背景 */
            color: white;               /* 白色文本 */
        }

        /* 鼠标点击状态 */
        QPushButton:pressed {
            background-color: #F44336;  /* 红色背景 */
            padding: 9px 15px 7px 17px; /* 点击时轻微偏移，模拟按压效果 */
        }

        /* 禁用状态（可选） */
        QPushButton:disabled {
            background-color: #F5F5F5;  /* 更浅的灰色 */
            color: #BDBDBD;             /* 灰色文本 */
        }
    )";

    // 2. 给按钮应用QSS
    ui->pushButton_style->setStyleSheet(btnStyle);

    // 拓展：给整个窗口设置背景色
    this->setStyleSheet("background-color: #FAFAFA;");
}

Widget::~Widget()
{
    delete ui;
}


