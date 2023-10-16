#include "calculationstackedwidget.h"
#include "ui_calculationstackedwidget.h"

CalculationStackedWidget::CalculationStackedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationStackedWidget)
{
    ui->setupUi(this);
}

CalculationStackedWidget::~CalculationStackedWidget()
{
    delete ui;
}
