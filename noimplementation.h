#ifndef NOIMPLEMENTATION_H
#define NOIMPLEMENTATION_H

#include <QObject>
#include <QWidget>
#include<QLabel>
#include"page.h"

class noImplementation : public Page
{
    Q_OBJECT
public:
    explicit noImplementation(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *label;
};

#endif // NOIMPLEMENTATION_H
