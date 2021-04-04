#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QGridLayout>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      Button *upButton = new Button(tr("Up"),0,0,this);
    Button *downButton = new Button(tr("Down"),100,0,this);
    Button *leftButton = new Button(tr("Left"),200,0,this);
    Button *rightButton = new Button(tr("right"),300,0,this);

    connect(upButton,SIGNAL(clicked()),upButton,SLOT(upButtonClicked()));

    connect(downButton,SIGNAL(clicked()),downButton,SLOT(downButtonClicked()));

    connect(leftButton,SIGNAL(clicked()),leftButton,SLOT(leftButtonClicked()));

    connect(rightButton,SIGNAL(clicked()),rightButton,SLOT(rightButtonClicked()));

}





MainWindow::~MainWindow()
{

    delete ui;

}


