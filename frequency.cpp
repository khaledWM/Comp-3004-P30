#include <iostream>
#include "frequency.h"

Frequency::Frequency(QWidget *parent) :
    QSlider (parent)
{
    setGeometry(800,100,200,30);
    setOrientation(Qt::Horizontal);
    setRange(60,200);

}
Frequency::~Frequency()
{}

int Frequency::getValue()
{
    return value;
}




