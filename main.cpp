#include "mainwindow.h"

#include <QApplication>
#include "algorithmcore.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AlgorithmCore::getInstance();

    MainWindow w;
    w.showMaximized();
    return a.exec();
}
