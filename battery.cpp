#include "battery.h"


Battery::Battery(int l,int x, int y, QWidget *parent):QProgressBar (parent)
{
   level = l;
   move(x,y);
   setMinimum(0);
   setMaximum(100);

   setValue(level);
}


Battery::~Battery(){

}

void Battery::drainBattery() {

    while(this->value() != 1){
        this->setValue(level-1);
        level -= 1;
        qDebug() << level;
        sleep(1);
    }
}



