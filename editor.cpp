#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
    Draw* draw = new Draw(800,500);
    draw->setAlignment(Qt::AlignCenter);
    draw->set_color(Qt::black);
    ui->drawZone->addWidget(draw);
}

void Editor::close_project(){
    this->close();
}

Editor::~Editor()
{
    delete ui;
}
