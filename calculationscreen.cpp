#include "calculationscreen.h"
#include "ui_calculationscreen.h"

CalculationScreen::CalculationScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationScreen)
{
    ui->setupUi(this);

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
    utilityResistorList = dataHandler->getActiveResisterList();
}

void CalculationScreen::redrawResistorLists()
{
    redrawBallastResistorList();
    redrawUtilityResistorList();
}

void CalculationScreen::redrawBallastResistorList()
{
    QListIterator<Resistor *> iter(ballastResistorList);
    for(int i = 1; iter.hasNext(); i++) drawBallastResistor(i, iter.next());
}

void CalculationScreen::drawBallastResistor(int number, Resistor *resistor)
{
    ui->ballastVLayout->insertWidget(0, new ResistorViewFrame(number, resistor, this));
}

void CalculationScreen::redrawUtilityResistorList()
{
    QListIterator<Resistor *> iter(utilityResistorList);
    for(int i = 1; iter.hasNext(); i++) drawUtilityResistor(i, iter.next());
}

void CalculationScreen::drawUtilityResistor(int number, Resistor *resistor)
{
    ui->utilityVLayout->insertWidget(0, new ResistorViewFrame(number, resistor, this));
}
