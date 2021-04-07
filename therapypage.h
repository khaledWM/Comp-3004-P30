#ifndef THERAPYPAGE_H
#define THERAPYPAGE_H

#include <QWidget>
#include <string>
#include <QLayout>
#include <QLabel>
#include <QTimer>
#include <QTime>
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

private:
    int timerMins;
    int timerSecs;
    QString name;
    int freq;
    int powerLevel;
};

#endif // THERAPYPAGE_H
