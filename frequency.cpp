#include "frequency.h"

Frequency::Frequency(QWidget *parent) :
    QSlider (parent)
{
    setGeometry(800,100,200,30);
    setOrientation(Qt::Horizontal);
    setRange(60,200);
//    setValue(60);s


}
Frequency::~Frequency()
{}

int Frequency::getValue()
{
    return value;
}


void Frequency::setFrequencyValue(int freq){
    setValue(freq);
   setDisabled(true);
}

void Frequency::enableFrequencyChange (){
    setValue(0);
    setDisabled(false);
}






