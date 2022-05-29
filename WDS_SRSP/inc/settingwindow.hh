#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingWindow(QSettings *serial_settings, QWidget *parent = nullptr);
    ~SettingWindow();
    void update();

signals:
    void connectToSerialPort();
    void disconectFromSerialPort();

private slots:
    void on_serialPortComboBox_currentIndexChanged(int index);
    void on_applyButton_clicked();
    void on_disconnectButton_clicked();
    void on_connectButton_clicked();

private:
    void updateSerialSettings();
    void fillSerialPortsInfo();
    void fillSerialPortParameters();
    void showPortInfo(int index);

    void fillBaudRateParameters();
    void fillWordLengthParameters();
    void fillParityParameters();
    void fillStopBitsParameters();
    void setCurrentIndexes();

    Ui::SettingWindow *_ui;
    QSettings *_serialSettings;



};

#endif // SETTINGSWINDOW_H
