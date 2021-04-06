#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QPushButton>
#include <QMainWindow>
#include <QSlider>
#include <QListView>
#include <QObject>
#include <QLabel>

using namespace std;

class Frequency : public QSlider
{

    Q_OBJECT

public:
    explicit Frequency(QWidget *parent = nullptr);
    ~Frequency();

private:
    QLabel *frequencyLabel;

signals:
//void sliderMoved(int);

};

#endif // FREQUENCY_H
