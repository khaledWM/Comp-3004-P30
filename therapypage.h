#ifndef THERAPYPAGE_H
#define THERAPYPAGE_H

#include <QWidget>
#include "page.h"

class TherapyPage : public Page
{
    Q_OBJECT

public:

    TherapyPage(QString name = "pain", QString freq = "77", QString powerLevel = "8", int timerMins=11, int timerSecs=6, QWidget *parent = nullptr);

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
    QString freq;
    QString powerLevel;
};

#endif // THERAPYPAGE_H
