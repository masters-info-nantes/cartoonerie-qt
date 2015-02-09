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
    this->updateList();
    this->current = new WelcomeAddProject;
    this->welcomeHome = this->current;
    ui->info->addWidget(this->current);

    connect(ui->listView->selectionModel(),
          SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
          this, SLOT(selectProject(QItemSelection)));
}

void Welcome::updateList() {
    QStringListModel* model = new QStringListModel(this);

    QStringList List;
    List << "ofk";

    model->setStringList(List);
    ui->listView->setModel(model);
}

void Welcome::selectProject(const QItemSelection& selection) {
    if(selection.indexes().isEmpty()) {
        ui->info->removeWidget(this->current);
        this->current->close();
        this->current = this->welcomeHome;
        ui->info->addWidget(this->current);
    } else {
        //displayModelIndexInMyView(selection.indexes().first());
        ui->info->removeWidget(this->current);
        this->current->close();
        this->current = new WelcomeProject;
        ui->info->addWidget(this->current);
    }
}

Welcome::~Welcome()
{
    delete ui;
}
