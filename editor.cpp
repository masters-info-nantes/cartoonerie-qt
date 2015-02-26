#include "editor.h"
#include "ui_editor.h"

Editor::Editor(Project *project, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    this->project = project;

    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
    ui->stackzone->push(new DrawZone(800,500));

    // Generate a draw for each image
    QDir dir(project->getProjectDir());
    dir.cd("video_frames");

    QDir dirdraw(project->getProjectDir());
    dirdraw.cd("drawings");

    QStringList files(dir.entryList());
    for(int i = 0; i < files.length(); i++){
        QString file (files.at(i));
        if(file != "." && file != ".." && !file.endsWith(".draw.png")){
            QFileInfo pictureName(file);
            QImage* img = new QImage(ui->stackzone->size(), QImage::Format_ARGB32);
            img->save(dirdraw.absolutePath() + "/" + pictureName.baseName() + ".draw.png");
            delete img;
        }
    }

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
