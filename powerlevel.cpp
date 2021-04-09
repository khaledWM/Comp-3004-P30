#include "powerlevel.h"


PowerLevel::PowerLevel( QWidget *parent ): QLCDNumber (parent)
{
    move(700,150);
    power = 0;
}

PowerLevel::~PowerLevel(){}

void PowerLevel::increasePower()
{
    if(power<100){
    display(++power);
    }
}

void PowerLevel::decreasePower()
{
    if(power>0){

    display(--power);

    }
}

int PowerLevel::getPowerLevel()
{
    return power;
}
