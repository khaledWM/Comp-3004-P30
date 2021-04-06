#ifndef PROGRAMSPAGE_H
#define PROGRAMSPAGE_H


#include <QWidget>
#include <QListWidget>
#include"page.h"


class ProgramsPage: public Page{
    Q_OBJECT

private:
    QListWidget *list ;


public:
    ProgramsPage(QWidget *parent =nullptr);




};

#endif // PROGRAMSPAGE_H
