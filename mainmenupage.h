#ifndef MAINMENUPAGE_H
#define MAINMENUPAGE_H


#include <QWidget>
#include <QListWidget>
#include"page.h"


class MainMenuPage: public Page{
    Q_OBJECT



public:
    MainMenuPage(QWidget *parent =nullptr);
    ~MainMenuPage();




};

#endif // MAINMENUPAGE_H
