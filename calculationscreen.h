#ifndef CALCULATIONSCREEN_H
#define CALCULATIONSCREEN_H

#include <QWidget>

namespace Ui {
class CalculationScreen;
}

class CalculationScreen : public QWidget
{
    Q_OBJECT

public:
    explicit CalculationScreen(QWidget *parent = nullptr);
    ~CalculationScreen();

private:
    Ui::CalculationScreen *ui;
};

#endif // CALCULATIONSCREEN_H
