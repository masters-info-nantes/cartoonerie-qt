#include "pensizepicker.h"
#include "ui_pensizepicker.h"

PenSizePicker::PenSizePicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PenSizePicker)
{
    ui->setupUi(this);

    connect(ui->size1, SIGNAL(clicked()), this, SLOT(notifySizeChange()));
    connect(ui->size2, SIGNAL(clicked()), this, SLOT(notifySizeChange()));
    connect(ui->size3, SIGNAL(clicked()), this, SLOT(notifySizeChange()));
    connect(ui->size4, SIGNAL(clicked()), this, SLOT(notifySizeChange()));
}

void PenSizePicker::changeSize(int size)
{
    if (size == 0)
        ui->size1->setChecked(true);
    else
        ui->size1->setChecked(false);

    if (size == 1)
        ui->size2->setChecked(true);
    else
        ui->size2->setChecked(false);

    if (size == 2)
        ui->size3->setChecked(true);
    else
        ui->size3->setChecked(false);

    if (size == 3)
        ui->size4->setChecked(true);
    else
        ui->size4->setChecked(false);
}

void PenSizePicker::notifySizeChange(){
    int i = 0;
    if(sender() == ui->size2)
        i = 1;
    if(sender() == ui->size3)
        i = 2;
    if(sender() == ui->size4)
        i = 3;

    emit sizeChanged(i);
}

PenSizePicker::~PenSizePicker()
{
    delete ui;
}
