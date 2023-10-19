#ifndef ACTIVERESISTORINPUTFRAME_H
#define ACTIVERESISTORINPUTFRAME_H

#include <QFrame>

#include "resistor.h"

namespace Ui {
class ActiveResistorInputFrame;
}

class ActiveResistorInputFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ActiveResistorInputFrame(QWidget *parent = nullptr);
    ~ActiveResistorInputFrame();

    double getConsumptionValue();
    bool getStatus();

private slots:
    void on_statusCheckBox_clicked();

private:
    Ui::ActiveResistorInputFrame *ui;

    void changeStatus();

    void setActiveState();
    void setActiveColor();
    void setActiveLabel();

    void setDeactiveState();
    void setDeactiveColor();
    void setDeactieLabel();
};

#endif // ACTIVERESISTORINPUTFRAME_H
