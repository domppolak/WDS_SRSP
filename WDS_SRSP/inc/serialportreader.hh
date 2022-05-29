#ifndef SERIALPORTREADER_HH
#define SERIALPORTREADER_HH

#include <QObject>
#include <QSerialPort>
#include <QString>
#include <QSettings>
#include <QMutex>

#include "memsdata.hh"


class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QObject *parent = nullptr);
    ~SerialPortReader();

    bool getPortOpened() const { return this->_portOpened; }
    QSettings* getSerialSettings() const { return this->_serialSettings; }
    void setPortOpened(const bool &state) {this->_portOpened = state; }

    void readData();

signals:
    void newData(rawData Data);
    void portOpened();
    void portClosed();
    void portError(QString errorMessage);
    void finished();

public slots:
    void openSerialPort();
    void closeSerialPort();
    int readDataFromSerial();
    void serialErrorHandler(QSerialPort::SerialPortError errorMessage);

private:
    QSerialPort *_serialPort = nullptr;
    QSettings *_serialSettings;
    QMutex _mutex;

    bool _portOpened = false;
};

#endif // COMMUNICATION_HH
