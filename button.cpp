#include "button.h"
#include <QtWidgets>
#include<QDebug>

Button::Button(const QString &text,int x, int y, QWidget *parent):QPushButton (parent)
{
    move(x,y);
    setText(text);

}


Button::~Button(){

}


void Button::upButtonClicked(){
    qDebug()<<"Up";
}


void Button::downButtonClicked(){

}

void Button::rightButtonClicked(){
    qDebug()<<"right";
}


void Button::leftButtonClicked(){
    qDebug()<<"left";
}


