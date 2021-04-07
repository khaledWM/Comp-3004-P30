#ifndef THERAPYPAGE_H
#define THERAPYPAGE_H

#include <QWidget>
#include "page.h"

class therapypage : public Page
{
    Q_OBJECT
public:
    therapypage(QString name = "pain", QString freq = "77", QString powerLevel = "8", int timerMins=11, int timerSecs=6, QWidget *parent = nullptr);
    ~therapypage();
    int getMins();
    int getSeconds();
private:
    int timerMins;
    int timerSecs;
    QString name;
    QString freq;
    QString powerLevel;
};

#endif // THERAPYPAGE_H
