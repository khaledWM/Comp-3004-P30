#ifndef FREQUENCYTHERAPYPAGE_H
#define FREQUENCYTHERAPYPAGE_H

#include <QObject>
#include <QWidget>
#include<QLCDNumber>
#include<QTimer>
#include<QTime>
#include "page.h"
#include"recording.h"

class FrequencyTherapyPage : public Page
{
    Q_OBJECT
public:
    FrequencyTherapyPage(QString = "NULL", int = 0, QWidget *parent = nullptr);
    ~FrequencyTherapyPage();


    QPushButton* getStartStop();
    QPushButton* getEnd();
    QString getName();
    void setName(QString);
    void setFrequency(int);
    //    int getMins();
    //    int getSeconds();
    //    int getFrequency();
    //    int getPowerLevel();

signals:
    void emitStopThread();
    void emitRecording(Recording*);
    void emitTurnOffStart(int);

public slots:
     void endTimer();

private:
    QString minString ;
    QString secsString;
    QString name;
    QLCDNumber *frequenctTherapyTimerDisplay;
    QTimer *timer;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *setPowerLabel;
    QLayout *layout;
    Recording * r;
    int timerMins;
    int timerSecs;
    int freq;
    int powerLevel;
    bool frequencyTherapyStarted=false;
    void validateTime(int, int);
    void createRecording(QString ,QString, QTime , int , int , int, int );

private slots:
    void showTime();
    void startTimer();
    void increasePowerLevel(int);
    void decreasePowerLevel(int);
    void showFrequencyOnDisplay(int);

};

#endif // FREQUENCYTHERAPYPAGE_H
