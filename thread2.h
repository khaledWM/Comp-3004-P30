#ifndef THREAD2_H
#define THREAD2_H


#include<QtCore>
#include<QDebug>
#include<QString>
#include<QProgressBar>
#include<battery.h>
class Thread2: public QThread
{
    Q_OBJECT
public:

    Thread2(Battery *battery);
    void run();
    void stop();
    Battery *battery;

private slots:
    void stopThread();
};

#endif // THREAD2_H
