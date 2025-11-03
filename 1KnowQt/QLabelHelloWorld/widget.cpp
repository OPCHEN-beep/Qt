#include "widget.h"
#include "ui_widget.h"
#include <QLabel>   // 包含标签控件头文件
#include <QFont>    // 包含字体设置头文件
#include <QColor>   // 包含颜色设置头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 创建QLabel对象，父对象为当前窗口
    QLabel *helloLabel = new QLabel(this);

    // 2. 设置标签显示的文本
    helloLabel->setText("中华人民共和国万岁");

    // 3. 设置窗口固定大小
    this->setFixedSize(1000, 600);

    // 4. 设置标签文本的字体（字体名称、字号、字体样式）
    QFont labelFont("华文行楷", 64, QFont::Bold); // 华文行楷字体，64号，加粗
    helloLabel->setFont(labelFont);

    // 5. 设置标签文本的颜色（蓝色）
    // 使用样式表（CSS-like）设置颜色，Qt控件均支持样式表
    helloLabel->setStyleSheet("color: blue;");

    // 6. 设置标签的位置（水平居中，垂直居中）
    // 计算标签位置：窗口宽度/2 - 标签宽度/2，窗口高度/2 - 标签高度/2
    int labelX = (this->width() - helloLabel->width()) / 2;
    int labelY = (this->height() - helloLabel->height()) / 2;
    helloLabel->move(labelX, labelY);

    // 7. 设置窗口标题
    this->setWindowTitle("Qt Hello World（标签版）");
}

Widget::~Widget()
{
    delete ui;
}

