#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //给主窗口添加一个子窗口
    QDockWidget* dockWidget = new QDockWidget();
    //使用addDockWidget方法，把浮动窗口加入到子窗口中
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

