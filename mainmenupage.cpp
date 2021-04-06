#include<QDebug>
#include<QLabel>
#include <QLayout>
#include"mainmenupage.h"

MainMenuPage::MainMenuPage(QWidget *parent ): Page (parent){

    list = new QListWidget();
    this->list->addItem("Program");
    this->list->addItem("Frequency");
    this->list->addItem("MED");
    this->list->addItem("Screening");
    this->list->addItem("Recordings");
    this->list->addItem("Settings");


    QLayout *layout = new QVBoxLayout();

    layout->addWidget(list);
    setLayout(layout);



}
