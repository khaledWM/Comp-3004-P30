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
      
    Display *display = new Display(this);
    Battery *battery = new Battery(98,100,600,this);
    PowerLevel *power = new PowerLevel(this);

    Frequency *fs = new Frequency(this);

    Button *upButton = new Button(tr("Up"),0,0,this);
    Button *downButton = new Button(tr("Down"),100,0,this);
    Button *leftButton = new Button(tr("Left"),200,0,this);
    Button *rightButton = new Button(tr("right"),300,0,this);
    Button *start = new Button(tr("Start"),100,50,this);
    Button *ok = new Button(tr("Ok"),100,100,this);
    Button *back = new Button(tr("Back"),100,200,this);


    power->move(400,400);

    connect(start,SIGNAL(clicked()),display,SLOT(changeToMainPage()));
    connect(ok,SIGNAL(clicked()),display,SLOT(selectChoice()));
    connect(upButton,SIGNAL(clicked()),display,SLOT(navigateUpList()));
    connect(downButton,SIGNAL(clicked()),display,SLOT(navigateDownList()));
    connect (back,SIGNAL(clicked()),display,SLOT(backOutOfPage()));
    connect(leftButton,SIGNAL(clicked()),leftButton,SLOT(leftButtonClicked()));
    connect(rightButton,SIGNAL(clicked()),rightButton,SLOT(rightButtonClicked()));

}





MainWindow::~MainWindow()
{

    delete ui;

}


