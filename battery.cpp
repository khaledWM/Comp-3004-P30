#include "battery.h"


Battery::Battery(int l,int x, int y, QWidget *parent):QProgressBar (parent)
{
      level=l;
      move(x,y);
      setMinimum(0);
      setMaximum(100);
      this->setValue(l);
      p=this->palette();
      p.setColor(QPalette::Highlight, Qt::darkGreen);
      this->setPalette(p);


}


Battery::~Battery(){

}
int Battery::getBatteryLevel(){
    return level;
}


void Battery::drainBattery() {
    while(this->value() != 0){
        this->setValue(level-1);
        level-=1;

        if(level== 20){
        p.setColor(QPalette::Highlight, Qt::red);
        this->setPalette(p);
        }
        sleep(1);
    }

    emit emitPowerOff();
}


void Battery::rechargeBattery(){

    while(this->value() != 101){
           this->setValue(level+1);
           level += 1;

           if(level== 20){
           p.setColor(QPalette::Highlight, Qt::darkGreen);
           this->setPalette(p);
           }
           usleep(10000);
       }

}

void Battery:: setBatteryLevel(int num){
    level= num;
}



