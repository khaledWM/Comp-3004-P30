#ifndef RECORDING_H
#define RECORDING_H

#include <QString>
#include <QObject>
#include <QTime>
class Recording: public QObject
{
    Q_OBJECT
public:
    Recording(QString, QTime,int,int,int,int);
    QString getName();
    QTime getDate();
    int getPowerLevel();
    int getFreq();
    int getSeconds();
    int getMinutes();
private:
    QString name;
    QTime date;
    int powerLevel;
    int freq;
    int seconds;
    int minutes;

};

#endif // RECORDING_H
