#include "display.h"

Display::Display(QWidget *parent ): QStackedWidget (parent){


      setGeometry(240,40,390,320);
      setStyleSheet("background-color:rgb(211, 215, 207);");

      pages[0] = new StartPage;
      pages[1]  = new MainMenuPage;
      pages[2] = new ProgramsPage;
      pages[3] = new FrequencyPage;
      pages[4] = new HistoryPage;
      pages[5] = new TherapyPage("pain",77,100,2,2,nullptr);
      pages[6]= new ViewHistoryPage;
      pages[7] = new NoImplementation;




      this->addWidget(pages[0]);
      this->addWidget(pages[1]);
      this->addWidget(pages[2]);
      this->addWidget(pages[3]);
      this->addWidget(pages[4]);
      this->addWidget(pages[5]);
      this->addWidget(pages[6]);
      this->addWidget(pages[7]);

}

Display::~Display(){

}

Page* Display::getPage(int index)
{
    return pages[index];
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

    else if (this->currentIndex()== 1){
        int currentRow=this->pages[1]->list->currentRow();


        if (currentRow==0){
            setCurrentIndex(2);
        }
        else if(currentRow ==1){
            setCurrentIndex(3);
        }
        else if(currentRow==2){
            setCurrentIndex(4);
        }
        else {
            setCurrentIndex(7);
        }

    }
    else if (this->currentIndex()==2) {

        setCurrentIndex(5);
    }
    else if(this->currentIndex()==4){
       // int currentRow=this->pages[1]->list->currentRow();
        setCurrentIndex(6);
    }

}

void Display:: navigateDownList(){

    if(this->currentIndex()==1){
        this->pages[1]->list->setCurrentRow(this->pages[1]->list->currentRow()+1);
    }
    else if (this->currentIndex()==2) {
        this->pages[2]->list->setCurrentRow(this->pages[2]->list->currentRow()+1);
    }
    else if (this->currentIndex()==4) {
        this->pages[4]->list->setCurrentRow(this->pages[4]->list->currentRow()+1);
    }
    else if (this->currentIndex() == 5) {
        this->pages[5]->list->setCurrentRow(this->pages[5]->list->currentRow()+1);
    }
}

void Display:: navigateUpList(){

    if(this->currentIndex()==1){
        this->pages[1]->list->setCurrentRow(this->pages[1]->list->currentRow()-1);
    }
    else if (this->currentIndex()==2) {
        this->pages[2]->list->setCurrentRow(this->pages[2]->list->currentRow()-1);
    }
    else if (this->currentIndex()==4) {
        this->pages[4]->list->setCurrentRow(this->pages[4]->list->currentRow()-1);
    }
    else if (this->currentIndex() == 5) {
        this->pages[5]->list->setCurrentRow(this->pages[5]->list->currentRow()-1);
    }
}


void Display:: backOutOfPage(){
    if(this->currentIndex()>1){
         if (this->currentIndex()==5) {
            setCurrentIndex(2);
        }
         else if (this->currentIndex()==6) {
             setCurrentIndex(4);
         }
        else {
            setCurrentIndex(1);
        }
    }


}


