#ifndef SERIALCONNECTOR_H
#define SERIALCONNECTOR_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QThread>
#include <QElapsedTimer>
#include <QStringList>
#include <QDateTime>
#include <QString>
#include <QFile>

#include <data_payload.h>

class SerialConnector : public QObject
{
    Q_OBJECT
public:
    static SerialConnector* serialConnector;
    static SerialConnector* getInstance(QString name, QObject *parent = nullptr);
    static SerialConnector* getInstance();
    explicit SerialConnector(QString name, QObject *parent = nullptr);
    QSerialPort* arduino;
    QFile *logFile;
    int writeToChanel(char* data,int64_t size = -1);
    int sendRequest();
    template <typename T>int writeToChanel(T data);
    void forceDisconnect();
    QElapsedTimer* timer;
public slots:
    void gotNewData();
    void disconnectForced();
    void requestSlot();
signals:
    void payloadArrived(Payload* data);
    void disconnect();
    void requestSignal();
};

#endif // SERIALCONNECTOR_H
