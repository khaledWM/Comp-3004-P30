#include "frequencylayout.h"

frequencylayout::frequencylayout(QWidget *parent) :
    QLayout (parent)
{
    fs = new Frequency ();
    fsLabel = new QLabel ();

    fsLabel = new QLabel;

    fsLabel->setText("Frequency");
    fsLabel->setGeometry(650,100,50,20);

    addWidget(fsLabel);
    addWidget(fs);

}

//frequencylayout::~frequencylayout(){}
