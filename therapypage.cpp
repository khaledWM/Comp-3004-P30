#include "therapypage.h"
#include <QFont>

TherapyPage::TherapyPage(QString name, int freq, QWidget *parent):
    Page(parent)

{
    this->name = name;
    this->powerLevel = 0;
    this->recordingMinutes=0;
    this->recordingSeconds=0;

    timer = new QTimer();


    startStop->setText("start");
    end->setText("end");

    label = new QLabel();           // for name
    label2 = new QLabel();          // for freq
    label3 = new QLabel();          // for power level
    setPowerLabel= new QLabel();

    setPowerLabel->setFont(QFont( "Arial", 8, QFont::Bold));

    therapyTimerDisplay = new QLCDNumber();
    therapyTimerDisplay->setFrameShape(QFrame::NoFrame);
    label->setText(name);
    label2->setNum(freq);
    label3->setNum(powerLevel);

    therapyTimerDisplay->setGeometry(80,50,221,61);



    layout = new QVBoxLayout();

    layout->addWidget(label);
    layout->addWidget(therapyTimerDisplay);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(setPowerLabel);
    layout->addWidget(startStop);
    layout->addWidget(end);
    label->setAlignment(Qt::AlignCenter);
    setLayout(layout);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));

}

TherapyPage::~TherapyPage(){}

void TherapyPage::setName(QString name)
{
    this->name = name;
    label->setText(name);
}

void TherapyPage::setFrequencyAndPower(int value)
{
    freq = value;
    this->prevFreq=value;
    label2->setNum(freq);
    this->powerLevel=0;
    this->label3->setNum(0);
}
void TherapyPage::setMinsAndSecs(int minutes,int seconds){
    this->timerMins=minutes;
    this->timerSecs=seconds;
    this->prevMins=minutes;
    this->prevSeconds=seconds;

    validateTime(minutes,seconds);

}

void TherapyPage::sensorOnSkin(bool placed)
{
    electrodePlaced = placed;

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

    if(powerLevel != 0 && electrodePlaced == true)
    {
        setPowerLabel->setText(nullptr);

        if(counter == 1)
        {
            emit emitTurnOffStart(powerLevel);
        }
        this->therapyStarted= true;

        if(timer->isActive())
        {
            counter += 1;
            timer->stop();
            startStop->setText("Continue Therapy");
            emit emitStopThread();
            return;
        }
        startStop->setText("stop");

        timer->start(1000);
    }
    else
    {
            setPowerLabel->setText("Please adjust power level and place electrode on skin.");
            emitStopThread();
            return;
    }

}

void TherapyPage::stopTimer()
{
    if(therapyStarted)
    {
        if(electrodePlaced == false)
        {
            counter += 1;
            timer->stop();
            startStop->setText("Continue Therapy");
            emit emitStopThread();
            return;
        }

        if(timer->isActive())
        {
            timer->stop();
            startStop->setText("Continue Therapy");
            emit emitStopThread();
            return;
        }
    }
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

    if(this->therapyStarted==true)
    {
        timer->stop();
        startStop->setText("start");
        therapyTimerDisplay->display("00:00");

        QTime time = QTime::currentTime();

        createRecording("Program",this->name,time,this->powerLevel,this->freq,this->recordingSeconds,this->recordingMinutes);

        recordingMinutes=0;
        recordingSeconds=0;

        setFrequencyAndPower(prevFreq);
        setMinsAndSecs(prevMins,prevSeconds);

        this->therapyStarted=false;
        this->powerLevel=0;
        counter = 1;

        label3->setNum(0);

        setPowerLabel->setText("Please adjust power level and place electrode on skin.");

        emit emitTurnOffStart(0);
        emit emitStopThread();
        emit emitSensorOffSkin();

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




