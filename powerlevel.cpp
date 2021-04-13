#include "powerlevel.h"


PowerLevel::PowerLevel( QWidget *parent ): QLCDNumber (parent)
{
    move(475,150);
    power = 0;
    checkOnPowerTherapyPage=false;
    this->maxPower=100;
    this->minPower=0;
}

PowerLevel::~PowerLevel(){}

void PowerLevel::increasePower()
{
    if(checkOnPowerTherapyPage == true){
    if(power<maxPower){
    display(++power);
    emit emitPowerLevel(power);
    }
    }
}

void PowerLevel::decreasePower()
{
    if(checkOnPowerTherapyPage==true){
    if(power>minPower){

    display(--power);

    emit emitPowerLevel(power);

    }

    }
}

int PowerLevel::getPowerLevel()
{
    return power;
}


void PowerLevel:: checkallowButtonBool(bool x){
    checkOnPowerTherapyPage=x;
}

void PowerLevel:: adjustPowerLevelDuringTherapy(int powerToBeAdjusted)
{
    if(powerToBeAdjusted!=0){
        this->maxPower=powerToBeAdjusted;
        this->minPower=1;
    }else {
        this->maxPower=100;
        this->minPower=0;
        this->power=0;
        display(0);

}

}
