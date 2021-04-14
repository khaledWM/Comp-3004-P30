/*

Frequency Class

Concrete Enetity Class that extends QSlider.

Attributes:
value

Member Functions:
getter for value - getValue()

slots:
setFrequencyValue(int).
enableFrequencyChange().

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
    int getValue();   // getter for frequency value selected from slider.

private:
    int value;      // stores the value selected from slider.

private slots:

   // slot for connecting to the signal emitted by the slider when moved.
   void setFrequencyValue(int);


   void enableFrequencyChange();


};

#endif // FREQUENCY_H
