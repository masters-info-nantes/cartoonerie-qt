#include "welcomeproject.h"
#include "ui_welcomeproject.h"

WelcomeProject::WelcomeProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeProject)
{
    ui->setupUi(this);
    connect(ui->editProject, SIGNAL(clicked()), this, SLOT(editProject()));
}

void WelcomeProject::run() {
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(project->getFile()));
    player->setVolume(0);
    player->play();
    player->setVideoOutput(ui->widget);
    ui->projectName->setText(project->getName());
}

void WelcomeProject::editProject(){
    Editor* editor = new Editor();
    editor->show();
}

WelcomeProject::~WelcomeProject()
{
    delete ui;
}
