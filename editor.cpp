#include "editor.h"
#include "ui_editor.h"

Editor::Editor(Project *project, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    this->project = project;

    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
    ui->stackzone->push(new DrawZone(500,500));

    // Generate a draw for each image
    QDir dir(project->getProjectDir());
    dir.cd("drawings");
    QStringList files(dir.entryList());

    for(int i = 0; i < files.length(); i++){
        QString file (files.at(i));
        if(file != "." && file != ".." && !file.endsWith(".draw.png")){
            QFileInfo pictureName(file);

            QImage* img = new QImage(ui->stackzone->size(), QImage::Format_ARGB32);
            img->save(dir.absolutePath() + "/" + pictureName.baseName() + ".draw.png");
            delete img;
        }
    }
}

void Editor::close_project(){
    this->close();
}

Editor::~Editor()
{
    delete ui;
}
