#include "project.h"

Project::Project(QString aName, int aFps, QString aFile)
{
    this->name = aName;
    this->fps = aFps;
    this->file = aFile;
}

QString Project::getName()
{
    return this->name;
}

int Project::getFps()
{
    return this->fps;
}

QString Project::getFile()
{
    return this->file;
}

QDir Project::getProjectDir()
{
    return this->projectDir;
}

void Project::setProjectDir(QDir dir)
{
    this->projectDir = dir;
}



