#include "therapypage.h"

#include <QLayout>
#include <QLabel>
#include <QTimer>
#include <QTime>

TherapyPage::TherapyPage(QString name, QString freq, QString powerLevel, int timerMins, int timerSecs,QWidget *parent): Page(parent)

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
    label2->setText(freq);
    label3->setText(powerLevel);
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

