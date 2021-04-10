#include "powerlevel.h"


PowerLevel::PowerLevel( QWidget *parent ): QLCDNumber (parent)
{
    move(700,150);
    power = 0;
    checkOnPowerTherapyPage=false;
}

PowerLevel::~PowerLevel(){}

void PowerLevel::increasePower()
{
    if(checkOnPowerTherapyPage == true){
    if(power<100){
    display(++power);
    emit emitPowerLevel(power);
    }
    }
}

void PowerLevel::decreasePower()
{
    if(checkOnPowerTherapyPage==true){
    if(power>0){

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
