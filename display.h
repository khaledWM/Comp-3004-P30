#ifndef DISPLAY_H
#define DISPLAY_H
class Cpu;

#include <QStackedWidget>
#include<QPushButton>
#include <QListWidget>
#include<QDebug>
#include"page.h"
#include "frequencypage.h"
#include "historypage.h"
#include "therapypage.h"
#include"mainmenupage.h"
#include"startpage.h"
#include"programspage.h"
#include"powerdownpage.h"
#include"noimplementation.h"
#include"viewhistorypage.h"
#include "powerlevel.h"
#include"frequencytherapypage.h"
#include"bloating.h"
#include"allergy.h"
#include"trauma.h"
#include"kidney.h"



class Display: public QStackedWidget{
    Q_OBJECT


private:
    StartPage *startPage;
    MainMenuPage *mainMenuPage;
    ProgramsPage *programsPage;
    FrequencyPage *frequencyPage;
    HistoryPage *historyOptionsPage;
    TherapyPage *therapyPage;
    NoImplementation *noImplementationPage;
    ViewHistoryPage *viewHistoryPage;
    FrequencyTherapyPage* frequencyTherapyPage;
    PowerDownPage* powerDownPage;
    PowerLevel *pl;
    Trauma *trauma;
    Allergy *allergy;
    Bloating *bloating;
    Kidney *kidney;

    int current;


public:
    Display(QWidget *parent =nullptr);
    ~Display();
    void startProgram(int programNumber);
    StartPage* getStartPage();
    MainMenuPage* getMainPage();
    ProgramsPage* getProgramsPage();
    FrequencyPage* getFrequencyPage();
    HistoryPage* getHistoryPage();
    TherapyPage* getTherapyPage();
    ViewHistoryPage* getViewHistoryPage();
    FrequencyTherapyPage* getFrequencyTherapyPage();
    NoImplementation* getNoImplementationPage();

private:
    void enableButtons(bool);
    void setFrequencyOnSlider(int);
    void resetFrequencyOnSlider();

signals:
    void allowButton(bool);
    void emitFrequency(int);
    void resetFrequency();
    void emitClearHistory();
    void emitRechargeBattery();
    void emitTurnOffStart(int);


private slots:
    void changeToMainPage();
    void selectChoice();
    void startFrequency();
    void navigateDownList();
    void navigateUpList();
    void backOutOfPage();
    void powerOff();
};

#endif // DISPLAY_H
