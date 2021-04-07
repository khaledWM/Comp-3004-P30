#include "battery.h"
#include <QtWidgets>
#include<QDebug>
Battery::Battery(int level,int x, int y, QWidget *parent):QProgressBar (parent)
{
   move(x,y);
   setMinimum(0);
   setMaximum(100);

   setValue(level);
}


Battery::~Battery(){

}

void Battery::batteryStatus() {
    qDebug()<<"test";
    qDebug() << value();
}

