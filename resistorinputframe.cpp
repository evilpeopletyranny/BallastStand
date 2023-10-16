#include "resistorinputframe.h"
#include "ui_resistorinputframe.h"

ResistorInputFrame::ResistorInputFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ResistorInputFrame)
{
    ui->setupUi(this);
    changeStatus();
}

ResistorInputFrame::~ResistorInputFrame()
{
    delete ui;
}

void ResistorInputFrame::on_statusCheckBox_clicked()
{
    changeStatus();
}

void ResistorInputFrame::changeStatus()
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

void ResistorInputFrame::setActiveState()
{
    setActiveColor();
    setActiveLabel();
}

void ResistorInputFrame::setActiveColor()
{
    const QString color = "background-color: rgb(51, 209, 122);";
    this->setStyleSheet(color);
}

void ResistorInputFrame::setActiveLabel()
{
    const QString label = "Вкл";
    ui->statusLabel->setText(label);
}

void ResistorInputFrame::setDeactiveState()
{
    setDeactiveColor();
    setDeactieLabel();
}

void ResistorInputFrame::setDeactiveColor()
{
    const QString color = "background-color: rgb(246, 97, 81);";
    this->setStyleSheet(color);
}

void ResistorInputFrame::setDeactieLabel()
{
    const QString label = "Выкл";
    ui->statusLabel->setText(label);
}

Resistor *ResistorInputFrame::getResistor()
{
    return new Resistor(getConsumptionValue(), getStatus());
}

double ResistorInputFrame::getConsumptionValue()
{
    return ui->consumptionSpinBox->value();
}

bool ResistorInputFrame::getStatus()
{
    return ui->statusCheckBox->checkState() == Qt::Checked;
}
