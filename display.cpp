#include "display.h"
#include <QListWidget>
#include<QDebug>
#include"mainmenupage.h"
#include"startpage.h"
#include"programspage.h"
#include"noimplementation.h"


Display::Display(QWidget *parent ): QStackedWidget (parent){


      setGeometry(240,40,390,320);
      setStyleSheet("background-color:rgb(211, 215, 207);");

      pages[0] = new StartPage;
      pages[1]  = new MainMenuPage;
      pages[2] = new ProgramsPage;
      pages[3]= new noImplementation;

      this->addWidget(pages[0]);
      this->addWidget(pages[1]);
      this->addWidget(pages[2]);
      this->addWidget(pages[3]);

      qDebug()<< pages[0]->getID();


}

void Display::changeToMainPage()
{
    if(this->currentIndex() == 0)
    {
        setCurrentIndex(1);
    }
}


void Display:: selectChoice(){
    if(this->currentIndex()==0){
        return;
    }

    if (this->currentIndex()== 1 && this->pages[1]->list->currentRow()==0){
        setCurrentIndex(2);
    }
    else {
        qDebug()<<"here";
        setCurrentIndex(3);
    }


}

void Display:: navigateDownList(){

    if(this->currentIndex()==1){
        this->pages[1]->list->setCurrentRow(this->pages[1]->list->currentRow()+1);
    }
    else if (this->currentIndex()==2) {
        this->pages[2]->list->setCurrentRow(this->pages[2]->list->currentRow()+1);
    }
}

void Display:: navigateUpList(){

    if(this->currentIndex()==1){
        this->pages[1]->list->setCurrentRow(this->pages[1]->list->currentRow()-1);
    }
    else if (this->currentIndex()==2) {
        this->pages[2]->list->setCurrentRow(this->pages[2]->list->currentRow()-1);
    }

}

void Display:: backOutOfPage(){
    qDebug()<<"here";
    if(this->currentIndex()>1){

        setCurrentIndex(currentIndex()-1);
    }
}


