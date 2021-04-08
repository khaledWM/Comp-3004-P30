#ifndef DISPLAY_H
#define DISPLAY_H

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
#include"noimplementation.h"
#include"viewhistorypage.h"
#include "powerlevel.h"


class Display: public QStackedWidget{
    Q_OBJECT

private:
    StartPage *sp;
    MainMenuPage *mp;
    ProgramsPage *pp;
    FrequencyPage *fp;
    HistoryPage *hp;
    TherapyPage *tp;
    NoImplementation *np;
    ViewHistoryPage *vp;

    PowerLevel *pl;

    int current;


public:
    Display(QWidget *parent =nullptr);
    ~Display();
//    Page* getPage(int);
    StartPage* getStartPage();
    MainMenuPage* getMainPage();
    ProgramsPage* getProgramsPage();
    FrequencyPage* getFrequencyPage();
    HistoryPage* getHistoryPage();
    TherapyPage* getTherapyPage();
    ViewHistoryPage* getViewHistoryPage();
    NoImplementation* getNoImplementationPage();

private slots:
    void changeToMainPage();
    void selectChoice();
    void navigateDownList();
    void navigateUpList();
    void backOutOfPage();
};

#endif // DISPLAY_H
