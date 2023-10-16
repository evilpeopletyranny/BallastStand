#include "calculationscreen.h"
#include "ui_calculationscreen.h"

CalculationScreen::CalculationScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationScreen)
{
    ui->setupUi(this);
}

CalculationScreen::~CalculationScreen()
{
    delete ui;
}
