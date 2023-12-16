#ifndef CALCULATIONSCREEN_H
#define CALCULATIONSCREEN_H

#include <QWidget>
#include <QList>

#include "resistorviewframe.h"
#include "algorithmcore.h"
#include "datahandler.h"
#include "windowmanager.h"

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

    WindowManager *windowManager;

    DataHandler *dataHandler;
    AlgorithmCore *algorithmCore;

    QList<Resistor *> ballastResistorList;
    QList<Resistor *> utilityResistorList;

    void initExternalEntities();
    void initConnections();

    void drawBallastResistor(int number, Resistor *resistor);
    void drawUtilityResistor(int number, Resistor *resistor);

    void clearAreas();
    void clearBallastArea();
    void clearUtilityArea();

    void redrawOnlyActiveResistorLists();
    void drawOnlyActiveBallastRessitorList();
    void drawOnlytActiveUtilityResistorList();

    void redrawResistorLists();
    void drawBallastResistorList();
    void drawUtilityResistorList();

    void refreshResistorLists();
    void refreshBallastResistorList();
    void refreshUtilityResistorList();

    void fillUtilityLoadFrame();
    void fillDiffLoadFrame();
    void fillBallastLoadFrame();

private slots:
    void receiverAlgorithmCompleteSignal();
    void fillCentralWidget();
    void on_showActiveCheckBox_clicked();
    void on_tableButton_clicked();
};

#endif // CALCULATIONSCREEN_H
