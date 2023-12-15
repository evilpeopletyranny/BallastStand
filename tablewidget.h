#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QTableWidget>
#include <QList>
#include <QDebug>
#include <QHeaderView>

#include "resistor.h"

class TableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QWidget *parent = nullptr);

    void drawTable(QList<QList<Resistor *>> dList);
    void drawCell(int row, int column, QString text);

    void drowDataRow(int row, QList<Resistor *> list);

    void drowHeaderLine(int size);

signals:

};

#endif // TABLEWIDGET_H
