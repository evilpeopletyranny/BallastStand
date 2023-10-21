#ifndef ALGORITHMCORE_H
#define ALGORITHMCORE_H

#include <QObject>
#include <QList>
#include <QDebug>

#include "resistor.h"
#include "datahandler.h"

class AlgorithmCore : public QObject
{
    Q_OBJECT

private:
    explicit AlgorithmCore(QObject *parent = nullptr);
    static AlgorithmCore *instance;

    DataHandler *dataHandler;

    void initExternalEntities();
    void initConnections();

    void greedyAlgorihtm(double load, QList<Resistor *> list);

public:
    static AlgorithmCore *getInstance();

public slots:
    void startAlgorithm();


signals:
    void algorithComplete();

};

#endif // ALGORITHMCORE_H
