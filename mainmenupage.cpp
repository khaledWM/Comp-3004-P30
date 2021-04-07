#include"mainmenupage.h"

MainMenuPage::MainMenuPage(QWidget *parent ): Page (parent){

   // list = new QListWidget();
    this->list->addItem("Program");
    this->list->addItem("Frequency");
    this->list->addItem("History");
    this->list->addItem("Screening");
    this->list->addItem("Power Level");
    this->list->addItem("Settings");

    list->setCurrentRow(0);


    QLayout *layout = new QVBoxLayout();

    layout->addWidget(list);
    setLayout(layout);

}


MainMenuPage::~MainMenuPage(){}
