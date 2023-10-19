#include "calculationsettingscreen.h"
#include "ui_calculationsettingscreen.h"

CalculationSettingScreen::CalculationSettingScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationSettingScreen)
{
    ui->setupUi(this);
    dataHandler = DataHandler::getInstance();

    connect(this, &CalculationSettingScreen::sendActiveResistorValueList, dataHandler, &DataHandler::receiveActiveResisterList);
    connect(this, &CalculationSettingScreen::sendBallastResistorsValueList, dataHandler, &DataHandler::receiveBallastResisterList);
}

CalculationSettingScreen::~CalculationSettingScreen()
{
    delete ui;
}

void CalculationSettingScreen::on_activeAddButton_clicked()
{
    ui->activeVLayout->insertWidget(0, new ActiveResistorInputFrame());
}


void CalculationSettingScreen::on_ballastAddButton_clicked()
{
    ui->ballastVLayout->insertWidget(0, new BallastResistorInputFrame());
}

void CalculationSettingScreen::rebuildResistors()
{

    emit sendActiveResistorValueList(getActiveResistorValueList());
    emit sendBallastResistorsValueList(getBallastResistorValueList());
}

QList<std::pair<double, bool>> CalculationSettingScreen::getActiveResistorValueList()
{
    QList<std::pair<double, bool>> list;
    for(auto *item: ui->activeAreaContent->findChildren<ActiveResistorInputFrame *>())
    {
        list.append(
                    {item->getConsumptionValue(), item->getStatus()}
        );
    }
    return list;
}

QList<double> CalculationSettingScreen::getBallastResistorValueList()
{
    QList<double> list;
    for(auto *item: ui->ballastAreaContent->findChildren<BallastResistorInputFrame *>())
    {
        list.append(item->getConsumptionValue());
    }
    return list;
}
