#ifndef FREQUENCYPAGE_H
#define FREQUENCYPAGE_H

#include "page.h"
#include <QLabel>
#include <QLayout>

class FrequencyPage : public Page
{
    Q_OBJECT

public:
    FrequencyPage(QWidget *parent = nullptr);
    ~FrequencyPage();
    QString getValue();

private:
    QLabel *promptLabel;
    QLabel *frequencyValue;
    QLayout *layout;


private slots:
    void showValueOnDisplay(int);

};

#endif // FREQUENCYPAGE_H
