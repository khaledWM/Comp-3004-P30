#include "powerlevel.h"


PowerLevel::PowerLevel(int p, QWidget *parent ): QLCDNumber (parent)
{
    move(700,150);
    power = p;
}

PowerLevel::~PowerLevel(){}

void PowerLevel::increasePower()
{
    display(++power);
}

void PowerLevel::decreasePower()
{
    display(--power);
}

int PowerLevel::getPowerLevel()
{
    return power;
}
