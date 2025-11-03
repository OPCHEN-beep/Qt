#include "widget.h"
#include "ui_widget.h"
// 包含QPushButton控件的头文件（使用按钮控件必须包含）
#include <QPushButton>
// 包含qDebug()日志打印的头文件（可选，用于调试）
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化UI界面（即使不使用可视化设计，也需保留该语句）

    // 1. 创建QPushButton对象，参数1为按钮显示文本，参数2为父对象（当前窗口）
    QPushButton *helloBtn = new QPushButton("Hello Qt", this);

    // 2. 设置按钮的位置（相对于父窗口左上角，x轴向右为正，y轴向下为正）
    // move(x, y)：x表示水平位置，y表示垂直位置
    helloBtn->move(150, 100);

    // 3. 设置按钮的固定大小（宽度，高度）
    // 若不设置，按钮会根据文本自动调整大小
    helloBtn->setFixedSize(120, 40);

    // 4. （可选）设置窗口的固定大小，避免窗口可随意拉伸导致控件位置错乱
    this->setFixedSize(400, 250);

    // 5. （可选）设置窗口标题
    this->setWindowTitle("Qt Hello World");

    // 6. （可选）打印调试日志，验证按钮创建成功
    qDebug() << "Hello Qt按钮创建成功，位置：" << helloBtn->pos()
             << "，大小：" << helloBtn->size();
}

Widget::~Widget()
{
    delete ui;
}

