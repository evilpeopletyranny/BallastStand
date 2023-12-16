#include "ballastresistorinputframe.h"
#include "ui_ballastresistorinputframe.h"

BallastResistorInputFrame::BallastResistorInputFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::BallastResistorInputFrame)
{
    ui->setupUi(this);
}

BallastResistorInputFrame::~BallastResistorInputFrame()
{
    delete ui;
}

double BallastResistorInputFrame::getConsumptionValue()
{
    return ui->consumptionSpinBox->value();
}

void BallastResistorInputFrame::on_deleteButton_clicked()
{
    delete this;
}
