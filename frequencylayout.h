#ifndef FREQUENCYLAYOUT_H
#define FREQUENCYLAYOUT_H

#include "frequency.h"
#include "frequencypage.h"
#include "QLayout"

class frequencylayout : public QLayout
{
public:
    frequencylayout(QWidget *parent = nullptr);

private:
    Frequency *fs;
    QLabel *fsLabel;};

#endif // FREQUENCYLAYOUT_H
