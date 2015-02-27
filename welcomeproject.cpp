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

    //ui->slider->setRange(0, this->player->duration() / 1000);
    connect(ui->slider, SIGNAL(sliderMoved(int)), this, SLOT(seek(int)));
    connect(this->player, SIGNAL(durationChanged(qint64)), SLOT(durationChanged(qint64)));
    connect(this->player, SIGNAL(positionChanged(qint64)), SLOT(positionChanged(qint64)));

}

void WelcomeProject::editProject(){
    Editor* editor = new Editor(this->project);
    editor->show();
}

void WelcomeProject::play(){
    if(!isPlay) {
        this->player->play();
        ui->playBtn->setIcon(QIcon(QPixmap(":images/pause.png")));
    } else {
        this->player->pause();
        ui->playBtn->setIcon(QIcon(QPixmap(":images/play.png")));
    }
    isPlay = !isPlay;
}

void WelcomeProject::stop(){
    this->player->stop();
    ui->playBtn->setIcon(QIcon(QPixmap(":images/play.png")));
}

void WelcomeProject::durationChanged(qint64 duration) {
    ui->slider->setMaximum(duration / 1000);
}

void WelcomeProject::positionChanged(qint64 progress) {
    if (!ui->slider->isSliderDown()) {
        ui->slider->setValue(progress / 1000);
    }
}

void WelcomeProject::seek(int seconds) {
    player->setPosition(seconds * 1000);
    qDebug() << seconds;
}

WelcomeProject::~WelcomeProject()
{
    delete ui;
}
