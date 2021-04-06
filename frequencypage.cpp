#include "frequencypage.h"

frequencypage::frequencypage(QWidget *parent) :
    Page(parent)
{
    promptLabel = new QLabel();
    promptLabel->setText("Move slider on side to set frequency");

    QLayout *layout = new QVBoxLayout();
    layout->addWidget(promptLabel);

    setLayout(layout);
}

frequencypage::~frequencypage(){}
