#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(250,250,700,700);
    setFixedSize(size());
    setWindowTitle("DENAS PCM6 Simulation");

        display = new Display(this);
        battery = new Battery(100,475,50,this);
        QLabel *batteryLabel = new QLabel("Battery",this);
        batteryLabel->move(375,50);

        power = new PowerLevel(this);
        QLabel *powerLevelLabel = new QLabel("Power Level", this);
        powerLevelLabel->move(375,150);

        electrode = new Electrode(this);
        QLabel *electrodeLabel = new QLabel("Electrode",this);
        electrodeLabel->move(375,200);

        QLabel *fslabel = new QLabel(this);
        fslabel->setText("Frequency");
        fslabel->move(375,100);
        fs = new Frequency(this);

        up = new Button(tr("Up"),150,300,this);
        down  = new Button(tr("Down"),125,400,this);
        left  = new Button(tr("Left"),25,350,this);
        right  = new Button(tr("right"),250,350,this);
        start  = new Button(tr("Start"),250,300,this);
        ok = new Button(tr("Ok"),150,350,this);
        back  = new Button(tr("Back"),25,300,this);

}





MainWindow::~MainWindow()
{

    delete ui;

}


