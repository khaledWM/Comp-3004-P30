#include "page.h"
#include<QDebug>
#include<QLabel>
#include <QLayout>



int Page::nextID=1;
Page::Page(QWidget *parent ): QWidget (parent){

    setGeometry(240,40,391,321);
    list = new QListWidget;
    id = nextID;
    ++nextID;
}


int Page::getID(){
    return id;
}


