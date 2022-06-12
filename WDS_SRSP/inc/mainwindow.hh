#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include "memsdata.hh"
#include "settingwindow.hh"
#include "serialportreader.hh"
#include "plotwindow.hh"
#include "receiverthread.hh"
#include "scene.hh"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void startSimulation();
    void stopSimulation();
    void resetSimulation();
    void obstacleON();
    void obstacleOFF();
    void constSpeed();
    void variableSpeed();

private slots:
    // button slots
    void on_ResetPushButton_clicked();
    void on_StopPushButton_clicked();
    void on_StartPushButton_clicked();
    void on_FigurePushButton_clicked();

    // check box slots
    void on_ObstacleCheckBox_stateChanged(int arg1);
    void on_SpeedCheckBox_stateChanged(int arg1);

    // Menu bar slots
    void on_connectAction_triggered();
    void on_disconnectAction_triggered();
    void on_settingAction_triggered();

    void on_serial_port_opened();
    void on_serial_port_closed();
    void ErrorHandler(QString);

    void greenLed();
    void redLed();

private:

    Ui::MainWindow *ui;
    SettingWindow *_sWindow;
    SerialPortReader *_portReader;
    PlotWindow *_plotWindow;
    ReceiverThread *_receiverThread;
    Scene *_scene;

    void setupScene();

    //ObjectWidget *_sceneWidget;
    QSettings *setting;
};
#endif // MAINWINDOW_H
