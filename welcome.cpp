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
    this->projectManager = new ProjectManager();
    this->updateList();
    this->welcomeHome = new WelcomeAddProject();
    this->welcomeHome->projectManager = this->projectManager;
    this->current = this->welcomeHome;
    ui->info->addWidget(this->current);

    connect(ui->listView->selectionModel(),
          SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
          this, SLOT(selectProject(QItemSelection)));
}

void Welcome::updateList() {
    QStringListModel* model = new QStringListModel(this);

    QStringList projectList;
    projectList.append("Add project");

    for(int i=0; i<this->projectManager->getProjects()->size(); i++) {
        projectList.append(this->projectManager->getProjects()->at(i)->getName());
    }

    model->setStringList(projectList);
    ui->listView->setModel(model);
}

void Welcome::selectProject(const QItemSelection& selection) {
    int pos = ui->listView->currentIndex().row();
    if(pos == 0) {
        ui->info->removeWidget(this->current);
        this->current->close();
        this->current = this->welcomeHome;
        this->current->show();
        ui->info->addWidget(this->current);
    } else {
        ui->info->removeWidget(this->current);
        this->current->close();
        WelcomeProject *wp = new WelcomeProject;
        wp->project = projectManager->getProjects()->at(pos-1);
        wp->run();
        this->current = wp;
        ui->info->addWidget(this->current);
    }
}

Welcome::~Welcome()
{
    delete ui;
}
