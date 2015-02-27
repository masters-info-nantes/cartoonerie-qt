#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <project.h>
#include "drawzone.h"
#include "colorpicker.h"
#include "pensizepicker.h"
#include <QColor>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(Project *project, QWidget *parent = 0);
    ~Editor();

public slots:
    void close_project();
    void thumbClick(int index);
    void saveCurrentDraw();
    void exportDrawWithMovie();
    void updateTool(int index);
    void updateAllColor(QColor color);
    void updateAllSize(int size);
    void updateThumbnails();
    void displayBackgroundMovie(bool active);
    void onionPeelings(bool active);
    void peelingsNumber();

private:
    Ui::Editor *ui;
    Project* project;
    ColorPicker* colorPicker;
    PenSizePicker* penSizePicker;
    int currentIndex;
    QDir dir;
    QDir dirdraw;
    DrawZone *drawzone;
    bool backgroundDisplayed;
    bool onionDisplayed;
    const static int DEFAULT_PEELINGS_COUNT = 3;
    int peelingsCount;

};

#endif // EDITOR_H
