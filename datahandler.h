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

    QList<Resistor*> activeResisterList;
    QList<Resistor*> ballastResisterList;

    double activeSum = 0.0;
    double load = 0.0;
    double ballastSum = 0.0;

    double percentage(double a, double b);

    void calculateActiveSum(const QList<std::pair<double, bool>> &activeResistorValueList);
    void calculateBallastSum(const QList<double> &ballastResisterValueList);

    void clearActiveResistorList();
    void clearBallastResistorList();

    void sortActiveResistorList();
    void sortBallastResistorList();

    void calculateLoad();

public:
    static DataHandler *getInstance();

    const QList<Resistor *> &getActiveResisterList() const;
    void setActiveResisterList(const QList<std::pair<double, bool>> &newActiveResisterList);
    void addActiveResistor(Resistor *resistor);

    const QList<Resistor *> &getBallastResisterList() const;
    void setBallastResisterList(const QList<double> &newBallastResisterList);
    void addBallastResistor(Resistor *resistor);

    double getActiveSum() const;

    double getBallastSum() const;

    double getLoad() const;

public slots:
    void receiveActiveResisterList(const QList<std::pair<double, bool>> &activeResistorValueList);
    void receiveBallastResisterList(const QList<double> &ballastResisterValueList);

signals:
    void ballastResistorListProcessed();
    void activeResistorListProcessed();
};

#endif // DATAHANDLER_H
