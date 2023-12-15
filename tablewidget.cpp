#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent)
    : QTableWidget{parent}
{
    QList<QList<Resistor *>> list;

    QList<Resistor *> first;
    first.append(new Resistor(10, 10, true));
    first.append(new Resistor(20, 20, true));
    first.append(new Resistor(30, 30, false));
    first.append(new Resistor(50, 50, false));

    list.append(first);

    drawTable(list);
    resizeColumnsToContents();
}

void TableWidget::drawTable(QList<QList<Resistor *>> dList)
{
    qDebug() << "Кол-во строк: " << dList.size();


    setColumnCount(1 + dList.first().size());
    setRowCount(dList.size() + 2);

    drowHeaderLine(dList.first().size());
    for (int i = 0; i < dList.size(); i++) drowDataRow(i, dList.at(i));
}

void TableWidget::drowDataRow(int rowNumber, QList<Resistor *> list)
{
    for(int columnNumber = 0; columnNumber < list.size(); columnNumber++) {
        drawCell(rowNumber+1, 0, QString::number(rowNumber+1));
        drawCell(rowNumber+1, columnNumber+1, list.at(columnNumber)->isActive()? "+" : "-");
    }
}

void TableWidget::drowHeaderLine(int size)
{
    qDebug() << "Отрисовка заглавной строки";
    drawCell(0, 0, "Кол-во % мощности,\nкоторое потребляет\nполезная нагрузка");
    for (int i = 1; i <= size; i++) drawCell(0, i, QString::number(i));

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void TableWidget::drawCell(int row, int column, QString text)
{
    auto* item = new QTableWidgetItem(text);
    item->setFlags(item->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    setItem(row, column, item);
}
