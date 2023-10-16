#ifndef CALCULATIONSTACKEDWIDGET_H
#define CALCULATIONSTACKEDWIDGET_H

#include <QWidget>

namespace Ui {
class CalculationStackedWidget;
}

class CalculationStackedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalculationStackedWidget(QWidget *parent = nullptr);
    ~CalculationStackedWidget();

private:
    Ui::CalculationStackedWidget *ui;
};

#endif // CALCULATIONSTACKEDWIDGET_H
