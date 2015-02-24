#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <project.h>
#include "draw.h"

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();
    Project* project;

public slots:
    void close_project();

private:
    Ui::Editor *ui;
};

#endif // EDITOR_H
