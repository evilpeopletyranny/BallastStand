#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QTableWidget>

class TableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QWidget *parent = nullptr);

    void start();

signals:

};

#endif // TABLEWIDGET_H
