#include "viewhistorypage.h"


ViewHistoryPage::ViewHistoryPage(QWidget *parent):Page(parent)
{
list= new QListWidget();

QLabel *label = new QLabel();
label->setText("No data to display");

layout = new QGridLayout();
layout->addWidget(label);
setLayout(layout);
}

ViewHistoryPage::~ViewHistoryPage(){};

void ViewHistoryPage::addRecording(Recording* r){
    QLayout *layout2 = new QHBoxLayout();
    QListWidget *list1 = new QListWidget();
    QString freq = QString::number(r->getFreq());
    QString mins = QString::number(r->getMinutes());
    QString secs = QString::number(r->getSeconds());
    QString powerLevel = QString::number(r->getPowerLevel());
    list1->addItem(r->getDate().toString("hh : mm"));
    if(r->getType()=="Program"){
        list1->addItem("Treatment: "+r->getType()+", " +r->getName());
    }
    else{
        list1->addItem("Treatment: "+r->getType());
    }

    list1->addItem("Power level: "+ powerLevel);
    list1->addItem("Frequency "+freq);
    list1->addItem("Duration: "+ mins +"m"+secs+"s");

    layout2->addWidget(list1);
    layout->addLayout(layout2,row,col);
    this->row++;
}
