#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include <QListWidget>
class Page: public QWidget{
    Q_OBJECT



public:
    Page(QWidget *parent =nullptr);
    int getID();
    QListWidget *list ;


private:

    static int nextID;
    int id;




};


#endif // PAGE_H
