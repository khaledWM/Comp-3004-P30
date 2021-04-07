#ifndef THERAPYPAGE_H
#define THERAPYPAGE_H

#include <QWidget>
#include "page.h"

class therapypage : public Page
{
public:
    therapypage(QWidget *parent,QString name, int freq, int powerLevel, int timerMins, int timerSecs);
    ~therapypage();
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
