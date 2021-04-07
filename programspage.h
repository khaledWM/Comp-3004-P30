#ifndef PROGRAMSPAGE_H
#define PROGRAMSPAGE_H
#include"page.h"
#include <QWidget>
#include <QListWidget>
#include<QDebug>
#include<QLabel>
#include <QLayout>




class ProgramsPage: public Page{
    Q_OBJECT

public:
    ProgramsPage(QWidget *parent =nullptr);
   ~ProgramsPage();




};

#endif // PROGRAMSPAGE_H
