#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,40,1000,600);


        display = new Display(this);
        battery = new Battery(100,700,50,this);
        power = new PowerLevel(this);

        QLabel *fslabel = new QLabel(this);
        fslabel->setText("Frequency");
        fslabel->setGeometry(700,100,80,30);

        fs = new Frequency(this);

        up = new Button(tr("Up"),400,400,this);
        down  = new Button(tr("Down"),400,500,this);
        left  = new Button(tr("Left"),250,450,this);
        right  = new Button(tr("right"),550,450,this);
        start  = new Button(tr("Start"),550,400,this);
        ok = new Button(tr("Ok"),400,450,this);
        back  = new Button(tr("Back"),250,400,this);

}

MainWindow::~MainWindow()
{

    delete ui;

}


