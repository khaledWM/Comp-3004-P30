#ifndef POWERLEVEL_H
#define POWERLEVEL_H
#include<QLCDNumber>
#include<QDebug>
#include<QLabel>
#include <QLayout>


class PowerLevel : public QLCDNumber{

    Q_OBJECT

public:
    PowerLevel(int, QWidget *parent = nullptr);
    ~PowerLevel();

private slots:
    void increasePower();
    void decreasePower();

private:
    int power;

};

#endif // POWERLEVEL_H
