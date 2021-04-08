#include "frequencypage.h"

FrequencyPage::FrequencyPage(QWidget *parent) :
    Page(parent)
{
    promptLabel = new QLabel();
    promptLabel->setText("Move slider on side to set frequency");

    frequencyValue = new QLabel();

    layout = new QVBoxLayout();
    layout->addWidget(promptLabel);

    setLayout(layout);
}

FrequencyPage::~FrequencyPage(){}

void FrequencyPage::showValueOnDisplay(int value)
{
    promptLabel->setText("Frequency selected: ");
    frequencyValue->setNum(value);
    layout->addWidget(frequencyValue);
}

QString FrequencyPage::getValue()
{
    return frequencyValue->text();
}
