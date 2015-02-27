#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include "QColor"
#include "QColorDialog"

namespace Ui {
class ColorPicker;
}

class ColorPicker : public QWidget
{
    Q_OBJECT

public:
    explicit ColorPicker(QWidget *parent = 0);
    ~ColorPicker();

public slots:
    void openDialog();
    void changeColor(QColor color);

private:
    Ui::ColorPicker *ui;
    QColorDialog* colorPalette;
};

#endif // COLORPICKER_H
