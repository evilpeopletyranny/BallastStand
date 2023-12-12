#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent)
    : QTableWidget{parent}
{
    start();
}

void TableWidget::start()
{


    setColumnCount(5);
    setRowCount(5);

    QTableWidgetItem *item = new QTableWidgetItem("ewekjgnjklwegnklwegklkl");
    setItem(0, 0, item);
}
