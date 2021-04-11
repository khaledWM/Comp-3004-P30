#include "battery.h"


Battery::Battery(int l,int x, int y, QWidget *parent):QProgressBar (parent)
{
   level = 4;
   move(x,y);
   setMinimum(0);
   setMaximum(100);

   setValue(level);
}


Battery::~Battery(){

}

void Battery::drainBattery() {

    while(this->value() != 0){
        this->setValue(level-1);
        level -= 1;
        sleep(1);
    }
    emit emitPowerOff();
    //sleep(3);

}

void Battery::rechargeBattery(){
    while(this->value() != 101){
        this->setValue(level+1);
        level += 1;
        usleep(10000);
    }
}
\




