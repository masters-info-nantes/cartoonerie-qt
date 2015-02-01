#include "welcome.h"
#include "ui_welcome.h"

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    ui->info->addWidget(new WelcomeAddProject);
    QMediaPlayer* player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/Users/Maxime/Downloads/test.mp4"));
    player->setVolume(50);
    player->play();
    //player->setVideoOutput(ui->);
}

Welcome::~Welcome()
{
    delete ui;
}
