#ifndef CALCULATIONSTACKEDWIDGET_H
#define CALCULATIONSTACKEDWIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class CalculationStackedWidget;
}

class CalculationStackedWidget : public QWidget
{
    Q_OBJECT

private:
    void goToSettingPage();
    void goToViewPage();

    void showChangeWidget();
    void hideChangeWidget();

public:
    explicit CalculationStackedWidget(QWidget *parent = nullptr);
    ~CalculationStackedWidget();

private slots:
    void on_acceptButton_clicked();

    void on_changeButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CalculationStackedWidget *ui;
};

#endif // CALCULATIONSTACKEDWIDGET_H
