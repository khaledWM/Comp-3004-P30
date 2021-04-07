#ifndef NOIMPLEMENTATION_H
#define NOIMPLEMENTATION_H

#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QLayout>
#include"page.h"

class NoImplementation : public Page
{
    Q_OBJECT
public:
    explicit NoImplementation(QWidget *parent = nullptr);
    ~NoImplementation();


signals:

public slots:

private:
    QLabel *label;
};

#endif // NOIMPLEMENTATION_H
