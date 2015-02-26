#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <project.h>
#include "drawzone.h"
#include <QLabel>
#include <QDir>

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

private:
    Ui::Editor *ui;
    Project* project;
    int currentIndex;
    QDir dir;
    QDir dirdraw;
    DrawZone *drawzone;
};

#endif // EDITOR_H
