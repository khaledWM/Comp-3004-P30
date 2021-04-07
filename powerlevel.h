#ifndef POWERLEVEL_H
#define POWERLEVEL_H
#include<QLCDNumber>

class PowerLevel : public QLCDNumber{

    Q_OBJECT

public:
    PowerLevel(QWidget *parent);
    ~PowerLevel();

};

#endif // POWERLEVEL_H
