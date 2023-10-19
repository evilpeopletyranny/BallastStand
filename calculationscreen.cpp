#include "calculationscreen.h"
#include "ui_calculationscreen.h"

CalculationScreen::CalculationScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationScreen)
{
    ui->setupUi(this);

    dataHandler = DataHandler::getInstance();
    algorithmCore = AlgorithmCore::getInstance();

    connect(algorithmCore, &AlgorithmCore::algorithComplete, this, &CalculationScreen::redrawBallastResistorList);
}

CalculationScreen::~CalculationScreen()
{
    delete ui;
}

void CalculationScreen::drawBallastResistor(int number, Resistor *resistor)
{
    ui->ballastVLayout->addWidget(new ResistorViewFrame(number, resistor, this));
}

void CalculationScreen::redrawBallastResistorList()
{
    auto list = dataHandler->getBallastResisterList();

    QListIterator<Resistor *> iter(list);
    for(int i = 1; iter.hasNext(); i++) drawBallastResistor(i, iter.next());
}
