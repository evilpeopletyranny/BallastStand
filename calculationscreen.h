#ifndef CALCULATIONSCREEN_H
#define CALCULATIONSCREEN_H

#include <QWidget>
#include <QList>

#include "resistorviewframe.h"
#include "algorithmcore.h"
#include "datahandler.h"

namespace Ui {
class CalculationScreen;
}

class CalculationScreen : public QWidget
{
    Q_OBJECT

public:
    explicit CalculationScreen(QWidget *parent = nullptr);
    ~CalculationScreen();

private:
    Ui::CalculationScreen *ui;

    DataHandler *dataHandler;
    AlgorithmCore *algorithmCore;

    QList<Resistor *> ballastResistorList;
    QList<Resistor *> utilityResistorList;

    void initExternalEntities();
    void initConnections();

    void drawBallastResistor(int number, Resistor *resistor);
    void drawUtilityResistor(int number, Resistor *resistor);

    void redrawResistorLists();
    void redrawBallastResistorList();
    void redrawUtilityResistorList();

    void refreshResistorLists();
    void refreshBallastResistorList();
    void refreshUtilityResistorList();

private slots:
    void receiverAlgorithmCompleteSignal();
};

#endif // CALCULATIONSCREEN_H
