#ifndef BATTERY_H
#define BATTERY_H
#include<QProgressBar>

class Battery: public QProgressBar {
    Q_OBJECT

private slots:
    void batteryStatus();

public:
    Battery(int level,int x, int y,QWidget *parent =nullptr);
    ~Battery();
};

#endif // BATTERY_H
