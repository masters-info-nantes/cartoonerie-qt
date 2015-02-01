#include "project.h"

Project::Project(QString aName, QString aDescription, QString aFile)
{
    this->name = aName;
    this->description = aDescription;
    this->file = aFile;
}

QString Project::getName()
{
    return this->name;
}

QString Project::getDescription()
{
    return this->description;
}

QString Project::getFile()
{
    return this->file;
}




