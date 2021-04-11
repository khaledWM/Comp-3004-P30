#include "button.h"

Button::Button(const QString &text,int x, int y, QWidget *parent):QPushButton (parent)
{
    move(x,y);
    setText(text);

}


Button::~Button(){

}




