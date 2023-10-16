#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QDebug>

#include "resistor.h"

class DataHandler : public QObject
{
    Q_OBJECT
private:
    explicit DataHandler(QObject *parent = nullptr);

    static DataHandler *instance;

    QList<Resistor*> activeResisterList;
    QList<Resistor*> ballastResisterList;

public:
    static DataHandler *getInstance();

    const QList<Resistor *> &getActiveResisterList() const;

    void addActiveResistor(Resistor *resistor);

    const QList<Resistor *> &getBallastResisterList() const;

    void addBallastResistor(Resistor *resistor);

public slots:
    void setActiveResisterList(const QList<Resistor *> &newActiveResisterList);

    void setBallastResisterList(const QList<Resistor *> &newBallastResisterList);
};

#endif // DATAHANDLER_H
