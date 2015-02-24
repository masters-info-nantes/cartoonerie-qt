#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
    ui->drawZone->addWidget(new Draw(50,50));
}

void Editor::close_project(){
    this->close();
}

Editor::~Editor()
{
    delete ui;
}
