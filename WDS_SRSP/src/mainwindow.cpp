#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "ui_settingwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _portReader = new SerialPortReader(this);
    _sWindow = new SettingWindow(_portReader->getSerialSettings(), this);
    _plotWindow = new PlotWindow(this);
    _receiverThread = new ReceiverThread(_portReader);
    _scene = new Scene(this);
    setupScene();

    connect(_sWindow, SIGNAL(connectToSerialPort()),
            _portReader, SLOT(openSerialPort()));
    connect(_sWindow, SIGNAL(disconectFromSerialPort()),
            _portReader, SLOT(closeSerialPort()));

    // port opened
    connect(_portReader, SIGNAL(portOpened()),
            this, SLOT(on_serial_port_opened()));
    connect(_portReader, SIGNAL(portOpened()),
            _receiverThread, SLOT(onPortOpened()));

    // port closed
    connect(_portReader, SIGNAL(portClosed()),
            this, SLOT(on_serial_port_closed()));

    // errors
    connect(_portReader, SIGNAL(portError(QString)),
            this, SLOT(ErrorHandler(QString)));
    connect(_receiverThread, SIGNAL(threadError(QString)),
            this, SLOT(ErrorHandler(QString)));

    // new data
    connect(_portReader, SIGNAL(newData(rawData)),
            _plotWindow, SLOT(new_data_received(rawData)));
    connect(_portReader, SIGNAL(newData(rawData)),
            _scene, SLOT(newDataArrived(rawData)));
    ui->speedWidget->hide();
    redLed();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _portReader;
    delete _sWindow;
    delete _plotWindow;
}


void MainWindow::on_ResetPushButton_clicked()
{
    _scene->resetScene();
    _scene->stopAnimation();
    emit resetSimulation();
}


void MainWindow::on_StopPushButton_clicked()
{
    _scene->stopAnimation();
    emit stopSimulation();
}


void MainWindow::on_StartPushButton_clicked()
{
    _scene->startAnimation();
    emit startSimulation();
}


void MainWindow::on_ObstacleCheckBox_stateChanged(int arg1)
{
    if(arg1){
        emit obstacleON();
    }else{
        emit obstacleOFF();
    }
}

void MainWindow::on_SpeedCheckBox_stateChanged(int arg1)
{
    if(arg1){
        ui->speedWidget->show();
        emit constSpeed();
    }else{
        ui->speedWidget->hide();
        emit variableSpeed();
    }
}

void MainWindow::on_connectAction_triggered()
{
    _portReader->openSerialPort();
}


void MainWindow::on_disconnectAction_triggered()
{
    _portReader->closeSerialPort();
}


void MainWindow::on_settingAction_triggered()
{
    _sWindow->update();
    _sWindow->show();
}

void MainWindow::on_serial_port_opened()
{
    if(_portReader->getPortOpened()){
        ui->mainConnectLabel->setText(QStringLiteral("Połączono z mikrokontrolerem"));
        greenLed();
    }else{
        ui->mainConnectLabel->setText(QStringLiteral("Brak połączenia z mikrokontrolerem"));
        redLed();
    }

}

void MainWindow::on_serial_port_closed()
{
    ui->mainConnectLabel->setText(QStringLiteral("Brak połączenia z mikrokontrolerem"));
    redLed();
}

void MainWindow::ErrorHandler(QString error_msg)
{
    QMessageBox::critical(this, QStringLiteral("Błąd"), error_msg);
}

void MainWindow::greenLed()
{
    ui->led->setPixmap(QPixmap(":/img/img/led/led_green.png"));
}

void MainWindow::redLed()
{
    ui->led->setPixmap(QPixmap(":/img/img/led/led_red.png"));
}

void MainWindow::setupScene()
{
    //_scene->setSceneRect(0,0, 739, 480);
    _scene->setBackgroundBrush(QBrush(QRgb(0xFFDFD3)));
    _scene->addRoad();
    _scene->addCar();

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(_scene);

}


void MainWindow::on_FigurePushButton_clicked()
{
    _plotWindow->show();
}

