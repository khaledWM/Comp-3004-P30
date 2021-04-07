#include "page.h"


int Page::nextID=1;
Page::Page(QWidget *parent ): QWidget (parent){

    setGeometry(240,40,390,320);
    list = new QListWidget;
    id = nextID;
    ++nextID;
}

Page::~Page(){};

int Page::getID(){
    return id;
}


