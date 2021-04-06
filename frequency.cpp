#include <iostream>
#include "frequency.h"

Frequency::Frequency(QWidget *parent) :
    QSlider (parent)
{
    setGeometry(450,60,231,31);
    setOrientation(Qt::Horizontal);
    setRange(60,200);
}

Frequency::~Frequency()
{}

//void Frequency::sliderMoved(int position)

