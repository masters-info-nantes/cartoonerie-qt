#include "welcomeaddproject.h"
#include "ui_welcomeaddproject.h"

WelcomeAddProject::WelcomeAddProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeAddProject)
{
    ui->setupUi(this);
    connect(ui->fileBtn, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui->createProjectBtn, SIGNAL(clicked()), this, SLOT(createProject()));
    connect(ui->fpsBtn, SIGNAL(clicked()), this, SLOT(fpsInfo()));
}

void WelcomeAddProject::selectFile() {
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Video File"),QDir::homePath() ,tr("(*.mp4 *.wmv *.avi)"));
    if(fileNames.length() == 1) {
        ui->fileName->setText(fileNames.at(0));
    }
}

void WelcomeAddProject::createProject() {
    if(ui->fileName->text() != "" && ui->projectName->text() != "") {
        editor = new Editor();
        editor->show();
    } else {
        QMessageBox::critical(
            this,
            tr("Cartoonerie"),
            tr("Select a video file.") );
    }
}

void WelcomeAddProject::fpsInfo() {
    QMessageBox::information(
                this,
                tr("Cartoonerie"),
                tr("FPS: Frames per second."));
}

WelcomeAddProject::~WelcomeAddProject()
{
    delete ui;
}
