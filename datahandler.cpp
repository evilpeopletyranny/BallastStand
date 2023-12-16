#include "datahandler.h"

bool compareResistors(const Resistor *res1, const Resistor *res2)
{
    return (res1->getPower() > res2->getPower());
}

DataHandler *DataHandler::instance = nullptr;

DataHandler::DataHandler(QObject *parent)
    : QObject{parent}
{

}

void DataHandler::setBallastResisterList(const QList<Resistor *> &newBallastResisterList)
{
    ballastResisterList = newBallastResisterList;
}

double DataHandler::getActiveBallastSum() const
{
    return activeBallastSum;
}

double DataHandler::getConsumptionDiff()
{
    return utilitySum - activeBallastSum;
}

double DataHandler::getPercentDiff()
{
    return 100.0 - (activeUtilityPercentSum + activeBallastPercentSum);
}

double DataHandler::getActiveUtilitySum() const
{
    return activeUtilitySum;
}

double DataHandler::getActiveBallastPercentSum() const
{
    return activeBallastPercentSum;
}

double DataHandler::getActiveUtilityPercentSum() const
{
    return activeUtilityPercentSum;
}

double DataHandler::getLoad() const
{
    return load;
}

double DataHandler::getBallastSum() const
{
    return ballastSum;
}

double DataHandler::getUtiltiySum() const
{
    return utilitySum;
}

void DataHandler::setBallastResisterDataList(const QList<double> &newBallastResisterList)
{
    QList<Resistor *> list;
    for (auto value: newBallastResisterList) list.append(new Resistor(value, percentage(value, utilitySum), false));
    ballastResisterList = list;
}

void DataHandler::setUtilityResisterDataList(const QList<std::pair<double, bool>> &newUtiityResisterList)
{
    QList<Resistor *> list;
    for (auto item: newUtiityResisterList) list.append(new Resistor(item.first, percentage(item.first, utilitySum), item.second));
    utilityResisterList = list;
}

double DataHandler::percentage(double a, double b)
{
    return a/b*100.0;
}

void DataHandler::calculateUtilitySum()
{
    double temp = 0.0;
    for(auto item: utilityResisterList) temp += item->getPower();
    utilitySum = temp;
}

void DataHandler::calculateBallastSum()
{
    double temp = 0.0;
    for(auto item: ballastResisterList) temp += item->getPower();
    ballastSum = temp;
}

void DataHandler::calculateActiveResistorSums()
{
    qDebug() << "DataHandler: высчитывание суммы активных полезных и балластных резисторов.";

    calculateActiveUtilitySum();
    calculateActiveBallastSum();
}

void DataHandler::calculateActiveUtilitySum()
{
    double temp = 0.0;
    for (auto item: utilityResisterList)
    {
        if (item->isActive()) temp += item->getPower();
    }
    activeUtilitySum = temp;

    qDebug() << "DataHandler: сумма активных полезных резисторов =" << activeUtilitySum;
}

void DataHandler::calculateActiveBallastSum()
{
    double temp = 0.0;
    for (auto item: ballastResisterList)
    {
        if (item->isActive()) temp += item->getPower();
    }
    activeBallastSum = temp;

    qDebug() << "DataHandler: сумма активных балластных резисторов =" << activeBallastSum;
}

void DataHandler::calculateActiveResistorPercentSums()
{
    qDebug() << "DataHandler: высчитывание суммы процентов активных полезных и балластных резисторов.";
    calcualteActiveUtilityPercentSum();
    calculateActiveBallastPercentSum();
}

void DataHandler::calcualteActiveUtilityPercentSum()
{
    double temp = 0.0;
    for (auto item: utilityResisterList)
    {
        if (item->isActive()) temp += item->getPercent();
    }
    activeUtilityPercentSum = temp;

    qDebug() << "DataHandler: сумма процентов активных полезных резисторов =" << activeUtilityPercentSum;
}

void DataHandler::calculateActiveBallastPercentSum()
{
    double temp = 0.0;
    for (auto item: ballastResisterList)
    {
        if (item->isActive()) temp += item->getPercent();
    }
    activeBallastPercentSum = temp;

    qDebug() << "DataHandler: сумма процентов активных балластных резисторов =" << activeBallastPercentSum;
}

void DataHandler::sortUtilityResistorList()
{
    std::sort(utilityResisterList.begin(), utilityResisterList.end(), compareResistors);
}

void DataHandler::sortBallastResistorList()
{
    std::sort(ballastResisterList.begin(), ballastResisterList.end(), compareResistors);
}

void DataHandler::calculateLoad()
{
    load = 0.0;
    for (auto *item: utilityResisterList)
    {
        if (item->isActive()) load += item->getPower();
    }
    qDebug() << "DataHandler: включенная активная нагрузка =" << load << "kOm";
}

void DataHandler::receiveBallastResisterList(const QList<double> &newBallastResisterList)
{
    qDebug() << "DataHandler: Кол-во резисторов балластной нагрузки:" << newBallastResisterList.size();

    setBallastResisterDataList(newBallastResisterList);
    calculateBallastSum();
    sortBallastResistorList();

    qDebug() << "DataHandler: Сумма балластных резисторов:" << ballastSum << "kOm";

    emit ballastResistorListProcessed();
}

void DataHandler::calculationAfterAlgorithm()
{
    calculateActiveResistorSums();
    calculateActiveResistorPercentSums();
    emit calculationsAfterAlgorithmProceed();
}

void DataHandler::receiveUtiltiyResisterList(const QList<std::pair<double, bool>> &newUtiltiyResisterList)
{
    qDebug() << "DataHandler: Кол-во резисторов активной нагрузки:" << newUtiltiyResisterList.size();

    double temp = 0.0;
    for (auto item: newUtiltiyResisterList) temp += item.first;

    utilitySum = temp;

    setUtilityResisterDataList(newUtiltiyResisterList);
    calculateUtilitySum();
    sortUtilityResistorList();
    calculateLoad();

    qDebug() << "DataHandler: Сумма активных резисторов:" << utilitySum << "kOm";
}

const QList<Resistor *> &DataHandler::getBallastResisterList() const
{
    return ballastResisterList;
}

const QList<Resistor *> &DataHandler::getUtilityResisterList() const
{
    return utilityResisterList;
}

void DataHandler::addUtilityResistor(Resistor* resistor)
{
    utilityResisterList.append(resistor);
}

DataHandler *DataHandler::getInstance()
{
    if (DataHandler::instance == nullptr) DataHandler::instance = new DataHandler();
    return DataHandler::instance;
}
