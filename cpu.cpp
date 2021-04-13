#include"cpu.h"


Cpu::Cpu(QWidget *parent):QObject(parent), thread(m.battery)
{



}


void Cpu::startDevice(){




    m.show();

    connect(m.start,SIGNAL(clicked()),m.display,SLOT(changeToMainPage()));
    connect(m.ok,SIGNAL(clicked()),m.display,SLOT(selectChoice()));
    connect(m.up,SIGNAL(clicked()),m.display,SLOT(navigateUpList()));
    connect(m.down,SIGNAL(clicked()),m.display,SLOT(navigateDownList()));
    connect (m.back,SIGNAL(clicked()),m.display,SLOT(backOutOfPage()));
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getFrequencyPage(),SLOT(showValueOnDisplay(int)));
    connect(m.right,SIGNAL(clicked()),m.power,SLOT(increasePower()));
    connect(m.left,SIGNAL(clicked()),m.power,SLOT(decreasePower()));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getTherapyPage(),SLOT(increasePowerLevel(int)));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getTherapyPage(),SLOT(decreasePowerLevel(int)));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getFrequencyTherapyPage(),SLOT(increasePowerLevel(int)));
    connect(m.power,SIGNAL(emitPowerLevel(int)),m.display->getFrequencyTherapyPage(),SLOT(decreasePowerLevel(int)));
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getTherapyPage(),SLOT(showFrequencyOnDisplay(int)));
    connect(m.fs,SIGNAL(valueChanged(int)),m.display->getFrequencyTherapyPage(),SLOT(showFrequencyOnDisplay(int)));
    connect(m.display->getTherapyPage()->startStop,SIGNAL(clicked()),&thread,SLOT(start()));
    connect(m.display->getTherapyPage()->startStop,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(startTimer()));
//    connect(m.display->getTherapyPage()->startStop,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(stopTimer()));
    connect(m.display->getTherapyPage()->end,SIGNAL(clicked()),m.display->getTherapyPage(),SLOT(endTimer()));
    connect(m.display->getFrequencyPage()->getStartFrequency(),SIGNAL(clicked()),m.display,SLOT(startFrequency()));
    connect(m.display->getFrequencyTherapyPage()->startStop,SIGNAL(clicked()),&thread,SLOT(start()));
    connect(m.display->getFrequencyTherapyPage()->startStop,SIGNAL(clicked()),m.display->getFrequencyTherapyPage(),SLOT(startTimer()));
    connect(m.display->getFrequencyTherapyPage()->end,SIGNAL(clicked()),m.display->getFrequencyTherapyPage(),SLOT(endTimer()));
    connect(m.display->getFrequencyTherapyPage()->end,SIGNAL(clicked()),&thread,SLOT(stopThread()));
    connect(m.display,SIGNAL(allowButton(bool)),m.power,SLOT(checkallowButtonBool(bool)));
    connect(m.display,SIGNAL(emitFrequency(int)),m.fs,SLOT(setFrequencyValue(int)));
    connect(m.display,SIGNAL(resetFrequency()),m.fs,SLOT(enableFrequencyChange()));
    connect(m.display->getTherapyPage(),SIGNAL(emitStopThread()),&thread,SLOT(stopThread()));
    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitStopThread()),&thread,SLOT(stopThread()));
    connect(m.display->getTherapyPage(),SIGNAL(emitRecording(Recording*)),m.display->getViewHistoryPage(),SLOT(addRecording(Recording *)));
    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitRecording(Recording*)),m.display->getViewHistoryPage(),SLOT(addRecording(Recording *)));
    connect(m.display->getTherapyPage(),SIGNAL(emitTurnOffStart(int)),m.power,SLOT(adjustPowerLevelDuringTherapy(int)));
    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitTurnOffStart(int)),m.power,SLOT(adjustPowerLevelDuringTherapy(int)));
    connect(m.display,SIGNAL(emitTurnOffStart(int)),m.power,SLOT(adjustPowerLevelDuringTherapy(int)));
    connect(m.display,SIGNAL(emitClearHistory()),m.display->getViewHistoryPage(),SLOT(clearHistory()));
    connect(m.battery,SIGNAL(emitPowerOff()),m.display,SLOT(rechargeBattery()));
    connect(m.display,SIGNAL(emitStartCharge()),&thread,SLOT(start()));
    connect(m.display,SIGNAL(emitChangetoStartPage()),m.display,SLOT(changetoStartPage()));
    connect(m.display,SIGNAL(emitStopThread()),&thread,SLOT(stopThread()));
    connect(m.display,SIGNAL(emitRecharged(int)),m.battery,SLOT(setBatteryLevel(int)));



    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getTherapyPage(),SLOT(sensorOnSkin(bool)));
    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getTherapyPage(),SLOT(stopTimer()));

    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getFrequencyTherapyPage(),SLOT(sensorOnSkin(bool)));
    connect(m.electrode,SIGNAL(toggled(bool)),m.display->getFrequencyTherapyPage(),SLOT(stopTimer()));


    connect(m.display->getTherapyPage(),SIGNAL(emitSensorOffSkin()),m.electrode,SLOT(sensorOffSkin()));

    connect(m.display->getFrequencyTherapyPage(),SIGNAL(emitSensorOffSkin()),m.electrode,SLOT(sensorOffSkin()));

    connect(m.display,SIGNAL(emitSensorOffSkin()),m.electrode,SLOT(sensorOffSkin()));

    connect(m.power,SIGNAL(emitPowerLevel(int)),m.battery,SLOT(setDrainingSpeed(int)));
}




Cpu::~Cpu(){


}


