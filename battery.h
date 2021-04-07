#ifndef BATTERY_H
#define BATTERY_H
#include<QProgressBar>

class Battery: public QProgressBar {
    Q_OBJECT
private:
    int level;
private slots:
    void drainBattery();

public:
    Battery(int l,int x, int y,QWidget *parent =nullptr);
    ~Battery();
};

#endif // BATTERY_H
