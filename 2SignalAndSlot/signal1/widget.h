#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_closeBtn_clicked();

    //自定义槽函数
    void showInputText(const QString &text);

private:
    Ui::Widget *ui;
    QLineEdit *inputEdit;   //输入框
    QLabel *showLabel;      //显示标签
};
#endif // WIDGET_H
