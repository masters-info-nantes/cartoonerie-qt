#include "editor.h"
#include "ui_editor.h"
#include <sstream>
#include <QFileDialog>

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
    connect(ui->actionExport, SIGNAL(triggered()), this, SLOT(export_project()));
}

void Editor::close_project(){
    this->close();
}

void Editor::export_project(){
    std::stringstream ss;
    ss << project->getFps();
    QString fps = QString::fromStdString(ss.str());
    std::string str = "avconv -y -f image2 -r " + ss.str() + " -i " + project->getProjectDir().absolutePath().toStdString() + ".png -vcodec mpeg4 " + project->getProjectDir().absolutePath().toStdString()+"/videos/ma_video.avi";
    system(str.c_str());

    QString dir_save = QDir::home().path();
    QString save_here = QFileDialog::getExistingDirectory(this, tr("Choose a directory"), dir_save, QFileDialog::ShowDirsOnly);
    std::string copier = "cp -R " + project->getProjectDir().absolutePath().toStdString() + "/dessins " + save_here.toStdString();
    system(copier.c_str());
}

Editor::~Editor()
{
    delete ui;
}
