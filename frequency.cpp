#include <iostream>
#include "frequency.h"

Frequency::Frequency(QWidget *parent) :
    QSlider (parent)
{
    setGeometry(800,100,200,30);
    setOrientation(Qt::Horizontal);
    setRange(60,200);

//    frequencyLabel = new QLabel;

//    frequencyLabel->setText("Frequency");
//    frequencyLabel->setGeometry(650,100,50,20);

//    QLayout *layout = new QHBoxLayout ();

//    layout->addWidget(frequencyLabel);
//    layout->addWidget(this);
//    setLayout(layout);

}

int Frequency::getValue()
{
    return value;
}

Frequency::~Frequency()
{}

//void Frequency::sliderMoved(int position)

