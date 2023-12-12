#include "windowmanager.h"

WindowManager *WindowManager::instance = nullptr;

WindowManager::WindowManager(QObject *parent)
    : QObject{parent}
{
    createWindowsInstance();
}

WindowManager::~WindowManager()
{
    deleteWindowsInstance();
}

void WindowManager::createWindowsInstance()
{
    tableWidget = new TableWidget();
}

void WindowManager::deleteWindowsInstance()
{
    delete tableWidget;
}

WindowManager *WindowManager::getInstance()
{
    if (WindowManager::instance == nullptr) WindowManager::instance = new WindowManager();
    return WindowManager::instance;
}

void WindowManager::showTableWidget(QWidget *parent)
{
    tableWidget->setParent(parent, Qt::Dialog);
    tableWidget->show();
}
