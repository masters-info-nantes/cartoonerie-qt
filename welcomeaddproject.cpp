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
        int fpsPos = ui->fps->currentIndex();
        int fps = 6;
        if(fpsPos == 1)
            fps = 8;
        if(fpsPos == 2)
            fps = 12;
        if(fpsPos == 3)
            fps = 24;
        qDebug("%d",fps);
        Project* p = new Project(ui->projectName->text(),fps,ui->fileName->text());
        this->projectManager->createProject(p);
        editor = new Editor();
        editor->project = p;
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
