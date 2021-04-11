#include "thread.h"


Thread::Thread(Battery *battery)
{
this->battery=battery;
}


void Thread::run(){
    sleep(2);

    if(battery->getBatteryLevel()==0){
        battery->rechargeBattery();
    }else {
        qDebug()<<battery->getBatteryLevel();
        battery->drainBattery();
}

}

void Thread::stopThread(){
    if(this->isRunning()){
    this->terminate();

    }
}
