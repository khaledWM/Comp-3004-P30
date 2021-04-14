/* Frequency Class
 *
 * inherits the QT calss QSlider
 *
 * allows the user to set their desired
 * frequency through a slider.
 *
 * attributes:
 *  value
*/
#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QPushButton>
#include <QMainWindow>
#include <QSlider>
#include <QListView>
#include <QObject>
#include <QLabel>
#include <QLayout>
#include <iostream>

using namespace std;

class Frequency : public QSlider
{

    Q_OBJECT

public:
    explicit Frequency(QWidget *parent = nullptr);
    ~Frequency();
    int getValue();

private:
    int value;

private slots:
   void setFrequencyValue(int);
   void enableFrequencyChange();


};

#endif // FREQUENCY_H
