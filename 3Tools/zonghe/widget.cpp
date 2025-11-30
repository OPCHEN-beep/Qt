#include "widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QFont>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 1. 设置全局字体
    QFont globalFont("微软雅黑", 12);
    this->setFont(globalFont);

    // 2. 创建主布局（垂直布局）
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(60, 40, 60, 40);
    mainLayout->setSpacing(35);

    // 3. 姓名输入行（水平布局：标签+输入框）
    QHBoxLayout *nameLayout = new QHBoxLayout();
    QLabel *nameLabel = new QLabel("姓名：");
    nameLabel->setFont(globalFont);
    QLineEdit *nameEdit = new QLineEdit();
    nameEdit->setFont(globalFont);
    nameEdit->setPlaceholderText("请输入您的姓名");
    nameEdit->setFixedHeight(35);
    nameEdit->setStyleSheet("border: 1px solid #CCCCCC; border-radius: 5px; padding: 0 10px;");

    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);
    nameLayout->setStretchFactor(nameLabel, 1);  // 标签占1份宽度
    nameLayout->setStretchFactor(nameEdit, 3);   // 输入框占3份宽度

    // 4. 性别选择组（垂直布局+分组框）
    QGroupBox *genderGroup = new QGroupBox("性别");
    genderGroup->setFont(globalFont);
    QVBoxLayout *genderLayout = new QVBoxLayout(genderGroup);
    genderLayout->setSpacing(15);
    genderLayout->setContentsMargins(20, 20, 20, 20);

    QRadioButton *maleBtn = new QRadioButton("男");
    QRadioButton *femaleBtn = new QRadioButton("女");
    maleBtn->setFont(globalFont);
    femaleBtn->setFont(globalFont);
    maleBtn->setChecked(true);  // 默认选中男

    genderLayout->addWidget(maleBtn);
    genderLayout->addWidget(femaleBtn);

    // 5. 兴趣爱好组（垂直布局+分组框）
    QGroupBox *hobbyGroup = new QGroupBox("兴趣爱好（可多选）");
    hobbyGroup->setFont(globalFont);
    QVBoxLayout *hobbyLayout = new QVBoxLayout(hobbyGroup);
    hobbyLayout->setSpacing(15);
    hobbyLayout->setContentsMargins(20, 20, 20, 20);

    QCheckBox *readBtn = new QCheckBox("阅读");
    QCheckBox *sportBtn = new QCheckBox("运动");
    QCheckBox *gameBtn = new QCheckBox("游戏");
    QCheckBox *musicBtn = new QCheckBox("听音乐");
    readBtn->setFont(globalFont);
    sportBtn->setFont(globalFont);
    gameBtn->setFont(globalFont);
    musicBtn->setFont(globalFont);

    hobbyLayout->addWidget(readBtn);
    hobbyLayout->addWidget(sportBtn);
    hobbyLayout->addWidget(gameBtn);
    hobbyLayout->addWidget(musicBtn);

    // 6. 提交按钮
    QPushButton *submitBtn = new QPushButton("提交用户信息");
    submitBtn->setFont(globalFont);
    submitBtn->setFixedHeight(40);
    submitBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #2196F3;
            color: white;
            border: none;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: #1976D2;
        }
        QPushButton:disabled {
            background-color: #CCCCCC;
            color: #999999;
        }
    )");

    // 7. 绑定提交按钮事件（验证+提交）
    connect(submitBtn, &QPushButton::clicked, this, [=]() {
        // 1. 验证姓名是否为空
        QString name = nameEdit->text().trimmed();
        if (name.isEmpty()) {
            qDebug() << "❌ 姓名不能为空！";
            return;
        }

        // 2. 获取性别
        QString gender = maleBtn->isChecked() ? "男" : "女";

        // 3. 获取兴趣爱好
        QStringList hobbies;
        if (readBtn->isChecked()) hobbies.append(readBtn->text());
        if (sportBtn->isChecked()) hobbies.append(sportBtn->text());
        if (gameBtn->isChecked()) hobbies.append(gameBtn->text());
        if (musicBtn->isChecked()) hobbies.append(musicBtn->text());
        QString hobbyStr = hobbies.isEmpty() ? "无" : hobbies.join(", ");

        // 4. 打印提交信息
        qDebug() << "\n✅ 用户信息提交成功！";
        qDebug() << "姓名：" << name;
        qDebug() << "性别：" << gender;
        qDebug() << "兴趣爱好：" << hobbyStr;
    });

    // 8. 将所有控件添加到主布局
    mainLayout->addLayout(nameLayout);
    mainLayout->addWidget(genderGroup);
    mainLayout->addWidget(hobbyGroup);
    mainLayout->addWidget(submitBtn);

    // 9. 窗口设置
    this->setFixedSize(500, 500);
    this->setWindowTitle("用户信息填写界面（三大按钮控件综合案例）");
}

Widget::~Widget()
{
}


