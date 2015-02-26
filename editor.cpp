#include "editor.h"
#include "ui_editor.h"

Editor::Editor(Project *project, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    this->project = project;

    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
<<<<<<< HEAD
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
=======
    ui->stackzone->push(new DrawZone(800,500));

    ui->thumbnailsList->setFlow(QListView::LeftToRight);
    connect(ui->thumbnailsList, SIGNAL(currentRowChanged(int)), this, SLOT(thumbClick(int)));
}

void Editor::thumbClick(int index){
    //this->changeCurrentImage(index);
    qDebug("ok");
>>>>>>> 608f4293ae7159d05f0b3829c4c0c833ddbda199
}

void Editor::close_project(){
    this->close();
}

Editor::~Editor()
{
    delete ui;
}
