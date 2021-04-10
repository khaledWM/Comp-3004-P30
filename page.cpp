#include "page.h"


int Page::nextID=1;
Page::Page( QWidget *parent ): QWidget (parent){

    setGeometry(240,40,390,320);
    list = new QListWidget;
    id = nextID;
    ++nextID;

    startStop = new QPushButton();
    end = new QPushButton();
}

Page::~Page(){};

int Page::getID(){
    return id;
}

Page* Page::getPage(){
    return this;
}

QPushButton* Page::getStartStop(){
    return startStop;
}
QPushButton* Page::getEnd(){
    return end;
}





