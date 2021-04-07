#include"cpu.h"
#include"display.h"

Cpu::Cpu(QWidget *parent):QObject(parent)
{



}


Cpu::~Cpu(){


}


void Cpu::startDevice(){

    m.show();

    connect(m.start,SIGNAL(clicked()),m.display,SLOT(changeToMainPage()));
    connect(m.ok,SIGNAL(clicked()),m.display,SLOT(selectChoice()));
    connect(m.up,SIGNAL(clicked()),m.display,SLOT(navigateUpList()));
    connect(m.down,SIGNAL(clicked()),m.display,SLOT(navigateDownList()));
    connect (m.back,SIGNAL(clicked()),m.display,SLOT(backOutOfPage()));
    connect(m.left,SIGNAL(clicked()),m.left,SLOT(leftButtonClicked()));
    connect(m.right,SIGNAL(clicked()),m.right,SLOT(rightButtonClicked()));
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getPage(4),SLOT(showValueOnDisplay(int)));

   // connect(m.start,SIGNAL(clicked()),m.battery,SLOT(drainBattery()));

//    if(m.display->getPage(1))
    connect(m.right,SIGNAL(clicked()),m.power,SLOT(increasePower()));
    connect(m.left,SIGNAL(clicked()),m.power,SLOT(decreasePower()));
}


