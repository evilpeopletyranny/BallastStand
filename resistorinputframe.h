#ifndef RESISTORINPUTFRAME_H
#define RESISTORINPUTFRAME_H

#include <QFrame>

#include "resistor.h"

namespace Ui {
class ResistorInputFrame;
}

class ResistorInputFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ResistorInputFrame(QWidget *parent = nullptr);
    ~ResistorInputFrame();

    Resistor *getResistor();

private slots:
    void on_statusCheckBox_clicked();

private:
    Ui::ResistorInputFrame *ui;

    void changeStatus();

    void setActiveState();
    void setActiveColor();
    void setActiveLabel();

    void setDeactiveState();
    void setDeactiveColor();
    void setDeactieLabel();

    double getConsumptionValue();
    bool getStatus();
};

#endif // RESISTORINPUTFRAME_H
