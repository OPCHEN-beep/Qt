#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>  // 垂直布局管理器

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
//    QPushButton *btn = new QPushButton("关闭窗口", this);  //创建一个按钮

//    resize(800, 600);

//    //关联信号和槽
//    connect(btn, &QPushButton::clicked, this, &QWidget::close);

//    ui->setupUi(this);

    //设置窗口大小与标题
    resize(600, 300);
    setWindowTitle("信号与槽参数传递");

    //创建控件
    inputEdit = new QLineEdit(this);
    inputEdit->setPlaceholderText("请输入文字：");

    showLabel = new QLabel(this);
    showLabel->setText("你输入的内容：");
    showLabel->setStyleSheet("font-size: 16px; color; #333;");

    // 使用布局管理器排版（垂直布局）
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(inputEdit);
    layout->addWidget(showLabel);
    layout->setSpacing(30);  // 控件间距
    layout->setContentsMargins(50, 50, 50, 50);  // 内边距

    //关联信号与槽
    connect(
                inputEdit, &QLineEdit::textChanged, //信号：文本变化，参数为QString
                this, &Widget::showInputText        //槽函数：接收QString参数
            );
}

Widget::~Widget()
{
}

void Widget::showInputText(const QString &text)
{
    showLabel->setText(QString("当前输入：%1").arg(text));
}


void Widget::on_closeBtn_clicked()
{
    this->close();  // 关闭当前窗口
}
