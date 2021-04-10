#include "therapypage.h"


TherapyPage::TherapyPage(QString name, int freq, QWidget *parent):
    Page(parent)

{
//    this->name = name;
//    this->freq = freq;
    this->powerLevel = 0;
//    this->timerMins = 0;
//    this->timerSecs = 0;

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
    minString = QString::number(minutes);
    secsString = QString::number(seconds);
    validateTime(minString,secsString);

}

void TherapyPage::increasePowerLevel(int power)
{
    label3->setNum(power);
}

void TherapyPage::decreasePowerLevel(int power)
{
    label3->setNum(power);
}

void TherapyPage::showFrequencyOnDisplay(int value)
{
    freq = value;
    label2->setNum(freq);
}

void TherapyPage::startTimer(){
    if(timer->isActive()) {
        timer->stop();
        startStop->setText("start");
        emit emitStopThread();
        return;
    }
    startStop->setText("stop");


    timer->start(1000);
}

void TherapyPage::showTime(){
timerSecs--;

if (timerSecs==-1 && timerMins==0){
    sleep(1);
    endTimer();
}
if(timerSecs == -1){
    timerSecs=59;
    timerMins--;
}

QString qstr = QString::number(timerMins);
QString qstr2 = QString::number(timerSecs);

validateTime(qstr,qstr2);
}



void TherapyPage::endTimer(){
    timer->stop();
    startStop->setText("start");
    therapyTimerDisplay->display("00:00");
    QTime time = QTime::currentTime();
    qDebug() << time.toString("hh : mm");
    createRecording("program",time,this->powerLevel,this->freq,this->timerSecs,this->timerMins);
    setFrequency(prevFreq);
    setMinsAndSecs(prevMins,prevSeconds);
    emit emitStopThread();

}

void TherapyPage::validateTime(QString qstr, QString qstr2){
    if (timerMins<10 && timerSecs<10) {
        therapyTimerDisplay->display("0" + qstr + ":" + "0" + qstr2);
    }else if(timerMins<10) {
        therapyTimerDisplay->display("0" + qstr + ":" + qstr2);
    }else if(timerSecs<10) {
        therapyTimerDisplay->display(qstr + ":" + "0" + qstr2);
    }
}

void TherapyPage::createRecording(QString n, QTime t, int pl, int f, int s, int m){
    Recording *r = new Recording(n,t,pl,f,s,m);
    qDebug() << n;
    emit emitRecording(pl);
}






