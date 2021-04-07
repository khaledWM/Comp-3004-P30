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
<<<<<<< HEAD
    label->setText(name);

    QLayout *layout = new QVBoxLayout();
    //layout->addWidget()
=======
    QLayout *layout = new QVBoxLayout();
>>>>>>> 98684a3ce18742b873d37c5587c8f3fdfa9c2f8f
}

therapypage::~therapypage(){}

int therapypage::getMins(){
    return timerMins;
}

int therapypage::getSeconds(){
    return timerSecs;
}
