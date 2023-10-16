#include "calculationsettingscreen.h"
#include "ui_calculationsettingscreen.h"

CalculationSettingScreen::CalculationSettingScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationSettingScreen)
{
    ui->setupUi(this);
    dataHandler = DataHandler::getInstance();

    connect(this, &CalculationSettingScreen::newActiveResistorsFound, dataHandler, &DataHandler::setActiveResisterList);
    connect(this, &CalculationSettingScreen::newBallastResistorsFound, dataHandler, &DataHandler::setBallastResisterList);
}

CalculationSettingScreen::~CalculationSettingScreen()
{
    delete ui;
}

void CalculationSettingScreen::on_activeAddButton_clicked()
{
    ui->activeVLayout->insertWidget(0, new ResistorInputFrame());
}


void CalculationSettingScreen::on_ballastAddButton_clicked()
{
    ui->ballastVLayout->insertWidget(0, new ResistorInputFrame());
}

void CalculationSettingScreen::on_acceptButton_clicked()
{
    newResistorsFound();
}

void CalculationSettingScreen::newResistorsFound()
{
    emit newActiveResistorsFound(getActiveResistorList());
    emit newBallastResistorsFound(getBallastResistorList());
}

QList<Resistor *> CalculationSettingScreen::getActiveResistorList()
{
    QList<Resistor *> list;
    for(auto *item: ui->activeAreaContent->findChildren<ResistorInputFrame *>())
    {
        list.append(item->getResistor());
    }
    return list;
}

QList<Resistor *> CalculationSettingScreen::getBallastResistorList()
{
    QList<Resistor *> list;
    for(auto *item: ui->ballastAreaContent->findChildren<ResistorInputFrame *>())
    {
        list.append(item->getResistor());
    }
    return list;
}
