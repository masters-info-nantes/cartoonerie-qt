#include "project.h"

Project::Project(QString aName, QString aDescription, QString aVersion)
{
    this->name = aName;
    this->description = aDescription;
    this->version = aVersion;
}

QString Project::getName()
{
    return this->name;
}

QString Project::getDescription()
{
    return this->description;
}

QString Project::getVersion()
{
    return this->version;
}




