#include "utilityresistorinputframe.h"
#include "ui_utilityresistorinputframe.h"

UtilityResistorInputFrame::UtilityResistorInputFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::UtilityResistorInputFrame)
{
    ui->setupUi(this);
    changeStatus();
}

UtilityResistorInputFrame::~UtilityResistorInputFrame()
{
    delete ui;
}

void UtilityResistorInputFrame::on_statusCheckBox_clicked()
{
    changeStatus();
}

void UtilityResistorInputFrame::changeStatus()
{
    switch (ui->statusCheckBox->checkState()) {
        case Qt::Checked:
            setActiveState();
            break;

        case Qt::Unchecked:
            setDeactiveState();
            break;
    }
}

void UtilityResistorInputFrame::setActiveState()
{
    setActiveColor();
    setActiveLabel();
}

void UtilityResistorInputFrame::setActiveColor()
{
    const QString color = "QFrame#UtilityResistorInputFrame {background-color: rgb(51, 209, 122);};";
    this->setStyleSheet(color);
}

void UtilityResistorInputFrame::setActiveLabel()
{
    const QString label = "Вкл";
    ui->statusLabel->setText(label);
}

void UtilityResistorInputFrame::setDeactiveState()
{
    setDeactiveColor();
    setDeactieLabel();
}

void UtilityResistorInputFrame::setDeactiveColor()
{
    const QString color = "QFrame#UtilityResistorInputFrame {background-color: rgb(246, 97, 81);};";
    this->setStyleSheet(color);
}

void UtilityResistorInputFrame::setDeactieLabel()
{
    const QString label = "Выкл";
    ui->statusLabel->setText(label);
}

double UtilityResistorInputFrame::getConsumptionValue()
{
    return ui->consumptionSpinBox->value();
}

bool UtilityResistorInputFrame::getStatus()
{
    return ui->statusCheckBox->checkState() == Qt::Checked;
}
