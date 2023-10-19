#include "activeresistorinputframe.h"
#include "ui_activeresistorinputframe.h"

ActiveResistorInputFrame::ActiveResistorInputFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ActiveResistorInputFrame)
{
    ui->setupUi(this);
    changeStatus();
}

ActiveResistorInputFrame::~ActiveResistorInputFrame()
{
    delete ui;
}

void ActiveResistorInputFrame::on_statusCheckBox_clicked()
{
    changeStatus();
}

void ActiveResistorInputFrame::changeStatus()
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

void ActiveResistorInputFrame::setActiveState()
{
    setActiveColor();
    setActiveLabel();
}

void ActiveResistorInputFrame::setActiveColor()
{
    const QString color = "QFrame#ActiveResistorInputFrame {background-color: rgb(51, 209, 122);};";
    this->setStyleSheet(color);
}

void ActiveResistorInputFrame::setActiveLabel()
{
    const QString label = "Вкл";
    ui->statusLabel->setText(label);
}

void ActiveResistorInputFrame::setDeactiveState()
{
    setDeactiveColor();
    setDeactieLabel();
}

void ActiveResistorInputFrame::setDeactiveColor()
{
    const QString color = "QFrame#ActiveResistorInputFrame {background-color: rgb(246, 97, 81);};";
    this->setStyleSheet(color);
}

void ActiveResistorInputFrame::setDeactieLabel()
{
    const QString label = "Выкл";
    ui->statusLabel->setText(label);
}

double ActiveResistorInputFrame::getConsumptionValue()
{
    return ui->consumptionSpinBox->value();
}

bool ActiveResistorInputFrame::getStatus()
{
    return ui->statusCheckBox->checkState() == Qt::Checked;
}
