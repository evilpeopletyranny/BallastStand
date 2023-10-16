#ifndef RESISTORFRAME_H
#define RESISTORFRAME_H

#include <QFrame>

namespace Ui {
class ResistorFrame;
}

class ResistorFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ResistorFrame(QWidget *parent = nullptr);
    ~ResistorFrame();

private:
    Ui::ResistorFrame *ui;
};

#endif // RESISTORFRAME_H
