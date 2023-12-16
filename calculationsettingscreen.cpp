#include "calculationsettingscreen.h"
#include "ui_calculationsettingscreen.h"

CalculationSettingScreen::CalculationSettingScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationSettingScreen)
{
    ui->setupUi(this);
    dataHandler = DataHandler::getInstance();

    connect(this, &CalculationSettingScreen::sendUtilityResistorValueList, dataHandler, &DataHandler::receiveUtiltiyResisterList);
    connect(this, &CalculationSettingScreen::sendBallastResistorsValueList, dataHandler, &DataHandler::receiveBallastResisterList);
}

CalculationSettingScreen::~CalculationSettingScreen()
{
    delete ui;
}

void CalculationSettingScreen::on_utilityAddButton_clicked()
{
    auto *layout = ui->utilityVLayout;
    layout->insertWidget(layout->count() - 1, new UtilityResistorInputFrame());
}


void CalculationSettingScreen::on_ballastAddButton_clicked()
{
    auto *layout = ui->ballastVLayout;
    layout->insertWidget(layout->count() - 1, new BallastResistorInputFrame());
}

void CalculationSettingScreen::rebuildResistors()
{
    emit sendUtilityResistorValueList(getUtilityResistorValueList());
    emit sendBallastResistorsValueList(getBallastResistorValueList());
}

QList<std::pair<double, bool>> CalculationSettingScreen::getUtilityResistorValueList()
{
    QList<std::pair<double, bool>> list;
    for(auto *item: ui->utilityAreaContent->findChildren<UtilityResistorInputFrame *>())
    {
        list.append(
                    {item->getConsumptionValue(), item->getStatus()}
        );
    }

    qDebug() << "CalculationSettingScreen: считаны данные о полезных резситорах.";

    return list;
}

QList<double> CalculationSettingScreen::getBallastResistorValueList()
{
    QList<double> list;
    for(auto *item: ui->ballastAreaContent->findChildren<BallastResistorInputFrame *>())
    {
        list.append(item->getConsumptionValue());
    }

    qDebug() << "CalculationSettingScreen: считаны данные о балластных резситорах.";

    return list;
}
