#include "thread.h"


Thread::Thread(Battery *battery)
{
this->battery=battery;
}


void Thread::run(){
    sleep(2);

battery->drainBattery();
}

void Thread::stopThread(){
    if(this->isRunning()){
    this->terminate();

    }
}
