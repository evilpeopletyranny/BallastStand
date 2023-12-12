#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "windowmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    WindowManager* windowManager;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionTable_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
