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
    qDebug()<<this->freq;
    qDebug()<<freq;

    startStop->setText("start");
    end->setText("end");

    label = new QLabel();
    label2 = new QLabel();
    label3 = new QLabel();
    setPowerLabel= new QLabel();
    QString qstr = QString::number(timerMins);
    QString qstr2 = QString::number(timerSecs);

    frequenctTherapyTimerDisplay = new QLCDNumber();
    frequenctTherapyTimerDisplay->display("0" + qstr + ":" + "0" + qstr2);

    label->setText(name);
    label2->setNum(freq);
    label3->setNum(0);
    frequenctTherapyTimerDisplay->setGeometry(80,50,221,61);



    layout = new QVBoxLayout();

    layout->addWidget(frequenctTherapyTimerDisplay);
    layout->addWidget(label);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(setPowerLabel);
    layout->addWidget(startStop);
    layout->addWidget(end);

    setLayout(layout);


    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));

}

FrequencyTherapyPage::~FrequencyTherapyPage(){}


void FrequencyTherapyPage::setName(QString name)
{
    this->name = name;
    label->setText(name);
}

void FrequencyTherapyPage::setFrequencyAndPower(int value)
{
    freq = value;
    label2->setNum(freq);
    this->powerLevel=0;
    this->label3->setNum(0);
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

void FrequencyTherapyPage::sensorOnSkin(bool placed)
{
    electrodePlaced = placed;

}

void FrequencyTherapyPage::startTimer(){
    if(powerLevel != 0 && electrodePlaced == true)
    {
        setPowerLabel->setText(nullptr);
        if(counter == 1)
        {
            emit emitTurnOffStart(powerLevel);
        }
        this->frequencyTherapyStarted= true;
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

void FrequencyTherapyPage::stopTimer()
{
    if(frequencyTherapyStarted)
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

void FrequencyTherapyPage::updateTime(){
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
    frequenctTherapyTimerDisplay->display("00:00");
    QTime time = QTime::currentTime();
    createRecording("Frequency",this->name,time,this->powerLevel,this->freq,this->timerSecs,this->timerMins);
    timerMins = 0;
    timerSecs=0;
    this->frequencyTherapyStarted=false;
    this->powerLevel=0;
    counter = 1;
    label3->setNum(0);
    setPowerLabel->setText("This therapy cannot start without adjusting power level");
    this->frequencyTherapyStarted=false;
    emit emitTurnOffStart(0);
    emit emitStopThread();
    emit emitSensorOffSkin();
    }
}

void FrequencyTherapyPage::validateTime(int mins, int secs){
    minString = QString::number(mins);
    secsString = QString::number(secs);

    if (timerMins<10 && timerSecs<10) {
        frequenctTherapyTimerDisplay->display("0" + minString + ":" + "0" + secsString);
    }else if(timerMins<10) {
        frequenctTherapyTimerDisplay->display("0" + minString + ":" + secsString);
    }else if(timerSecs<10) {
        frequenctTherapyTimerDisplay->display(minString + ":" + "0" + secsString);
    }
}



void FrequencyTherapyPage::createRecording(QString type,QString name ,QTime t, int pl, int f, int s, int m){
    Recording *r = new Recording(type,name,t,pl,f,s,m);

    emit emitRecording(r);
}

