#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

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
    //QDialog也是QWidget的子类，因此相关的各种属性方法也能使用
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("对话框标题");
    //设置对话框尺寸
    dialog->resize(400, 300);
    //通过show方法就可以显示出对话框
    dialog->show();

    //释放对话框，防止内存泄漏
    //不能直接delete，对话框会一闪而过
    //正确做法是把delete和关闭按钮的点击信号关联起来
    //在用户点击关闭的时候，触发delete
    //Qt给QDialog设置了一个属性，可以通过设置属性，完成上述效果
    dialog->setAttribute(Qt::WA_DeleteOnClose);
}
