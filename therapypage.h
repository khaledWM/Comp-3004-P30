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

class TherapyPage : public Page
{
    Q_OBJECT

public:

    TherapyPage(QString name, int freq, int powerLevel, int timerMins, int timerSecs, QWidget *parent = nullptr);

    ~TherapyPage();
    int getMins();
    int getSeconds();
    QString getName();
    int getFrequency();
    int getPowerLevel();
    QPushButton* getStartStop();
    QPushButton* getEnd();


private:
    int timerMins;
    int timerSecs;
    QString name;
    int freq;
    int powerLevel;
    QLCDNumber *therapyTimerDisplay;
    QTimer *timer;


private slots:
    void showTime();
    void startTimer();
    void endTimer();
};

#endif // THERAPYPAGE_H
