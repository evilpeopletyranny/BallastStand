#ifndef CALCULATIONSETTINGSCREEN_H
#define CALCULATIONSETTINGSCREEN_H

#include <QWidget>
#include <QDebug>

#include "utilityresistorinputframe.h"
#include "ballastresistorinputframe.h"
#include "datahandler.h"

namespace Ui {
class CalculationSettingScreen;
}

class CalculationSettingScreen : public QWidget
{
    Q_OBJECT

public:
    explicit CalculationSettingScreen(QWidget *parent = nullptr);
    ~CalculationSettingScreen();

    void rebuildResistors();

private slots:
    void on_utilityAddButton_clicked();

    void on_ballastAddButton_clicked();

private:
    Ui::CalculationSettingScreen *ui;

    DataHandler *dataHandler;

    QList<std::pair<double, bool>> getUtilityResistorValueList();
    QList<double> getBallastResistorValueList();

signals:
    void sendUtilityResistorValueList(QList<std::pair<double, bool>> list);
    void sendBallastResistorsValueList(QList<double> list);
};

#endif // CALCULATIONSETTINGSCREEN_H
