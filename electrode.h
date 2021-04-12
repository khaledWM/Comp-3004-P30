#ifndef ELECTRODE_H
#define ELECTRODE_H

#include <QObject>
#include <QWidget>
#include <QCheckBox>

class Electrode : public QCheckBox
{
    Q_OBJECT;

public:
    Electrode(QWidget *parent=nullptr);
    ~Electrode();

private slots:
    void sensorOffSkin();
};

#endif // ELECTRODE_H
