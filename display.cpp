#include "display.h"
#include <QListWidget>
#include<QDebug>
#include"mainmenupage.h"
#include"startpage.h"
#include"programspage.h"

Display::Display(QWidget *parent ): QStackedWidget (parent){


      setGeometry(240,40,391,321);
      setStyleSheet("background-color:rgb(211, 215, 207);");

      Page *startPage = new StartPage;
      Page *mainPage = new MainMenuPage;
      Page *programsPage= new ProgramsPage;


      this->addWidget(startPage);
      this->addWidget(mainPage);
      this->addWidget(programsPage);

      qDebug()<< startPage->getID();
//      setCurrentIndex(1);

}

void Display::changeToMainPage()
{
    if(this->currentIndex() == 0)
    {
        setCurrentIndex(1);
    }
}
