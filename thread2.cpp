#include "thread2.h"

Thread2::Thread2(Battery* battery)
{
this->battery=battery;
}


void Thread2::run(){
    //sleep(2);

battery->rechargeBattery();
}

void Thread2::stopThread(){
    if(this->isRunning()){
    this->terminate();

    }
}
