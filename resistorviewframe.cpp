#include "resistorviewframe.h"
#include "ui_resistorviewframe.h"

ResistorViewFrame::ResistorViewFrame(int number, Resistor *resistor, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ResistorViewFrame)
{
    ui->setupUi(this);

    ui->numberLabel->setText(QString::number(number));
    ui->consumptionLabel->setText(QString::number(resistor->getConsumption()));
    ui->percentLabel->setText(QString::number(resistor->getPercent()));
}

ResistorViewFrame::~ResistorViewFrame()
{
    delete ui;
}
