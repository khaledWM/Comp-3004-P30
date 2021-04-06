#ifndef DISPLAY_H
#define DISPLAY_H
#include"page.h"
#include <QStackedWidget>
#include<QPushButton>
#include "frequencypage.h"
#include "historypage.h"

class Display: public QStackedWidget{
    Q_OBJECT

private:
    Page * pages[10];

public:
    Display(QWidget *parent =nullptr);
    Page* getPage(int);

private slots:
    void changeToMainPage();
    void selectChoice();
    void navigateDownList();
    void navigateUpList();
    void backOutOfPage();
};

#endif // DISPLAY_H
