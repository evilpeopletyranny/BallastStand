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

void AlgorithmCore::greedyAlgorihtm(double load, QList<Resistor *> list)
{
    if (list.isEmpty()) return;

    double smallestConsumption = list.last()->getPower();

    for(auto item: list)
    {
        if (item->getPower() <= load || abs(load-item->getPower()) <= smallestConsumption/2.0)
        {
            item->activate();
            load -= item->getPower();
        }
    }
}

void AlgorithmCore::startAlgorithm()
{
    auto list = dataHandler->getBallastResisterList();
    qDebug() << "AlgorithmCore: start greedyAlgorihtm. List size =" << list.size();

    greedyAlgorihtm(dataHandler->getLoad(), list);

    qDebug() << "AlgorithmCore: complete greedyAlgorihtm";
    emit algorithComplete();
}
