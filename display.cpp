#include "display.h"


Display::Display(QWidget *parent ): QStackedWidget (parent){


      setGeometry(240,40,390,320);
      setStyleSheet("background-color:rgb(211, 215, 207);");

      sp = new StartPage(this);
      mp  = new MainMenuPage;
      pp = new ProgramsPage;
      fp = new FrequencyPage;
      hp = new HistoryPage;
      tp = new TherapyPage;
      vp = new ViewHistoryPage;
      np = new NoImplementation;


      this->addWidget(sp);
      this->addWidget(mp);
      this->addWidget(pp);
      this->addWidget(fp);
      this->addWidget(hp);
      this->addWidget(tp);
      this->addWidget(vp);
      this->addWidget(np);


}

Display::~Display(){

}


StartPage* Display::getStartPage()
{
    return sp;
}

MainMenuPage* Display::getMainPage()
{
    return mp;
}
ProgramsPage* Display::getProgramsPage()
{
    return pp;
}
FrequencyPage* Display::getFrequencyPage()
{
    return fp;
}
HistoryPage* Display::getHistoryPage()
{
    return hp;
}
TherapyPage* Display::getTherapyPage()
{
    return tp;
}
ViewHistoryPage* Display::getViewHistoryPage()
{
    return vp;
}
NoImplementation* Display::getNoImplementationPage()
{
    return np;
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

    else if (this->currentIndex()== 1)
    {
        int currentRow=this->mp->list->currentRow();


        if (currentRow==0)
        {
            setCurrentIndex(2);
        }
        else if(currentRow ==1){
            setCurrentIndex(3);
        }
        else if(currentRow==2)
        {
            setCurrentIndex(4);
        }
        else {
            setCurrentIndex(7);
        }

    }
    else if (this->currentIndex()==2)
    {
        tp->setName(pp->list->currentItem()->text());
        tp->setFrequency(fp->getValue().toInt());
//        tp->setPowerLevel()
        setCurrentIndex(5);
    }
    else if(this->currentIndex()==4){
       // int currentRow=this->mp->list->currentRow();
        setCurrentIndex(6);
    }


}

void Display:: navigateDownList(){

    if(this->currentIndex()==1){
        this->mp->list->setCurrentRow(this->mp->list->currentRow()+1);
    }
    else if (this->currentIndex()==2) {
        this->pp->list->setCurrentRow(this->pp->list->currentRow()+1);
    }
    else if (this->currentIndex()==4) {
        this->hp->list->setCurrentRow(this->hp->list->currentRow()+1);
    }

    else if (this->currentIndex() == 5) {
        this->tp->list->setCurrentRow(this->tp->list->currentRow()+1);
    }
}

void Display:: navigateUpList(){

    if(this->currentIndex()==1){
        this->mp->list->setCurrentRow(this->mp->list->currentRow()-1);
    }
    else if (this->currentIndex()==2) {
        this->pp->list->setCurrentRow(this->pp->list->currentRow()-1);
    }
    else if (this->currentIndex()==4) {
        this->hp->list->setCurrentRow(this->hp->list->currentRow()-1);
    }
    else if (this->currentIndex() == 5) {
        this->tp->list->setCurrentRow(this->tp->list->currentRow()-1);
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


