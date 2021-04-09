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
#include <unistd.h>
#include <cstdlib>

class TherapyPage : public Page
{
    Q_OBJECT

public:

    TherapyPage(QString = "NULL", int = 0, QWidget *parent = nullptr);

    ~TherapyPage();
    QString getName();
    QPushButton* getStartStop();
    QPushButton* getEnd();
    int getMins();
    int getSeconds();
    int getFrequency();
    int getPowerLevel();
    void setName(QString);
    void setFrequency(int);
    void setMinsAndSecs(int,int);
        //    void setPowerLevel(int);
private:
    void validateTime(QString,QString);
    void resetTimer();


private:
    QString minString ;
    QString secsString;
    QString name;
    QLCDNumber *therapyTimerDisplay;
    QTimer *timer;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;

    int timerMins;
    int timerSecs;
    int freq;
    int powerLevel;
    int prevMins;
    int prevSeconds;
    int prevFreq;


public slots:
     void endTimer();


private slots:
    void showTime();
    void startTimer();
    void increasePowerLevel();
    void decreasePowerLevel();
    void showFrequencyOnDisplay(int);
};

#endif // THERAPYPAGE_H
