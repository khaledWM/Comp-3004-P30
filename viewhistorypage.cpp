#include "viewhistorypage.h"


ViewHistoryPage::ViewHistoryPage(QWidget *parent):Page(parent)
{
list= new QListWidget();

QLabel *label = new QLabel();
label->setText("No data to display");

layout = new QGridLayout();
layout->addWidget(label);
/*QLayout *layout2 = new QHBoxLayout();
QLayout *layout3= new QHBoxLayout();
QListWidget *list1 = new QListWidget();
QListWidget *list2 = new QListWidget();
list1->addItem("frequency");
list1->addItem("77");
list2->addItem("therapy");
list2->addItem("85");
layout2->addWidget(list1);
layout3->addWidget(list2);
layout->addLayout(layout2,0,0);
layout->addLayout(layout3,2,0);*/

setLayout(layout);
}

ViewHistoryPage::~ViewHistoryPage(){};

void ViewHistoryPage::addRecording(int pl){
    //QLayout *layout2 = new QHBoxLayout();
    //QListWidget *list1 = new QListWidget();
    qDebug() << pl;

}
