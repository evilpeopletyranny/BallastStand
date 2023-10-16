#include "resistorframe.h"
#include "ui_resistorframe.h"

ResistorFrame::ResistorFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ResistorFrame)
{
    ui->setupUi(this);
}

ResistorFrame::~ResistorFrame()
{
    delete ui;
}
