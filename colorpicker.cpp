#include "colorpicker.h"
#include "ui_colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorPicker)
{
    ui->setupUi(this);
    ui->color->setStyleSheet("background-color:black;");
    connect(ui->colorPicker, SIGNAL(clicked()), this, SLOT(openDialog()));
}

void ColorPicker::openDialog()
{
    colorPalette = new QColorDialog();
    colorPalette->show();
    QObject::connect(colorPalette, SIGNAL(colorSelected(QColor)), this, SLOT(changeColor(QColor)));
    QObject::connect(colorPalette, SIGNAL(colorSelected(QColor)), this, SLOT(notifyColorChange(QColor)));
}

void ColorPicker::changeColor(QColor color)
{
    ui->color->setStyleSheet("background-color:"+color.name()+";");
}

void ColorPicker::notifyColorChange(QColor color){
    emit colorChanged(color);
}

ColorPicker::~ColorPicker()
{
    delete ui;
}
