#ifndef FREQUENCYTHERAPYPAGE_H
#define FREQUENCYTHERAPYPAGE_H

#include <QObject>
#include <QWidget>
#include<QLCDNumber>
#include<QTimer>
#include<QTime>
#include "page.h"

class FrequencyTherapyPage : public Page
{
    Q_OBJECT
public:
    FrequencyTherapyPage(QString = "NULL", int = 0, QWidget *parent = nullptr);
    ~FrequencyTherapyPage();


    QPushButton* getStartStop();
    QPushButton* getEnd();
    QString getName();
    int getMins();
    int getSeconds();
    int getFrequency();
    int getPowerLevel();
    void setName(QString);
    void setFrequency(int);

public slots:
     void endTimer();

private:
    int timerMins;
    int timerSecs;
    int freq;
    int powerLevel;
    QString name;
    QLCDNumber *therapyTimerDisplay;
    QTimer *timer;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    void validateTime(QString, QString);

private slots:
    void showTime();
    void startTimer();
    void increasePowerLevel();
    void decreasePowerLevel();
    void showFrequencyOnDisplay(int);

};

#endif // FREQUENCYTHERAPYPAGE_H
