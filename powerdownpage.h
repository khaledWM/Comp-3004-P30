#ifndef POWERDOWNPAGE_H
#define POWERDOWNPAGE_H

#include "page.h"

#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QLayout>


class PowerDownPage: public Page
{

    Q_OBJECT
public:
    explicit PowerDownPage(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *label;
};

#endif // POWERDOWNPAGE_H
