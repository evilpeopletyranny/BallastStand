#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QTableWidget>
#include <QList>
#include <QDebug>
#include <QHeaderView>
#include <QSizePolicy>

#include "resistor.h"
#include "datahandler.h"
#include "algorithmcore.h"

class TableWidget : public QTableWidget
{
    Q_OBJECT

private:
    void initUI();

    int columnCount = 0;
    int rowCount = 0;

    DataHandler *dataHandler;
    AlgorithmCore *algoritmCore;

    void calculateTableSize(QList<QList<Resistor *>> &dList);
    void resizeTable();

    void drawHeader();
    QStringList createHeader(int size);

public:
    explicit TableWidget(QWidget *parent = nullptr);

    void drawCell(int row, int column, QString text);
    void drowDataRow(int row, QList<Resistor *> list);

    void drawTable(QList<QList<Resistor *>> dList);

public slots:
    void calculateTable();

signals:

};

#endif // TABLEWIDGET_H
