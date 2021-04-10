#include "frequencytherapypage.h"

FrequencyTherapyPage::FrequencyTherapyPage(QString name, int freq, QWidget *parent):
    Page(parent)
{
    this->name = name;
    this->freq = freq;
    this->powerLevel = 0;
    this->timerMins = 0;
    this->timerSecs = 0;

    timer = new QTimer();


    startStop->setText("start");
    end->setText("end");

    label = new QLabel();
    label2 = new QLabel();
    label3 = new QLabel();

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

FrequencyTherapyPage::~FrequencyTherapyPage(){}

//int FrequencyTherapyPage::getMins(){
//    return timerMins;
//}

//int FrequencyTherapyPage::getSeconds(){
//    return timerSecs;
//}

//QString FrequencyTherapyPage::getName()
//{
//    return name;
//}

//int FrequencyTherapyPage::getFrequency()
//{
//    return freq;
//}

//int FrequencyTherapyPage::getPowerLevel()
//{
//    return powerLevel;
//}


void FrequencyTherapyPage::setName(QString name)
{
    this->name = name;
    label->setText(name);
}

void FrequencyTherapyPage::setFrequency(int value)
{
    freq = value;
    label2->setNum(freq);
}

void FrequencyTherapyPage::increasePowerLevel(int power)
{
    this->powerLevel=power;
    label3->setNum(power);
}

void FrequencyTherapyPage::decreasePowerLevel(int power)
{
    this->powerLevel=power;
    label3->setNum(power);
}

void FrequencyTherapyPage::showFrequencyOnDisplay(int value)
{
    freq = value;
    label2->setNum(freq);
}

void FrequencyTherapyPage::startTimer(){
    this->frequencyTherapyStarted=true;
    if(timer->isActive()) {
        timer->stop();
        startStop->setText("start");
        emit emitStopThread();
        return;
    }
    startStop->setText("stop");
    timer->start(1000);
}

void FrequencyTherapyPage::showTime(){
timerSecs++;
if(timerSecs == 60){
    timerSecs=0;
    timerMins++;
}


validateTime(timerMins,timerSecs);
}

void FrequencyTherapyPage::endTimer(){
    if(this->frequencyTherapyStarted==true){
    timer->stop();
    startStop->setText("start");
    therapyTimerDisplay->display("00:00");
    QTime time = QTime::currentTime();
    createRecording("Frequency",this->name,time,this->powerLevel,this->freq,this->timerSecs,this->timerMins);
    timerMins = 0;
    timerSecs=0;
    this->frequencyTherapyStarted=false;
    emit emitStopThread();
    }
}

void FrequencyTherapyPage::validateTime(int mins, int secs){
    minString = QString::number(mins);
    secsString = QString::number(secs);

    if (timerMins<10 && timerSecs<10) {
        therapyTimerDisplay->display("0" + minString + ":" + "0" + secsString);
    }else if(timerMins<10) {
        therapyTimerDisplay->display("0" + minString + ":" + secsString);
    }else if(timerSecs<10) {
        therapyTimerDisplay->display(minString + ":" + "0" + secsString);
    }
}



void FrequencyTherapyPage::createRecording(QString type,QString name ,QTime t, int pl, int f, int s, int m){
    Recording *r = new Recording(type,name,t,pl,f,s,m);

    emit emitRecording(r);
}

