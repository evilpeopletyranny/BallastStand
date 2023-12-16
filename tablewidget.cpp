#include "tablewidget.h"

void TableWidget::initUI()
{
    setMinimumSize(500, 500);
    setMaximumSize(1000, 500);

    setWindowTitle("Таблица расчетов");

    setShowGrid(true);
    verticalHeader()->setVisible(false);
}

void TableWidget::calculateTableSize(QList<QList<Resistor *> > &dList)
{
    rowCount = dList.size();
    columnCount = dList.first().size() + 2;

    qDebug() << "Кол-во строк" << rowCount;
    qDebug() << "Кол-во столбцов" << columnCount;
    qDebug() << "Кол-во резисторов" << dList.first().size();
}

void TableWidget::resizeTable()
{
    setColumnCount(columnCount);
    setRowCount(rowCount);
}

void TableWidget::drawHeader()
{
    setHorizontalHeaderLabels(createHeader(columnCount-1));
}

QStringList TableWidget::createHeader(int size)
{
    auto headers = QStringList() << "Кол-во % мощности,\nкоторое потребляет\nполезная нагрузка";
    for (int i = 1; i < size; i++) headers << QString::number(i);
    headers << "Разницу между\nреальной\nнагрузкой и 100%";

    return headers;
}

TableWidget::TableWidget(QWidget *parent)
    : QTableWidget{parent}
{
    initUI();
    dataHandler = DataHandler::getInstance();
    algoritmCore = AlgorithmCore::getInstance();

    connect(algoritmCore, &AlgorithmCore::algorithComplete, this, &TableWidget::calculateTable);
}

void TableWidget::drawTable(QList<QList<Resistor *>> dList)
{
    calculateTableSize(dList);
    resizeTable();
    drawHeader();

    for (int i = 0; i < dList.size(); i++) drowDataRow(i, dList.at(i));

    resizeColumnsToContents();
}

void TableWidget::calculateTable()
{
    qDebug() << "TableWidget: Расчет таблицы";
    auto list = dataHandler->getBallastResisterList();

    QList<Resistor *> a;
    for (auto item: list) a.append(new Resistor(item->getPower(), item->getPercent(), false));

    QList<QList<Resistor *>> res;
    for (int i = 0; i <= 100; i++)
    {
        res.append(algoritmCore->greedyAlgorihtm(100.0 - i, a));
    }

    drawTable(res);
}

void TableWidget::drowDataRow(int rowNumber, QList<Resistor *> list)
{
    double load = 0.0;

    for(int columnNumber = 0; columnNumber < list.size(); columnNumber++) {
        drawCell(rowNumber, 0, QString::number(rowNumber));

        if (list.at(columnNumber)->isActive()) {
            load += list.at(columnNumber)->getPercent();
            drawCell(rowNumber, columnNumber+1, "+");
        }
        else drawCell(rowNumber, columnNumber+1, "-");
    }

    drawCell(rowNumber, columnCount - 1, QString::number(100.0 - (load + (double)rowNumber)));
}

void TableWidget::drawCell(int row, int column, QString text)
{
    auto* item = new QTableWidgetItem(text);
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);
    item->setTextAlignment(Qt::AlignCenter);
    setItem(row, column, item);
}
