#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QPushButton>
#include <QMainWindow>
#include <QSlider>
#include <QListView>
#include <QObject>
#include <QLabel>
#include <QLayout>

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


};

#endif // FREQUENCY_H