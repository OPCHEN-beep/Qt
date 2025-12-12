#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建三行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    //创建三列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    //给三列设置列名（设置水平方向的表头）
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("年龄"));

    //给表格中添加数据
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("19"));

    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem("18"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insertRow_clicked()
{
    //需要知道当前一共有多少行
    int rowCount = ui->tableWidget->rowCount();
    //在最后一行之后新增新行
    //注意此处的参数是“下标”，表示你新增之后的一行是第几行
    ui->tableWidget->insertRow(rowCount);
}

void Widget::on_pushButton_deleteRow_clicked()
{
    //获取到选中的行号
    int curRow = ui->tableWidget->currentRow();
    //删除这一行
    ui->tableWidget->removeRow(curRow);
}

void Widget::on_pushButton_insertColumn_clicked()
{
    //需要知道当前一共有多少列
    int colCount = ui->tableWidget->columnCount();
    //在对应位置新增新列
    ui->tableWidget->insertColumn(colCount);
    //设置列名（从输入框中获取到）
    const QString& text = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(text));
}

void Widget::on_pushButton_4_clicked()
{
    //获取到选中的列号
    int curCol = ui->tableWidget->currentColumn();
    //删除这一列
    ui->tableWidget->removeColumn(curCol);
}
