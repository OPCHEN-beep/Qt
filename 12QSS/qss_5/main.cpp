
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QString style = "QPushButton { color : red;}";
//    style += "#pushButton_2 {color : green;}";
//    style += "#pushButton_3 {color : blue;}";

    //并集选择器
    QString style = "QPushButton, QLineEdit, QLabel {color : red;}";

    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
