#include "welcomeaddproject.h"
#include "ui_welcomeaddproject.h"

WelcomeAddProject::WelcomeAddProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeAddProject)
{
    ui->setupUi(this);
    connect(ui->fileBtn, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui->createProjectBtn, SIGNAL(clicked()), this, SLOT(createProject()));
}

void WelcomeAddProject::selectFile() {
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Video File"),QDir::homePath() ,tr("(*.mp4 *.wmv *.avi)"));
    if(fileNames.length() == 1) {
        ui->fileName->setText(fileNames.at(0));
    }
}

void WelcomeAddProject::createProject() {
    if(ui->fileName->text() != "" && ui->projectName->text() != "") {

    } else {
        QMessageBox::critical(
            this,
            tr("Application Name"),
            tr("An information message.") );
    }
}

WelcomeAddProject::~WelcomeAddProject()
{
    delete ui;
}
