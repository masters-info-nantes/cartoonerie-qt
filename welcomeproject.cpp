#include "welcomeproject.h"
#include "ui_welcomeproject.h"

WelcomeProject::WelcomeProject(Project *project, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeProject)
{
    ui->setupUi(this);
    connect(ui->editProject, SIGNAL(clicked()), this, SLOT(editProject()));
    connect(ui->playBtn, SIGNAL(clicked()), this, SLOT(play()));
    connect(ui->stopBtn, SIGNAL(clicked()), this, SLOT(stop()));

    this->project = project;
    this->player = new QMediaPlayer;
    this->player->setMedia(QUrl::fromLocalFile(project->getFile()));
    this->player->setVolume(0);
    this->player->setVideoOutput(ui->widget);
    ui->projectName->setText(project->getName());
}

void WelcomeProject::editProject(){
    Editor* editor = new Editor(this->project);
    editor->show();
}

void WelcomeProject::play(){
    this->player->play();
    //this->player->pause();
}

void WelcomeProject::stop(){
    this->player->stop();
}

WelcomeProject::~WelcomeProject()
{
    delete ui;
}
