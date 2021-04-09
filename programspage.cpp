#include"programspage.h"

ProgramsPage::ProgramsPage(QWidget *parent ): Page (parent){
    this->list->addItem("Allergy");
    this->list->addItem("Bloating");
    this->list->addItem("Trauma");
    this->list->addItem("Kidneys");
    this->list->addItem("back");
    this->list->addItem("arms");

    list->setCurrentRow(0);

    QLayout *layout = new QVBoxLayout();

    layout->addWidget(list);
    setLayout(layout);

}

ProgramsPage::~ProgramsPage(){}






