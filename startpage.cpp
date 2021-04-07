
#include<QLabel>
#include <QLayout>
#include"startpage.h"

StartPage::StartPage(QWidget *parent ): Page (parent){

    label = new QLabel;
    label->setText("welcome to denas");
    QLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}
StartPage::~StartPage(){}
