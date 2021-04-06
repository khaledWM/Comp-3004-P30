#ifndef DISPLAY_H
#define DISPLAY_H
#include"page.h"
#include <QStackedWidget>
#include<QPushButton>

class Display: public QStackedWidget{
    Q_OBJECT

private:
    Page * pages[5];

public:
    Display(QWidget *parent =nullptr);

private slots:
    void changeToMainPage();
    void selectChoice();
    void navigateDownList();
    void navigateUpList();
    void backOutOfPage();
};

#endif // DISPLAY_H
