#ifndef BUTTON_H
#define BUTTON_H
#include <QToolButton>
#include<QPushButton>
#include <QtWidgets>
#include<QDebug>


class Button: public QPushButton{
    Q_OBJECT


private slots:



public:
    Button(const QString &text,int x, int y,QWidget *parent =nullptr);
    ~Button();
};

#endif // BUTTON_H
