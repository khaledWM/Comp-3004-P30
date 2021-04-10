#ifndef POWERLEVEL_H
#define POWERLEVEL_H
#include<QLCDNumber>
#include<QDebug>
#include<QLabel>
#include <QLayout>
#include<QDebug>



class PowerLevel : public QLCDNumber{

    Q_OBJECT

public:
    PowerLevel( QWidget *parent = nullptr);
    ~PowerLevel();
    int getPowerLevel();
signals:
  void  emitPowerLevel(int);
private slots:
    void increasePower();
    void decreasePower();
    void checkallowButtonBool(bool);
    void adjustPowerLevelDuringTherapy(int);

private:
    int power;
    int maxPower;
    int minPower;
    bool checkOnPowerTherapyPage;

};

#endif // POWERLEVEL_H
