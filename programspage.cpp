#include<QDebug>
#include<QLabel>
#include <QLayout>
#include"programspage.h"

ProgramsPage::ProgramsPage(QWidget *parent ): Page (parent){
    this->list->addItem("Throat");
    this->list->addItem("Feet");
    this->list->addItem("Stomach");
    this->list->addItem("Screening");
    this->list->addItem("back");
    this->list->addItem("arms");

    list->setCurrentRow(0);

    QLayout *layout = new QVBoxLayout();

    layout->addWidget(list);
    setLayout(layout);

}

ProgramsPage::~ProgramsPage(){}






