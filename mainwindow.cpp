#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QGridLayout>
#include <QtWidgets>
#include"display.h"
#include"powerlevel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,39,828,497);

    Button *upButton = new Button(tr("Up"),0,0,this);
    Button *downButton = new Button(tr("Down"),100,0,this);
    Button *leftButton = new Button(tr("Left"),200,0,this);
    Button *rightButton = new Button(tr("right"),300,0,this);


    Display *display = new Display(this);


    connect(upButton,SIGNAL(clicked()),upButton,SLOT(upButtonClicked()));

    connect(downButton,SIGNAL(clicked()),downButton,SLOT(downButtonClicked()));

    connect(leftButton,SIGNAL(clicked()),leftButton,SLOT(leftButtonClicked()));

    connect(rightButton,SIGNAL(clicked()),rightButton,SLOT(rightButtonClicked()));

    PowerLevel *power = new PowerLevel(this);
    power->move(400,400);


}





MainWindow::~MainWindow()
{

    delete ui;

}


