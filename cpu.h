/* CPU Class
 *
 * inherits the QT class QObject
 *
 * The main component of the program which
 * connects all of the slots and signals from
 * every class to another.
*/
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


};

#endif // CPU_H
