#ifndef CALCULATIONSETTINGSCREEN_H
#define CALCULATIONSETTINGSCREEN_H

#include <QWidget>
#include <QDebug>

#include "resistorinputframe.h"
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

private slots:
    void on_activeAddButton_clicked();

    void on_ballastAddButton_clicked();

    void on_acceptButton_clicked();

private:
    Ui::CalculationSettingScreen *ui;

    DataHandler *dataHandler;

    void newResistorsFound();
    QList<Resistor *> getActiveResistorList();
    QList<Resistor *> getBallastResistorList();

signals:
    void newActiveResistorsFound(QList<Resistor *> list);
    void newBallastResistorsFound(QList<Resistor *> list);
};

#endif // CALCULATIONSETTINGSCREEN_H
