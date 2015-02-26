#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
    ui->stackzone->push(new DrawZone(500,500));
}

void Editor::close_project(){
    this->close();
}

Editor::~Editor()
{
    delete ui;
}
