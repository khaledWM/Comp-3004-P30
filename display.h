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


class Display: public QStackedWidget{
    Q_OBJECT

private:
    Page * pages[10];
    TherapyPage *tPages[6];
    int current;


public:
    Display(QWidget *parent =nullptr);
    ~Display();
    Page* getPage(int);

private slots:
    void changeToMainPage();
    void selectChoice();
    void navigateDownList();
    void navigateUpList();
    void backOutOfPage();
};

#endif // DISPLAY_H
