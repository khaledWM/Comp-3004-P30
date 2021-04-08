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

class TherapyPage : public Page
{
    Q_OBJECT

public:

    TherapyPage(QString = "NULL", int = 0, QWidget *parent = nullptr);

    ~TherapyPage();
    int getMins();
    int getSeconds();
    QString getName();
    int getFrequency();
    int getPowerLevel();
    QPushButton* getStartStop();
    QPushButton* getEnd();

    void setName(QString);
    void setPowerLevel(int);
    void setFrequency(int);

private:
    int timerMins;
    int timerSecs;
    QString name;
    int freq;
    int powerLevel;
    QLCDNumber *therapyTimerDisplay;
    QTimer *timer;

    QLabel *label;
    QLabel *label2;
    QLabel *label3;


private slots:
    void showTime();
    void startTimer();
    void endTimer();
};

#endif // THERAPYPAGE_H
