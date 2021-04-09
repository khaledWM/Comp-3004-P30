#include"cpu.h"
#include"display.h"

Cpu::Cpu(QWidget *parent):QObject(parent), thread(m.battery)
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
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getFrequencyPage(),SLOT(showValueOnDisplay(int)));
    connect(m.right,SIGNAL(clicked()),m.power,SLOT(increasePower()));
    connect(m.left,SIGNAL(clicked()),m.power,SLOT(decreasePower()));
    connect(m.right,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(increasePowerLevel()));
    connect(m.left,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(decreasePowerLevel()));
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getTherapyPage(),SLOT(showFrequencyOnDisplay(int)));



    connect(m.display->getTherapyPage()->startStop,SIGNAL(clicked()),&thread,SLOT(start()));
    connect(m.display->getTherapyPage()->startStop,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(startTimer()));
    connect(m.display->getTherapyPage()->end,SIGNAL(clicked()),&thread,SLOT(terminate()));
    connect(m.display->getTherapyPage()->end,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(endTimer()));
    connect(m.display->getFrequencyPage()->getStartFrequency(),SIGNAL(clicked()),m.display,SLOT(startFrequency()));
    connect(m.display->getFrequencyTherapyPage()->startStop,SIGNAL(clicked()),&thread,SLOT(start()));
    connect(m.display->getFrequencyTherapyPage()->startStop,SIGNAL(clicked()),m.display->getFrequencyTherapyPage(),SLOT(startTimer()));
    connect(m.display->getFrequencyTherapyPage()->end,SIGNAL(clicked()),m.display->getFrequencyTherapyPage(),SLOT(endTimer()));
    connect(m.display->getFrequencyTherapyPage()->end,SIGNAL(clicked()),&thread,SLOT(terminate()));
}


