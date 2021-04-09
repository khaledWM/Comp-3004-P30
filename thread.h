#ifndef THREAD_H
#define THREAD_H
#include<QtCore>
#include<QDebug>
#include<QString>
#include<QProgressBar>
#include<battery.h>
class Thread: public QThread
{
    Q_OBJECT
public:

    Thread(Battery *battery);
    void run();
    void stop();
    Battery *battery;
};

#endif // THREAD_H
