#include "therapypage.h"


TherapyPage::TherapyPage(QString name, int freq, QWidget *parent):
    Page(parent)

{

    this->powerLevel = 0;
    this->recordingMinutes=0;
    this->recordingSeconds=0;

    timer = new QTimer();


    startStop->setText("start");
    end->setText("end");

    label = new QLabel();
    label2 = new QLabel();
    label3 = new QLabel();


    therapyTimerDisplay = new QLCDNumber();


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

//int TherapyPage::getMins(){
//    return timerMins;
//}

//int TherapyPage::getSeconds(){
//    return timerSecs;
//}

//QString TherapyPage::getName()
//{
//    return name;
//}

//int TherapyPage::getFrequency()
//{
//    return freq;
//}

//int TherapyPage::getPowerLevel()
//{
//    return powerLevel;
//}

//bool TherapyPage::getTherapyStarted(){
//    return therapyStarted;
//}

void TherapyPage::setName(QString name)
{
    this->name = name;
    label->setText(name);
}

void TherapyPage::setFrequency(int value)
{
    freq = value;
    this->prevFreq=value;
    label2->setNum(freq);
}
void TherapyPage::setMinsAndSecs(int minutes,int seconds){
    this->timerMins=minutes;
    this->timerSecs=seconds;
    this->prevMins=minutes;
    this->prevSeconds=seconds;

    validateTime(minutes,seconds);

}

void TherapyPage::increasePowerLevel(int power)
{
    this->powerLevel=power;
    label3->setNum(power);
}

void TherapyPage::decreasePowerLevel(int power)
{   this->powerLevel=power;
    label3->setNum(power);
}

void TherapyPage::showFrequencyOnDisplay(int value)
{
    freq = value;
    label2->setNum(freq);
}

void TherapyPage::startTimer(){
    this->therapyStarted= true;

    if(timer->isActive()) {
        timer->stop();
        startStop->setText("start");
        emit emitStopThread();
        return;
    }
    startStop->setText("stop");

    timer->start(1000);
}

void TherapyPage::recordMinutesAndSecond(){
    recordingSeconds++;
    if(recordingSeconds==60){
        recordingSeconds=0;
        recordingMinutes++;
    }
}

void TherapyPage::showTime(){
    recordMinutesAndSecond();
    timerSecs--;

    if (timerSecs==-1 && timerMins==0){
        sleep(1);
        endTimer();
     }
    if(timerSecs == -1){
         timerSecs=59;
         timerMins--;
}

validateTime(timerMins,timerSecs);
}


void TherapyPage::endTimer(){

    if(this->therapyStarted==true){
    timer->stop();
    startStop->setText("start");
    therapyTimerDisplay->display("00:00");
    QTime time = QTime::currentTime();
    createRecording("Program",this->name,time,this->powerLevel,this->freq,this->recordingSeconds,this->recordingMinutes);
    recordingMinutes=0;
    recordingSeconds=0;
    setFrequency(prevFreq);
    setMinsAndSecs(prevMins,prevSeconds);
    this->therapyStarted=false;
    emit emitStopThread();
}

}

void TherapyPage::validateTime(int min, int secs){
    minString = QString::number(min);
    secsString = QString::number(secs);

    if (timerMins<10 && timerSecs<10) {
        therapyTimerDisplay->display("0" + minString + ":" + "0" + secsString);
    }else if(timerMins<10) {
        therapyTimerDisplay->display("0" + minString + ":" + secsString);
    }else if(timerSecs<10) {
        therapyTimerDisplay->display(minString + ":" + "0" + secsString);
    }
}



void TherapyPage::createRecording(QString type,QString name, QTime t, int pl, int f, int s, int m){
    Recording *r = new Recording(type,name,t,pl,f,s,m);
    emit emitRecording(r);
}




