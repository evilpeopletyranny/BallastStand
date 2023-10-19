#include "datahandler.h"

bool compareResistors(const Resistor *res1, const Resistor *res2)
{
    return (res1->getConsumption() < res2->getConsumption());
}

DataHandler *DataHandler::instance = nullptr;

DataHandler::DataHandler(QObject *parent)
    : QObject{parent}
{

}

double DataHandler::getLoad() const
{
    return load;
}

double DataHandler::getBallastSum() const
{
    return ballastSum;
}

double DataHandler::getActiveSum() const
{
    return activeSum;
}

void DataHandler::setBallastResisterList(const QList<double> &newBallastResisterList)
{
    for (auto item: newBallastResisterList)
    {
        ballastResisterList.append(new Resistor(item, percentage(item, activeSum), false));
    }
}

void DataHandler::setActiveResisterList(const QList<std::pair<double, bool>> &newActiveResisterList)
{
    for (auto item: newActiveResisterList)
    {
        activeResisterList.append(new Resistor(item.first, percentage(item.first, activeSum), item.second));
    }
}

double DataHandler::percentage(double a, double b)
{
    return a/b*100.0;
}

void DataHandler::calculateActiveSum(const QList<std::pair<double, bool> > &activeResistorValueList)
{
    double temp = 0.0;
    for(auto item: activeResistorValueList)
    {
        temp += item.first;
    }
    activeSum = temp;
}

void DataHandler::calculateBallastSum(const QList<double> &ballastResisterValueList)
{
    ballastSum = std::accumulate(ballastResisterValueList.begin(), ballastResisterValueList.end(), 0.0);
}

void DataHandler::clearActiveResistorList()
{
    activeResisterList.clear();
}

void DataHandler::clearBallastResistorList()
{
    ballastResisterList.clear();
}

void DataHandler::sortActiveResistorList()
{
    std::sort(activeResisterList.begin(), activeResisterList.end(), compareResistors);
}

void DataHandler::sortBallastResistorList()
{
    std::sort(ballastResisterList.begin(), ballastResisterList.end(), compareResistors);
}

void DataHandler::calculateLoad()
{
    load = 0.0;
    for (auto *item: activeResisterList)
    {
        if (item->isActive()) load += item->getConsumption();
    }
    qDebug() << "DataHandler: включенная активная нагрузка =" << load << "kOm";
}

void DataHandler::receiveBallastResisterList(const QList<double> &newBallastResisterList)
{
    clearBallastResistorList();
    calculateBallastSum(newBallastResisterList);
    qDebug() << "DataHandler: Кол-во резисторов балластной нагрузки:" << newBallastResisterList.size();
    qDebug() << "DataHandler: Сумма балластных резисторов:" << ballastSum << "kOm";
    setBallastResisterList(newBallastResisterList);
    sortBallastResistorList();

    emit ballastResistorListProcessed();
}

void DataHandler::receiveActiveResisterList(const QList<std::pair<double, bool>> &newActiveResisterList)
{
    clearActiveResistorList();
    calculateActiveSum(newActiveResisterList);
    qDebug() << "DataHandler: Кол-во резисторов активной нагрузки:" << newActiveResisterList.size();
    qDebug() << "DataHandler: Сумма активных резисторов:" << activeSum << "kOm";
    setActiveResisterList(newActiveResisterList);
    sortActiveResistorList();
    calculateLoad();
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
