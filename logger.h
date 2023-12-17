#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include "data_payload.h"
#include <QThread>
#include "serialconnector.h"
class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);
public slots:
    void logData(Payload* data);
signals:
};

#endif // LOGGER_H
