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
    int drainSpeed;
    void drainingSpeed();

public slots:
    void setBatteryLevel(int);
    void setDrainingSpeed(int);

public:
    Battery(int l,int x, int y,QWidget *parent =nullptr);
    QPalette p;
    void drainBattery();
    void rechargeBattery();
    int getBatteryLevel();
    ~Battery();


signals:
    void emitPowerOff();
    void emitStartDevice();
};

#endif // BATTERY_H
