#include "calculationscreen.h"
#include "ui_calculationscreen.h"

CalculationScreen::CalculationScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationScreen)
{
    ui->setupUi(this);

    windowManager = WindowManager::getInstance();

    initExternalEntities();
    initConnections();
}

CalculationScreen::~CalculationScreen()
{
    delete ui;
}

void CalculationScreen::initExternalEntities()
{
    dataHandler = DataHandler::getInstance();
    algorithmCore = AlgorithmCore::getInstance();
}

void CalculationScreen::initConnections()
{
    connect(algorithmCore, &AlgorithmCore::algorithComplete, this, &CalculationScreen::receiverAlgorithmCompleteSignal);
    connect(dataHandler, &DataHandler::calculationsAfterAlgorithmProceed, this, &CalculationScreen::fillCentralWidget);
}

void CalculationScreen::receiverAlgorithmCompleteSignal()
{
    refreshResistorLists();
    redrawResistorLists();
}

void CalculationScreen::refreshResistorLists()
{
    refreshBallastResistorList();
    refreshUtilityResistorList();
}

void CalculationScreen::refreshBallastResistorList()
{
    ballastResistorList = dataHandler->getBallastResisterList();
}

void CalculationScreen::refreshUtilityResistorList()
{
    utilityResistorList = dataHandler->getUtilityResisterList();
}

void CalculationScreen::fillUtilityLoadFrame()
{
    ui->utilitySumLabel->setText(QString::number(dataHandler->getUtiltiySum(), 'f', 3));
    ui->activeUtilitySumLabel->setText(QString::number(dataHandler->getActiveUtilitySum(), 'f', 3));
    ui->activeUtilityPercentLabel->setText(QString::number(dataHandler->getActiveUtilityPercentSum(), 'f', 2));
}

void CalculationScreen::fillDiffLoadFrame()
{
    ui->diffLabel->setText(QString::number(dataHandler->getConsumptionDiff(), 'f', 3));
    ui->percentDiffLabel->setText(QString::number(dataHandler->getPercentDiff(), 'f', 2));
}

void CalculationScreen::fillBallastLoadFrame()
{
    ui->ballastSumLabel->setText(QString::number(dataHandler->getBallastSum(), 'f', 3));
    ui->activeBallastSumLabel->setText(QString::number(dataHandler->getActiveBallastSum(), 'f', 3));
    ui->activeBallastPercentLabel->setText(QString::number(dataHandler->getActiveBallastPercentSum(), 'f', 2));
}

void CalculationScreen::redrawResistorLists()
{
    clearAreas();
    drawBallastResistorList();
    drawUtilityResistorList();
}

void CalculationScreen::drawBallastResistorList()
{
    QListIterator<Resistor *> iter(ballastResistorList);
    for(int i = 1; iter.hasNext(); i++) drawBallastResistor(i, iter.next());
}

void CalculationScreen::drawBallastResistor(int number, Resistor *resistor)
{
    auto layout = ui->ballastVLayout;
    layout->insertWidget(layout->count()-1, new ResistorViewFrame(number, resistor, this));
}

void CalculationScreen::drawUtilityResistorList()
{
    QListIterator<Resistor *> iter(utilityResistorList);
    for(int i = 1; iter.hasNext(); i++) drawUtilityResistor(i, iter.next());
}

void CalculationScreen::drawUtilityResistor(int number, Resistor *resistor)
{
    auto layout = ui->utilityVLayout;
    layout->insertWidget(layout->count()-1, new ResistorViewFrame(number, resistor, this));
}

void CalculationScreen::clearAreas()
{
    clearBallastArea();
    clearUtilityArea();
}

void CalculationScreen::clearBallastArea()
{
    for (auto *item: ui->ballastAreaContent->findChildren<ResistorViewFrame *>()) delete item;
}

void CalculationScreen::clearUtilityArea()
{
    for (auto *item: ui->utilityAreaContent->findChildren<ResistorViewFrame *>()) delete item;
}

void CalculationScreen::redrawOnlyActiveResistorLists()
{
    clearAreas();
    drawOnlyActiveBallastRessitorList();
    drawOnlytActiveUtilityResistorList();
}

void CalculationScreen::drawOnlyActiveBallastRessitorList()
{
    QListIterator<Resistor *> iter(ballastResistorList);
    for(int i = 1; iter.hasNext(); i++) {
        auto *item = iter.next();
        if (item->isActive()) drawBallastResistor(i, item);
    }
}

void CalculationScreen::drawOnlytActiveUtilityResistorList()
{
    QListIterator<Resistor *> iter(utilityResistorList);
    for(int i = 1; iter.hasNext(); i++) {
        auto *item = iter.next();
        if (item->isActive()) drawUtilityResistor(i, item);
    }
}

void CalculationScreen::fillCentralWidget()
{
    fillUtilityLoadFrame();
    fillDiffLoadFrame();
    fillBallastLoadFrame();
}

void CalculationScreen::on_showActiveCheckBox_clicked()
{
    switch (ui->showActiveCheckBox->checkState()) {
        case Qt::Checked:
            redrawOnlyActiveResistorLists();
            break;

        case Qt::Unchecked:
            redrawResistorLists();
            break;
    }
}

void CalculationScreen::on_tableButton_clicked()
{
    windowManager->showTableWidget(this);
}

