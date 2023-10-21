#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QDebug>
#include <algorithm>

#include "resistor.h"

class DataHandler : public QObject
{
    Q_OBJECT
private:
    explicit DataHandler(QObject *parent = nullptr);

    static DataHandler *instance;

    QList<Resistor*> utilityResisterList;
    QList<Resistor*> ballastResisterList;

    double load = 0.0;

    double utilitySum = 0.0;
    double ballastSum = 0.0;

    double activeUtilitySum = 0.0;
    double activeBallastSum = 0.0;

    double activeUtilityPercentSum = 0.0;
    double activeBallastPercentSum = 0.0;

    double percentage(double a, double b);

    void calculateUtilitySum();
    void calculateBallastSum();

    void calculateActiveResistorSums();
    void calculateActiveUtilitySum();
    void calculateActiveBallastSum();

    void calculateActiveResistorPercentSums();
    void calcualteActiveUtilityPercentSum();
    void calculateActiveBallastPercentSum();

    void sortUtilityResistorList();
    void sortBallastResistorList();

    void calculateLoad();

public:
    static DataHandler *getInstance();

    const QList<Resistor *> &getUtilityResisterList() const;
    void setUtilityResisterList(const QList<std::pair<double, bool>> &newUtilityResisterList);
    void addUtilityResistor(Resistor *resistor);

    const QList<Resistor *> &getBallastResisterList() const;
    void setBallastResisterList(const QList<double> &newBallastResisterList);
    void addBallastResistor(Resistor *resistor);

    double getUtiltiySum() const;

    double getBallastSum() const;

    double getLoad() const;

    double getActiveUtilityPercentSum() const;

    double getActiveBallastPercentSum() const;

    double getActiveUtilitySum() const;

    double getActiveBallastSum() const;

    double getConsumptionDiff();
    double getPercentDiff();

public slots:
    void receiveUtiltiyResisterList(const QList<std::pair<double, bool>> &utilityResistorValueList);
    void receiveBallastResisterList(const QList<double> &ballastResisterValueList);

    void calculationAfterAlgorithm();

signals:
    void ballastResistorListProcessed();
    void utilityResistorListProcessed();
    void calculationsAfterAlgorithmProceed();
};

#endif // DATAHANDLER_H
