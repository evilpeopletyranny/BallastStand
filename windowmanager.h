#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QObject>

#include "tablewidget.h"

class WindowManager : public QObject
{
    Q_OBJECT
private:
    explicit WindowManager(QObject *parent = nullptr);
    ~WindowManager();

    static WindowManager *instance;

    void createWindowsInstance();
    void deleteWindowsInstance();


    TableWidget *tableWidget;

public:
    static WindowManager *getInstance();

    void showTableWidget(QWidget *parent);

signals:

};

#endif // WINDOWMANAGER_H
