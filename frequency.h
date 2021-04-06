#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QPushButton>
#include <QMainWindow>
#include <QSlider>
#include <QListView>

using namespace std;

class Frequency : public QSlider
{

    Q_OBJECT

public:
    explicit Frequency(QWidget *parent = nullptr);
    ~Frequency();

signals:
//void sliderMoved(int);

};

#endif // FREQUENCY_H
