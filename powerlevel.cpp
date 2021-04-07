#include "powerlevel.h"
#include<QDebug>
#include<QLabel>
#include <QLayout>

PowerLevel::PowerLevel(QWidget *parent ): QLCDNumber (parent)
{
    move(700,150);
}

PowerLevel::~PowerLevel(){}

