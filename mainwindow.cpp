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
    this->setGeometry(0,40,1000,600);
      
    Display *display = new Display(this);
    Battery *battery = new Battery(100,700,50,this);
    PowerLevel *power = new PowerLevel(this);

    Frequency *fs = new Frequency(this);

    Button *upButton = new Button(tr("Up"),400,400,this);
    Button *downButton = new Button(tr("Down"),400,500,this);
    Button *leftButton = new Button(tr("Left"),250,450,this);
    Button *rightButton = new Button(tr("right"),550,450,this);
    Button *start = new Button(tr("Start"),550,400,this);
    Button *ok = new Button(tr("Ok"),400,450,this);
    Button *back = new Button(tr("Back"),250,400,this);

    connect(start,SIGNAL(clicked()),display,SLOT(changeToMainPage()));
    connect(ok,SIGNAL(clicked()),display,SLOT(selectChoice()));
    connect(upButton,SIGNAL(clicked()),display,SLOT(navigateUpList()));
    connect(downButton,SIGNAL(clicked()),display,SLOT(navigateDownList()));
    connect (back,SIGNAL(clicked()),display,SLOT(backOutOfPage()));
    connect(leftButton,SIGNAL(clicked()),leftButton,SLOT(leftButtonClicked()));
    connect(rightButton,SIGNAL(clicked()),rightButton,SLOT(rightButtonClicked()));
//    connect(fs,SIGNAL(valueChanged(int)),this,SLOT(ShowSliderMovedValue(int)));

}

MainWindow::~MainWindow()
{

    delete ui;

}


