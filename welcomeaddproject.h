#ifndef WELCOMEADDPROJECT_H
#define WELCOMEADDPROJECT_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

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

private:
    Ui::WelcomeAddProject *ui;
};

#endif // WELCOMEADDPROJECT_H
