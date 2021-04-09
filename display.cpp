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
      ftp= new FrequencyTherapyPage;



      this->addWidget(sp);
      this->addWidget(mp);
      this->addWidget(pp);
      this->addWidget(fp);
      this->addWidget(hp);
      this->addWidget(tp);
      this->addWidget(vp);
      this->addWidget(np);
      this->addWidget(ftp);

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

FrequencyTherapyPage * Display::getFrequencyTherapyPage(){

    return ftp;
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
        int currentRow=this->pp->list->currentRow();
        startProgram(currentRow);
    }
    else if(this->currentIndex()==4){
        setCurrentIndex(6);
    }


}

void Display:: startProgram(int programNumber){

    if (programNumber == 0){
        allergy= new Allergy;
        tp->setMinsAndSecs(allergy->minutes,allergy->seconds);
        tp->setName(allergy->programName);
        tp->setFrequency(allergy->frequency);
    }
    else if(programNumber==1){
        bloating= new Bloating;
        tp->setMinsAndSecs(bloating->minutes,bloating->seconds);
        tp->setName(bloating->programName);
        tp->setFrequency(bloating->frequency);
    }
    else if (programNumber==2) {
        trauma= new Trauma;
        tp->setMinsAndSecs(trauma->minutes,trauma->seconds);
        tp->setName(trauma->programName);
        tp->setFrequency(trauma->frequency);
    }
    else if(programNumber==3){
        kidney =new Kidney;
        tp->setMinsAndSecs( kidney->minutes, kidney->seconds);
        tp->setName( kidney->programName);
        tp->setFrequency(kidney->frequency);
    }

setCurrentIndex(5);
}
void Display:: startFrequency(){
ftp->setName("Frequency");
ftp->setFrequency(fp->getValue().toInt());
        setCurrentIndex(8);
}

void Display:: navigateDownList(){


    if(this->currentIndex()==1 && this->mp->list->currentRow()<this->mp->list->count()-1){
        this->mp->list->setCurrentRow(this->mp->list->currentRow()+1);
    }
    else if (this->currentIndex()==2 && this->pp->list->currentRow()<this->pp->list->count()-1) {
        this->pp->list->setCurrentRow(this->pp->list->currentRow()+1);
    }
    else if (this->currentIndex()==4 && this->hp->list->currentRow()<this->hp->list->count()-1) {
        this->hp->list->setCurrentRow(this->hp->list->currentRow()+1);
    }

    else if (this->currentIndex() == 5 && this->tp->list->currentRow()<this->tp->list->count()-1) {
        this->tp->list->setCurrentRow(this->tp->list->currentRow()+1);
    }
}

void Display:: navigateUpList(){

    if(this->currentIndex()==1 && this->mp->list->currentRow()>0){
        this->mp->list->setCurrentRow(this->mp->list->currentRow()-1);
    }
    else if (this->currentIndex()==2 && this->pp->list->currentRow()>0) {
        this->pp->list->setCurrentRow(this->pp->list->currentRow()-1);
    }
    else if (this->currentIndex()==4 && this->hp->list->currentRow()>0) {
        this->hp->list->setCurrentRow(this->hp->list->currentRow()-1);
    }
    else if (this->currentIndex() == 5 && this->tp->list->currentRow()>0) {
        this->tp->list->setCurrentRow(this->tp->list->currentRow()-1);
    }
}


void Display:: backOutOfPage(){
    if(this->currentIndex()>1){
         if (this->currentIndex()==5) {
             this->tp->endTimer();
            setCurrentIndex(2);
        }
         else if (this->currentIndex()==6) {

             setCurrentIndex(4);
         }
         else if(this->currentIndex() == 8){
             this->ftp->endTimer();
             setCurrentIndex(1);
         }
        else {
            setCurrentIndex(1);
        }
    }


}


