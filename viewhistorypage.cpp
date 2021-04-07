#include "viewhistorypage.h"


ViewHistoryPage::ViewHistoryPage(QWidget *parent):Page(parent)
{
list= new QListWidget();

QLabel *label = new QLabel();
label->setText("No data to display");


QLayout *layout = new QVBoxLayout();
layout->addWidget(label);

setLayout(layout);
}

ViewHistoryPage::~ViewHistoryPage(){};
