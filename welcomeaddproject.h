#ifndef WELCOMEADDPROJECT_H
#define WELCOMEADDPROJECT_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "editor.h"

namespace Ui {
class WelcomeAddProject;
}

class WelcomeAddProject : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeAddProject(QWidget *parent = 0);
    ~WelcomeAddProject();

public slots:
     void selectFile();
     void createProject();
     void fpsInfo();

private:
    Ui::WelcomeAddProject *ui;
    Editor *editor;
};

#endif // WELCOMEADDPROJECT_H
