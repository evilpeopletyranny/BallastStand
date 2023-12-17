#include "mainwindow.h"

#include <QApplication>
#include <QThread>
#include "algorithmcore.h"
#include "serialconnector.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AlgorithmCore::getInstance();
    QString name = "ttyUSB0";
    if(argc>1)
        name = QString(argv[1]);

    //uncomment bofore final compiling.
    //SerialConnector::getInstance(name,&a);

    MainWindow w;
    w.showMaximized();
    return a.exec();
}
