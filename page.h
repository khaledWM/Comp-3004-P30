#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include <QListWidget>
#include<QDebug>
#include<QLabel>
#include <QLayout>
#include <QPushButton>

class Page: public QWidget{
    Q_OBJECT


public:
    Page(QWidget *parent =nullptr);
    int getID();
    QListWidget *list ;
    ~Page();
    virtual Page* getPage();
    QPushButton* getStartStop();
    QPushButton* getEnd();
    QPushButton *startStop;
    QPushButton *end;


private:
    static int nextID;
    int id;

};


#endif // PAGE_H
