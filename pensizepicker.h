#ifndef PENSIZEPICKER_H
#define PENSIZEPICKER_H

#include <QWidget>

namespace Ui {
class PenSizePicker;
}

class PenSizePicker : public QWidget
{
    Q_OBJECT

public:
    explicit PenSizePicker(QWidget *parent = 0);
    ~PenSizePicker();

signals:
    void sizeChanged(int);

public slots:
    void changeSize(int);
    void notifySizeChange();

private:
    Ui::PenSizePicker *ui;
};

#endif // PENSIZEPICKER_H
