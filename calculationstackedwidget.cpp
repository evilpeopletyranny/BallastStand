#include "calculationstackedwidget.h"
#include "ui_calculationstackedwidget.h"

CalculationStackedWidget::CalculationStackedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationStackedWidget)
{
    ui->setupUi(this);

    goToViewPage();
}

void CalculationStackedWidget::goToSettingPage()
{
    ui->stackedWidget->setCurrentWidget(ui->settingPage);
    showChangeWidget();
}

void CalculationStackedWidget::goToViewPage()
{
    ui->stackedWidget->setCurrentWidget(ui->viewPage);
    hideChangeWidget();
}

void CalculationStackedWidget::showChangeWidget()
{
    ui->changeWidget->setVisible(true);
    ui->changeButton->setVisible(false);
}

void CalculationStackedWidget::hideChangeWidget()
{
    ui->changeWidget->setVisible(false);
    ui->changeButton->setVisible(true);
}

CalculationStackedWidget::~CalculationStackedWidget()
{
    delete ui;
}

void CalculationStackedWidget::on_acceptButton_clicked()
{
    qDebug() << "CalculationStackedWidget: нажатие кнопки применить.";

    goToViewPage();
    ui->settingPage->rebuildResistors();
}

void CalculationStackedWidget::on_cancelButton_clicked()
{
    goToViewPage();
}

void CalculationStackedWidget::on_changeButton_clicked()
{
    goToSettingPage();
}
