#ifndef RECEIVERTHREAD_H
#define RECEIVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QWaitCondition>
#include "serialportreader.hh"

class ReceiverThread : public QThread
{
    Q_OBJECT

public:
    ReceiverThread(SerialPortReader *reader);

signals:
    void threadError(QString errorMessage);

public slots:
    void onPortOpened();
    void _finished();
    void _terminate();

private:
    void run() override;

    SerialPortReader *_portReader;
    QWaitCondition m_cond;
};

#endif // RECEIVERTHREAD_H
