#ifndef BALLASTRESISTORINPUTFRAME_H
#define BALLASTRESISTORINPUTFRAME_H

#include <QFrame>

#include "resistor.h"

namespace Ui {
class BallastResistorInputFrame;
}

class BallastResistorInputFrame : public QFrame
{
    Q_OBJECT

public:
    explicit BallastResistorInputFrame(QWidget *parent = nullptr);
    ~BallastResistorInputFrame();

    double getConsumptionValue();

private slots:
    void on_deleteButton_clicked();

private:
    Ui::BallastResistorInputFrame *ui;
};

#endif // BALLASTRESISTORINPUTFRAME_H
