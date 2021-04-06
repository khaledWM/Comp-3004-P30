#include "frequencypage.h"

frequencypage::frequencypage(QWidget *parent) :
    Page(parent)
{
    promptLabel = new QLabel();
    promptLabel->setText("Move slider on side to set frequency");

    frequencyValue = new QLabel();

    layout = new QVBoxLayout();
    layout->addWidget(promptLabel);

    setLayout(layout);
}

frequencypage::~frequencypage(){}

void frequencypage::showValueOnDisplay(int value)
{
    promptLabel->setText("Frequency selected: ");
    frequencyValue->setNum(value);
    layout->addWidget(frequencyValue);
}
