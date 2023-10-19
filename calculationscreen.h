#ifndef CALCULATIONSCREEN_H
#define CALCULATIONSCREEN_H

#include <QWidget>

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

    void drawBallastResistor(int number, Resistor *resistor);

private slots:
    void redrawBallastResistorList();
};

#endif // CALCULATIONSCREEN_H
