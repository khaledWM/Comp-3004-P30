#include "recording.h"

Recording::Recording(QString n,QTime t, int pl,int f,int s,int m)
{
    this->name = n;
    this->date = t;
    this->powerLevel = pl;
    this->freq = f;
    this->seconds = s;
    this->minutes = m;
}

QString Recording::getName(){
    return this->name;
}

QTime Recording::getDate(){
    return this->date;
}

int Recording::getPowerLevel(){
    return this->powerLevel;
}

int Recording::getFreq(){
    return this->freq;
}

int Recording::getSeconds(){
    return this->seconds;
}

int Recording::getMinutes(){
    return this->minutes;
}
