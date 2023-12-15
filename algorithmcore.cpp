#include "algorithmcore.h"

AlgorithmCore *AlgorithmCore::instance = nullptr;

AlgorithmCore::AlgorithmCore(QObject *parent)
    : QObject{parent}
{
    initExternalEntities();
    initConnections();
}

void AlgorithmCore::initExternalEntities()
{
    dataHandler = DataHandler::getInstance();
}

void AlgorithmCore::initConnections()
{
    connect(dataHandler, &DataHandler::ballastResistorListProcessed, this, &AlgorithmCore::startAlgorithm);
    connect(this, &AlgorithmCore::algorithComplete, dataHandler, &DataHandler::calculationAfterAlgorithm);
}

AlgorithmCore *AlgorithmCore::getInstance()
{
    if (AlgorithmCore::instance == nullptr) AlgorithmCore::instance = new AlgorithmCore();
    return AlgorithmCore::instance;
}

QList<Resistor *> AlgorithmCore::greedyAlgorihtm(double load, QList<Resistor *> list)
{
    QList<Resistor *> res;
    if (list.isEmpty()) return res;

    double smallestConsumption = list.first()->getPower();
    for(auto item: list)
    {
        if (item->getPower() <= load || abs(load-item->getPower()) <= smallestConsumption/2.0)
        {
            res.append(new Resistor(item->getPower(), item->getPercent(), true));
            load -= item->getPower();
        }
        else
        {
            res.append(new Resistor(item->getPower(), item->getPercent(), false));
        }
    }

    return res;
}

void AlgorithmCore::startAlgorithm()
{
    auto list = dataHandler->getBallastResisterList();
    qDebug() << "AlgorithmCore: start greedyAlgorihtm. List size =" << list.size();

    dataHandler->setBallastResisterList(greedyAlgorihtm(100.0 - dataHandler->getLoad(), list));

    qDebug() << "AlgorithmCore: complete greedyAlgorihtm";
    emit algorithComplete();
}
