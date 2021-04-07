#include "therapypage.h"

#include <QLayout>
#include <QLabel>

therapypage::therapypage(QWidget *parent, QString name, QString freq, QString powerLevel, int timerMins, int timerSecs): Page(parent)
{
    this->name=name;
    this->freq = freq;
    this->powerLevel = powerLevel;
    this->timerMins = timerMins;
    this->timerSecs = timerSecs;

    QLabel *label = new QLabel();

    label->setText(name);

    QLayout *layout = new QVBoxLayout();
    //layout->addWidget()
}

therapypage::~therapypage(){}

int therapypage::getMins(){
    return timerMins;
}

int therapypage::getSeconds(){
    return timerSecs;
}
