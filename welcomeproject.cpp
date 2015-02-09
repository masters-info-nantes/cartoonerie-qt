#include "welcomeproject.h"
#include "ui_welcomeproject.h"

WelcomeProject::WelcomeProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeProject)
{
    ui->setupUi(this);

    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/Users/Maxime/Downloads/test.mp4"));
    player->setVolume(50);
    player->play();
    player->setVideoOutput(ui->widget);
}

WelcomeProject::~WelcomeProject()
{
    delete ui;
}
