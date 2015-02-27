#ifndef WELCOMEPROJECT_H
#define WELCOMEPROJECT_H

#include <QWidget>
#include <QMediaPlayer>
#include "project.h"
#include "editor.h"

namespace Ui {
class WelcomeProject;
}

class WelcomeProject : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeProject(Project *project, QWidget *parent = 0);
    ~WelcomeProject();

public slots:
     void editProject();
     void play();
     void stop();
     void durationChanged(qint64 progress);
     void positionChanged(qint64 progress);
     void seek(int);

private:
    Ui::WelcomeProject *ui;
    Project *project;
    QMediaPlayer* player;
    bool isPlay = false;
};

#endif // WELCOMEPROJECT_H
