/* FrequencyTherapyPage Class
 *
 * concrete entity class that extends
 * the abstract Page class
 *
 * provides all of the fuctionality of
 * the frequency page.
*/

#ifndef FREQUENCYTHERAPYPAGE_H
#define FREQUENCYTHERAPYPAGE_H

#include <QObject>
#include <QWidget>
#include<QLCDNumber>
#include<QTimer>
#include<QTime>
#include "page.h"
#include"recording.h"

class FrequencyTherapyPage : public Page
{
    Q_OBJECT
public:
    FrequencyTherapyPage(QString = "NULL", int = 60, QWidget *parent = nullptr);
    ~FrequencyTherapyPage();


    QPushButton* getStartStop();
    QPushButton* getEnd();
    QString getName();
    void setName(QString);
    void setFrequencyAndPower(int);
    //    int getMins();
    //    int getSeconds();
    //    int getFrequency();
    //    int getPowerLevel();

signals:
    void emitStopThread();
    void emitRecording(Recording*);
    void emitTurnOffStart(int);
    void emitSensorOffSkin();

public slots:
     void endTimer();

private:
    QString minString ;
    QString secsString;
    QString name;
    QLCDNumber *frequencyTherapyTimerDisplay;
    QTimer *timer;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *frequencyLabel;
    QLabel *powerLabel;
    QLabel *setPowerLabel;
    QLayout *layout;
    Recording * r;

    bool electrodePlaced=false;
    int timerMins;
    int timerSecs;
    int freq;
    int powerLevel;
    int counter = 1;
    bool frequencyTherapyStarted=false;
    void validateTime(int, int);
    void createRecording(QString ,QString, QTime , int , int , int, int );

private slots:
    void showTime();
    void startTimer();
    void stopTimer();
    void increasePowerLevel(int);
    void decreasePowerLevel(int);
    void showFrequencyOnDisplay(int);
    void sensorOnSkin(bool);

};

#endif // FREQUENCYTHERAPYPAGE_H
