#include "therapypage.h"


TherapyPage::TherapyPage(QString name, int freq, int powerLevel, int timerMins, int timerSecs,QWidget *parent):
    Page(parent)

{
    this->name=name;
    this->freq = freq;
    this->powerLevel = powerLevel;
    this->timerMins = 0;
    this->timerSecs = 55;

    timer = new QTimer();


    startStop->setText("start");
    end->setText("end");

    QLabel *label = new QLabel();
    QLabel *label2 = new QLabel();
    QLabel *label3 = new QLabel();

    QString qstr = QString::number(timerMins);
    QString qstr2 = QString::number(timerSecs);

    therapyTimerDisplay = new QLCDNumber();
    therapyTimerDisplay->display("0" + qstr + ":" + "0" + qstr2);

    label->setText(name);
    label2->setNum(freq);
    label3->setNum(powerLevel);
    therapyTimerDisplay->setGeometry(80,50,221,61);



    QLayout *layout = new QVBoxLayout();

layout->addWidget(therapyTimerDisplay);
    layout->addWidget(label);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(startStop);
    layout->addWidget(end);

    setLayout(layout);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));

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

void TherapyPage::startTimer(){
    if(timer->isActive()) {
        timer->stop();
        startStop->setText("start");
        return;
    }
    startStop->setText("stop");
    qDebug() << "test";

    timer->start(1000);
}

void TherapyPage::showTime(){
timerSecs++;
if(timerSecs == 60){
    timerSecs=0;
    timerMins++;
}
QString qstr = QString::number(timerMins);
QString qstr2 = QString::number(timerSecs);

if (timerMins<10 && timerSecs<10) {
    therapyTimerDisplay->display("0" + qstr + ":" + "0" + qstr2);
}else if(timerMins<10) {
    therapyTimerDisplay->display("0" + qstr + ":" + qstr2);
}else if(timerSecs<10) {
    therapyTimerDisplay->display(qstr + ":" + "0" + qstr2);
}
}



void TherapyPage::endTimer(){
    timer->stop();
    startStop->setText("start");
    therapyTimerDisplay->display("00:00");
    QTime time = QTime::currentTime();
    qDebug() << timerMins;
    qDebug() << timerSecs;
    qDebug() << time.toString("hh : mm");
    timerMins = 0;
    timerSecs = 0;
}





