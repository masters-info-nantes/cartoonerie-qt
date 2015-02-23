#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
}

void Editor::close_project(){
    this->close();
}

Editor::~Editor()
{
    delete ui;
}
