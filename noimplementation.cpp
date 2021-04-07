#include "noimplementation.h"
NoImplementation::NoImplementation(QWidget *parent) : Page(parent)
{

    label = new QLabel;
    label->setText("Features have not been implemented");
    QLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);

}

NoImplementation::~NoImplementation(){}
