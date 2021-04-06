#ifndef DISPLAY_H
#define DISPLAY_H
#include"page.h"
#include <QStackedWidget>

class Display: public QStackedWidget{
    Q_OBJECT


public:
    Display(QWidget *parent =nullptr);

private slots:
    void changeToMainPage();
};

#endif // DISPLAY_H
