#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
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
//    QColorDialog* dialog = new QColorDialog(this);
//    dialog->exec();
//    delete dialog;

    QColor color = QColorDialog::getColor(QColor(0, 255, 0), this, "选择颜色");
    qDebug() << color;

    //基于用户选择的颜色，修改窗口背景色
    //QSS
//    QString style = "background-color: rgb(" + QString::number(color.red()) + ", " + QString::number(color.green())
//            + ", " + QString::number(color.blue()) + ");";
//    this->setStyleSheet(style);

    char style[1024] = {0};
    sprintf(style, "background-color: rgb(%d, %d, %d);", color.red(), color.green(), color.blue());
    this->setStyleSheet(style);
}
