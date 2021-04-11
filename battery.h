#ifndef BATTERY_H
#define BATTERY_H
#include<QProgressBar>
#include <QtWidgets>
#include<QDebug>
#include <unistd.h>
#include <cstdlib>
#include<QThread>

class Battery: public QProgressBar {
    Q_OBJECT
private:
    int level;


public slots:
    void rechargeBattery();

public:
    Battery(int l,int x, int y,QWidget *parent =nullptr);
    void drainBattery();
    ~Battery();


signals:
    void emitPowerOff();
};

#endif // BATTERY_H
