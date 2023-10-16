#include "datahandler.h"

DataHandler *DataHandler::instance = nullptr;

DataHandler::DataHandler(QObject *parent)
    : QObject{parent}
{

}

void DataHandler::setBallastResisterList(const QList<Resistor *> &newBallastResisterList)
{
    ballastResisterList = newBallastResisterList;
    qDebug() << "DataHandler::setBallastResisterList" << newBallastResisterList.size();
}

void DataHandler::setActiveResisterList(const QList<Resistor *> &newActiveResisterList)
{
    activeResisterList = newActiveResisterList;
    qDebug() << "DataHandler::setActiveResisterList" << newActiveResisterList.size();
}

const QList<Resistor *> &DataHandler::getBallastResisterList() const
{
    return ballastResisterList;
}

const QList<Resistor *> &DataHandler::getActiveResisterList() const
{
    return activeResisterList;
}

void DataHandler::addActiveResistor(Resistor* resistor)
{
    activeResisterList.append(resistor);
}

DataHandler *DataHandler::getInstance()
{
    if (DataHandler::instance == nullptr) DataHandler::instance = new DataHandler();
    return DataHandler::instance;
}
