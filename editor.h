#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <project.h>
#include "drawzone.h"

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

private:
    Ui::Editor *ui;
    Project* project;
};

#endif // EDITOR_H
