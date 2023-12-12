#include "resistorviewframe.h"
#include "ui_resistorviewframe.h"

ResistorViewFrame::ResistorViewFrame(int number, Resistor *resistor, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ResistorViewFrame)
{
    ui->setupUi(this);

    QLocale ru(QLocale::Russian);

    ui->numberLabel->setText(QString::number(number));
    ui->consumptionLabel->setText(QString::number(resistor->getPower(), 'f', 3));
    ui->percentLabel->setText(QString::number(resistor->getPercent(), 'f', 2));
    changeStatus(resistor->isActive());
}

ResistorViewFrame::~ResistorViewFrame()
{
    delete ui;
}

void ResistorViewFrame::changeStatus(bool active)
{
    switch (active) {
        case true:
            setActiveColor();
            break;
        case false:
            setDeactiveColor();
            break;
    }
}

void ResistorViewFrame::setActiveColor()
{
    const QString color = "QFrame#ResistorViewFrame {background-color: rgb(51, 209, 122);};";
    this->setStyleSheet(color);
}

void ResistorViewFrame::setDeactiveColor()
{
    const QString color = "QFrame#ResistorViewFrame {background-color: rgb(246, 97, 81);};";
    this->setStyleSheet(color);
}
