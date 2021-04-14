/* Button Class
 *
 * inherits the QT class QPushButton
 *
 * has no private attributes, everything
 * gets initialized un the constructer arguements
 *
 * the constructer sets the buttons size, coordinate
 * icon, and text.
*/
#ifndef BUTTON_H
#define BUTTON_H
#include <QToolButton>
#include<QPushButton>
#include <QtWidgets>
#include<QDebug>


class Button: public QPushButton{
    Q_OBJECT


private slots:



public:
    Button(const QString &text,int x, int y, const QIcon icon,QWidget *parent =nullptr);
    ~Button();
};

#endif // BUTTON_H
