#ifndef CPU_H
#define CPU_H

#include <QObject>
#include <QWidget>
#include"battery.h"
#include"button.h"
#include"display.h"
#include"frequency.h"
#include"frequencypage.h"
#include"historypage.h"
#include"mainmenupage.h"
#include"noimplementation.h"
#include"page.h"
#include"powerlevel.h"
#include"startpage.h"
#include"programspage.h"
#include"startpage.h"
#include"therapypage.h"
#include"mainwindow.h"
#include"thread.h"
#include"thread2.h"
#include"recording.h"
class Cpu:public QObject
{
    Q_OBJECT
public:
    Cpu(QWidget *parent = nullptr);
    ~Cpu();
    void startDevice();



signals:


private:
    MainWindow m;
    Thread thread;
    Thread2 thread2;

};

#endif // CPU_H
