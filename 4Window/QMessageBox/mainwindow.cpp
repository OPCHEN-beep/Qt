#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //创建QMessageBox
    QMessageBox* messageBox = new QMessageBox(this);
    messageBox->setWindowTitle("对话框窗口标题");
    messageBox->setText("这是对话框的文本");
    messageBox->setIcon(QMessageBox::Warning);
    messageBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Save | QMessageBox::Cancel);

//    QPushButton* button = new QPushButton("按钮", messageBox);
//    messageBox->addButton(button, QMessageBox::AcceptRole);

    //connect连接信号槽，针对当前点击的按钮进行一些相关操作


    //弹出模态对话框
    //用户点击按钮，对话框关闭之后，此时就能通过exec返回的值，来指导用户点击的是哪个按钮，从而执行一些对应的逻辑了
    int result = messageBox->exec();
    if(result == QMessageBox::Ok)
    {
        qDebug() << "OK";
    }
    else if(result == QMessageBox::Save)
    {
        qDebug() << "Save";
    }
    else if(result == QMessageBox::Cancel)
    {
        qDebug() << "Cancel";
    }

    delete messageBox;
}
