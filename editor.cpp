#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
    ui->stackzone->push(new DrawZone(800,500));

    ui->thumbnailsList->setFlow(QListView::LeftToRight);
    connect(ui->thumbnailsList, SIGNAL(currentRowChanged(int)), this, SLOT(thumbClick(int)));
}

void Editor::thumbClick(int index){
    //this->changeCurrentImage(index);
    qDebug("ok");
}

void Editor::close_project(){
    this->close();
}

Editor::~Editor()
{
    delete ui;
}
