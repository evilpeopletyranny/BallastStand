#ifndef UTILITYRESISTORINPUTFRAME_H
#define UTILITYRESISTORINPUTFRAME_H

#include <QFrame>

#include "resistor.h"

namespace Ui {
class UtilityResistorInputFrame;
}

class UtilityResistorInputFrame : public QFrame
{
    Q_OBJECT

public:
    explicit UtilityResistorInputFrame(QWidget *parent = nullptr);
    ~UtilityResistorInputFrame();

    double getConsumptionValue();
    bool getStatus();

private slots:
    void on_statusCheckBox_clicked();

private:
    Ui::UtilityResistorInputFrame *ui;

    void changeStatus();

    void setActiveState();
    void setActiveColor();
    void setActiveLabel();

    void setDeactiveState();
    void setDeactiveColor();
    void setDeactieLabel();
};

#endif // UTILITYRESISTORINPUTFRAME_H
