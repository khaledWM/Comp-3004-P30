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

private:
    int power;
    bool checkOnPowerTherapyPage;

};

#endif // POWERLEVEL_H
