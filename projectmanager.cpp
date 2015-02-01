#include "projectmanager.h"

ProjectManager::ProjectManager()
{
  ProjectManager::updateProjects();
  if(this->getProjects()->size()>0)
      this->currentProject= this->projects->at(0);
  else
      this->currentProject=0;
}

QVector<Project*>* ProjectManager::getProjects()
{
    return this->projects;
}

Project* ProjectManager::getCurrentProject()
{
    return this->currentProject;
}

void ProjectManager::setCurrentProject(int index)
{
        if(index >= 0 && index < this->projects->size())
                this->currentProject = this->projects->at(index);
}

void ProjectManager::addProject(QDir* dir) {
    QDomDocument doc;
    QFile projectXmlFile(dir->absolutePath()+QDir::separator()+"project.xml");
    if(!projectXmlFile.exists()) {
        qDebug("error project.xml not exist "+dir->absolutePath().toUtf8());
        return;
    }
    projectXmlFile.open(QIODevice::ReadOnly);
    doc.setContent(&projectXmlFile);
    projectXmlFile.close();
    QDomElement project = doc.documentElement();
    QString name = project.lastChildElement("name").text();
    QString description = project.lastChildElement("description").text();
    QString file = project.lastChildElement("file").text();
    Project* p =  new Project(name, description,file);
    qDebug("Project: "+name.toUtf8());

    projects->push_back(p);
}

void ProjectManager::updateProjects()
{
    this->projects = new QVector<Project*>();
    QDir projectdir = QCoreApplication::applicationDirPath(); // current directory (build directory)
    #ifdef Q_OS_MAC
        projectdir=QCoreApplication::applicationDirPath()+"/../../.."; // to exit mac application package
    #endif
    QDir* dir = new QDir(projectdir.absolutePath()+QDir::separator()+"projects");
    qDebug(dir->absolutePath().toUtf8());
    if (dir->exists())
    {
        QFileInfoList entries = dir->entryInfoList( QDir::Dirs | QDir::NoDotAndDotDot);
        foreach ( QFileInfo info, entries )
        {
            if (info.isDir()) {
                addProject(new QDir(info.absoluteFilePath()));
            }
        }
    }
    else
    {
        projectdir.mkdir("projects");
    }

}

