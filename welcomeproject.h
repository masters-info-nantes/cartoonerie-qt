#ifndef WELCOMEPROJECT_H
#define WELCOMEPROJECT_H

#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class WelcomeProject;
}

class WelcomeProject : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeProject(QWidget *parent = 0);
    ~WelcomeProject();

private:
    Ui::WelcomeProject *ui;
};

#endif // WELCOMEPROJECT_H
