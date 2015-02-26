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
    explicit Editor(QWidget *parent = 0);
    ~Editor();
    Project* project;

public slots:
    void close_project();
    void thumbClick(int index);

private:
    Ui::Editor *ui;
};

#endif // EDITOR_H
