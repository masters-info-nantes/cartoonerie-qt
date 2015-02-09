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
    ui->info->addWidget(new WelcomeAddProject);
    // Create model
        QStringListModel* model = new QStringListModel(this);

        // Make data
        QStringList List;
        List << "Clair de Lune" << "Reverie" << "Prelude";

        // Populate our model
        model->setStringList(List);
        ui->listView->setModel(model);
    connect(ui->listView->selectionModel(),
          SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
          this, SLOT(selectProject(QItemSelection)));
}

void Welcome::selectProject(const QItemSelection& selection) {
    if(selection.indexes().isEmpty()) {
        ui->info->addWidget(new WelcomeAddProject);
    } else {
        //displayModelIndexInMyView(selection.indexes().first());
        ui->info->addWidget(new WelcomeProject);
    }
}

Welcome::~Welcome()
{
    delete ui;
}
