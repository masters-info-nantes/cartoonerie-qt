#include "editor.h"
#include "ui_editor.h"
#include <sstream>
#include <string>

Editor::Editor(Project *project, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    this->drawzone = new DrawZone(800,500);
    this->drawzone->setPenWidth(1);

    connect(ui->tools, SIGNAL(currentChanged(int)), this, SLOT(updateTool(int)));

    connect(ui->traitColor, SIGNAL(colorChanged(QColor)), this, SLOT(updateAllColor(QColor)));
    connect(ui->penColor, SIGNAL(colorChanged(QColor)), this, SLOT(updateAllColor(QColor)));

    connect(ui->traitSize, SIGNAL(sizeChanged(int)), this, SLOT(updateAllSize(int)));
    connect(ui->penSize, SIGNAL(sizeChanged(int)), this, SLOT(updateAllSize(int)));
    connect(ui->eraserSize, SIGNAL(sizeChanged(int)), this, SLOT(updateAllSize(int)));


    this->project = project;
    currentIndex=0;
    connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(close_project()));
    connect(ui->actionExport, SIGNAL(triggered()), this, SLOT(exportDrawWithMovie()));
    ui->stackzone->push(this->drawzone);

    ui->thumbnailsList->setFlow(QListView::LeftToRight);

    // Generate a draw for each image
    QDir dir(project->getProjectDir());
    dir.cd("video_frames");

    QDir dirdraw(project->getProjectDir());
    dirdraw.cd("drawings");

    QStringList files(dir.entryList());
    for(int i = 0; i < files.length(); i++){
        QString file (files.at(i));
        if(file != "." && file != ".." && !file.endsWith(".draw.png")){
            QFileInfo pictureName(file);
            QStringList draws(dirdraw.entryList());
            if(draws.filter(pictureName.baseName()).size()!=0){
                QImage* img = new QImage(ui->stackzone->size(), QImage::Format_ARGB32);
                img->save(dirdraw.absolutePath() + "/" + pictureName.baseName() + ".draw.png");
                delete img;
            }

        }

        QLabel* thumbLabel = new QLabel();
        thumbLabel->setAlignment(Qt::AlignCenter);
        thumbLabel->setToolTip(dir.absolutePath() + "/" + file);

        QPixmap* thumbFull = new QPixmap(dir.absolutePath() + "/" + file);
        QPixmap thumbScaled(thumbFull->scaledToHeight(100));

        thumbLabel->setPixmap(thumbScaled);
        thumbLabel->setMinimumSize(QSize(thumbScaled.width(), thumbScaled.height()));

        QListWidgetItem* listItem = new QListWidgetItem(ui->thumbnailsList);
        listItem->setSizeHint(QSize(thumbLabel->minimumWidth()+ 30, thumbLabel->minimumHeight()));

        ui->thumbnailsList->addItem(listItem);
        ui->thumbnailsList->setItemWidget(listItem, thumbLabel);

        delete thumbFull;// not use after

    }
    connect(ui->thumbnailsList, SIGNAL(currentRowChanged(int)), this, SLOT(thumbClick(int)));
    ui->stackzone->push(project->getProjectDir().absolutePath()+"/video_frames/"+project->getName()+"-001.png");
}

void Editor::thumbClick(int index){
    index--;
    this->updateThumbnails();
    this->currentIndex=index;
    this->saveCurrentDraw();
    ui->stackzone->removeAll();
    this->drawzone = new DrawZone(800,500);
    QString img;
    std::stringstream s;
    s << index;
    QString image = s.str().c_str();
    if(index <10){
        img = project->getName()+"-00"+image+".png";
    }
    else{
        img = project->getName()+"-0"+image+".png";
    }
    //this->changeCurrentImage(index);
    QImage* frame = new QImage(project->getProjectDir().absolutePath()+"/video_frames/"+img);
    this->drawzone->replaceLayer(frame);
    ui->stackzone->removeAll();
    ui->stackzone->push(this->drawzone);

}

void Editor::updateThumbnails(){
    QDir dir(project->getProjectDir().absolutePath()+"/drawings");
    QStringList files(dir.entryList());

    for(int i = 0; i < files.length(); i++){
        QString file(files.at(i));
        if(file == "." || file == ".." || file.endsWith(".draw.png")){
            continue;
        }

        QLabel* thumbLabel = new QLabel();
        thumbLabel->setAlignment(Qt::AlignCenter);
        thumbLabel->setToolTip(dir.absolutePath() + "/" + file);

        QPixmap* thumbFull = new QPixmap(dir.absolutePath() + "/" + file);
        QPixmap thumbScaled(thumbFull->scaledToHeight(100));

        thumbLabel->setPixmap(thumbScaled);
        thumbLabel->setMinimumSize(QSize(thumbScaled.width(), thumbScaled.height()));

        QListWidgetItem* listItem = new QListWidgetItem(ui->thumbnailsList);
        listItem->setSizeHint(QSize(thumbLabel->minimumWidth()+ 30, thumbLabel->minimumHeight()));

        ui->thumbnailsList->addItem(listItem);
        ui->thumbnailsList->setItemWidget(listItem, thumbLabel);

        delete thumbFull;// not use after
    }
}

void Editor::updateTool(int index){
    this->drawzone->setTool(index);
}

void Editor::updateAllColor(QColor color){
    this->drawzone->setPenColor(color);
    ui->penColor->changeColor(color);
    ui->traitColor->changeColor(color);
}

void Editor::updateAllSize(int size){
    this->drawzone->setPenWidth(1);
    if(size == 1)
        this->drawzone->setPenWidth(3);
    if(size == 2)
        this->drawzone->setPenWidth(8);
    if(size == 3)
        this->drawzone->setPenWidth(15);
    ui->penSize->changeSize(size);
    ui->traitSize->changeSize(size);
    ui->eraserSize->changeSize(size);
}

void Editor::saveCurrentDraw(){
    QLabel* label = (QLabel*)ui->thumbnailsList->itemWidget(ui->thumbnailsList->item(this->currentIndex));
    if(label == NULL) return;

    QFileInfo pictName(QFileInfo(label->toolTip()));
    QString drawName(project->getProjectDir().absolutePath() + "/drawings/" + pictName.completeBaseName() + ".draw" + ".png");

    this->drawzone->save(drawName, QPixmap(label->toolTip()).size());
}

void Editor::close_project(){
    this->close();
}

void Editor::exportDrawWithMovie(){
    QString drawMovie(QFileDialog::getSaveFileName(this, tr("Export the drawings with the movie"),
                                                    project->getName() + "-drawmovie.mp4",
                                                    tr("Files (*.mp4)")));
    this->saveCurrentDraw();

    if(!drawMovie.endsWith(".mp4")){
        drawMovie += ".mp4";
    }

    // Export
    QStringList args;
    args << "-r" << QString::number(6);
    args << "-i" << project->getName() + "-%03d.draw.png";
    args << drawMovie;

    QProcess command;
    command.setWorkingDirectory(project->getProjectDir().absolutePath()+"/drawings");
    command.start("avconv", args);
    command.waitForFinished(1000*1000); // 1000sec, otherwise it cuts itself

    QMessageBox::information(this, "Export of the drawings", "The video was generated from the drawings with success");
}

Editor::~Editor()
{
    delete ui;
}
