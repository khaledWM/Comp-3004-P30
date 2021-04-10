#ifndef RECORDING_H
#define RECORDING_H

#include <QString>
#include <QObject>
#include <QTime>
class Recording: public QObject
{
    Q_OBJECT
public:
    Recording(QString,QString, QTime,int,int,int,int);
    QString getName();
    QString getType();
    QTime getDate();
    int getPowerLevel();
    int getFreq();
    int getSeconds();
    int getMinutes();
private:
    QString name;
    QString type;
    QTime date;
    int powerLevel;
    int freq;
    int seconds;
    int minutes;

};

#endif // RECORDING_H
