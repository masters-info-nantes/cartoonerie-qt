#include "pensizepicker.h"
#include "ui_pensizepicker.h"

PenSizePicker::PenSizePicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PenSizePicker)
{
    ui->setupUi(this);
}

PenSizePicker::~PenSizePicker()
{
    delete ui;
}
