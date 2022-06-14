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

enum Language{pl_PL, en_EN};

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
    void on_polishAction_triggered();
    void on_englishAction_triggered();

    void on_serial_port_opened();
    void on_serial_port_closed();
    void ErrorHandler(QString);

    void greenLed();
    void redLed();

    void on_SpeedSpinBox_valueChanged(int arg1);



private:
    void setupScene();
    void setConnections();
    void setupSpeedSpinBox();
    int changeLanguage(Language lang);
    void retranslate();

    Ui::MainWindow *ui;
    SettingWindow *_sWindow;
    SerialPortReader *_portReader;
    PlotWindow *_plotWindow;
    ReceiverThread *_receiverThread;
    Scene *_scene;
    //QTranslator *engTranslate;
    QTranslator *_translator;
};
#endif // MAINWINDOW_H
