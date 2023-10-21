#ifndef RESISTORVIEWFRAME_H
#define RESISTORVIEWFRAME_H

#include <QFrame>
#include <QLocale>

#include "resistor.h"

namespace Ui {
class ResistorViewFrame;
}

class ResistorViewFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ResistorViewFrame(int number, Resistor *resistor, QWidget *parent = nullptr);
    ~ResistorViewFrame();

private:
    Ui::ResistorViewFrame *ui;

    void changeStatus(bool active);

    void setActiveColor();
    void setDeactiveColor();
};

#endif // RESISTORVIEWFRAME_H
