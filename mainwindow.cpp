#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    windowManager = WindowManager::getInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionTable_triggered()
{
    windowManager->showTableWidget(this);
}

