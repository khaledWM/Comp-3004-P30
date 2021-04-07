#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< Updated upstream

#include "button.h"
=======
#include <QLabel>
#include<QDebug>
#include <QGridLayout>
#include <QtWidgets>
#include "button.h"
#include "battery.h"
#include "frequency.h"
#include "frequencylayout.h"
#include"display.h"
#include"powerlevel.h"
#include "ui_mainwindow.h"
#include"display.h"
#include"powerlevel.h"


>>>>>>> Stashed changes

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
