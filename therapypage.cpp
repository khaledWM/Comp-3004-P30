using namespace std;
#include "therapypage.h"

#include <string>
#include <QLayout>
#include <QLabel>
#include <QTimer>
#include <QTime>

TherapyPage::TherapyPage(QString name, int freq, int powerLevel, int timerMins, int timerSecs,QWidget *parent):
    Page(parent)

{
    this->name=name;
    this->freq = freq;
    this->powerLevel = powerLevel;
    this->timerMins = timerMins;
    this->timerSecs = timerSecs;

    QLabel *label = new QLabel();
    QLabel *label2 = new QLabel();
    QLabel *label3 = new QLabel();

    label->setText(name);
    label2->setNum(freq);
    label3->setNum(powerLevel);
   // QTimer *timer = new QTimer(this);
     //connect(timer, &QTimer::timeout, this, QOverload<>::of(&AnalogClock::update));
       //timer->start(1000);

    //QTime time = QTime::currentTime();
    //QString time_text = time.toString(" mm : ss");
    //label2->setText(time_text);

    //ui->timelabel->setText(time_text);

    QLayout *layout = new QVBoxLayout();

//    layout->addWidget();

    layout->addWidget(label);
    //connect(timer,QTimer:timeout);
    layout->addWidget(label2);
    layout->addWidget(label3);
    setLayout(layout);

}

TherapyPage::~TherapyPage(){}

int TherapyPage::getMins(){
    return timerMins;
}

int TherapyPage::getSeconds(){
    return timerSecs;
}

QString TherapyPage::getName()
{
    return name;
}

int TherapyPage::getFrequency()
{
    return freq;
}

int TherapyPage::getPowerLevel()
{
    return powerLevel;
}



