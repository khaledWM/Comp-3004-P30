#ifndef THERAPYPAGE_H
#define THERAPYPAGE_H

#include <QWidget>
#include <string>
#include <QLayout>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>
#include "page.h"
#include "frequencypage.h"
#include "frequency.h"
#include "recording.h"
#include <unistd.h>
#include <cstdlib>

class TherapyPage : public Page
{
    Q_OBJECT

public:

    TherapyPage(QString = "NULL", int = 0, QWidget *parent = nullptr);

    ~TherapyPage();

    QPushButton* getStartStop();
    QPushButton* getEnd();
    QString getName();
//    int getMins();
//    int getSeconds();
//    int getFrequency();
//    int getPowerLevel();
//    void setPowerLevel(int);
    //bool getTherapyStarted();
    void setName(QString);
    void setFrequencyAndPower(int);
    void setMinsAndSecs(int,int);

private:
    QString minString ;
    QString secsString;
    QString name;
    QLCDNumber *therapyTimerDisplay;
    QTimer *timer;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *frequencyLabel;
    QLabel *powerLabel;
    QLabel *setPowerLabel;
    QLayout *layout;

    bool therapyStarted=false;
    bool electrodePlaced=false;
    int timerMins;
    int timerSecs;
    int recordingMinutes;
    int recordingSeconds;
    int freq;
    int powerLevel;
    int prevMins;
    int prevSeconds;
    int prevFreq;
    int counter = 1;
    void recordMinutesAndSecond();
    void validateTime(int,int);
    void resetTimer();
    void createRecording(QString,QString, QTime,int,int,int,int);


signals:
    void emitStopThread();
    void emitRecording(Recording *);
    void emitTurnOffStart(int);
    void emitSensorOffSkin();

public slots:
     void endTimer();



private slots:
    void showTime();
    void startTimer();
    void stopTimer();
    void increasePowerLevel(int);
    void decreasePowerLevel(int);
    void showFrequencyOnDisplay(int);
    void sensorOnSkin(bool);
};

#endif // THERAPYPAGE_H
