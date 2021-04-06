#ifndef FREQUENCYPAGE_H
#define FREQUENCYPAGE_H

#include "page.h"
#include <QLabel>
#include <QLayout>

class frequencypage : public Page
{
    Q_OBJECT

public:
    frequencypage(QWidget *parent = nullptr);
    ~frequencypage();

private:
    QLabel *promptLabel;
    QLabel *frequencyValue;
    QLayout *layout;

private slots:
    void showValueOnDisplay(int);

};

#endif // FREQUENCYPAGE_H
