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
    Project *project;
    explicit WelcomeProject(QWidget *parent = 0);
    void run();
    ~WelcomeProject();

public slots:
     void editProject();

private:
    Ui::WelcomeProject *ui;
};

#endif // WELCOMEPROJECT_H
