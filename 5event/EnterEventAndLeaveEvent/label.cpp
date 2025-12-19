#include "label.h"
#include <QDebug>

Label::Label(QWidget* parent) : QLabel(parent)
{

}

void Label::enterEvent(QEvent *event)
{
    (void) event;   //消除警告
    qDebug() << "enterEvent";
}

void Label::leaveEvent(QEvent *event)
{
    (void) event;   //消除警告
    qDebug() << "leaveEvent";
}
