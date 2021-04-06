#ifndef STARTPAGE_H
#define STARTPAGE_H


#include <QWidget>
#include <QListWidget>
#include<QLabel>
#include"page.h"


class StartPage: public Page{
    Q_OBJECT

private:
    QLabel *label;


public:
    StartPage(QWidget *parent =nullptr);




};

#endif // STARTPAGE_H
