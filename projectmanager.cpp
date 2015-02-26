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

Project* ProjectManager::addProject(QDir* dir) {
    QDomDocument doc;
    QFile projectXmlFile(dir->absolutePath()+QDir::separator()+"project.xml");
    if(!projectXmlFile.exists()) {
        qDebug("error project.xml not exist "+dir->absolutePath().toUtf8());
        return NULL;
    }
    projectXmlFile.open(QIODevice::ReadOnly);
    doc.setContent(&projectXmlFile);
    projectXmlFile.close();
    QDomElement project = doc.documentElement();
    QString name = project.lastChildElement("name").text();
    int fps = project.lastChildElement("fps").text().toInt();
    QString file = project.lastChildElement("file").text();
    Project* p =  new Project(name, fps,file);
    p->setProjectDir(*dir);
    qDebug("Project: "+name.toUtf8());

    projects->push_back(p);
    return p;
}

void ProjectManager::createProject(Project* p)
{
    QString timestamp = QString::number(QDateTime::currentMSecsSinceEpoch());
    this->projectDir->mkdir(timestamp);

    QDir current = *projectDir;
    current.cd(timestamp);
    qDebug(current.absolutePath().toUtf8());

    p->setProjectDir(current);

    QFile file(current.absolutePath()+QDir::separator()+"project.xml");
      file.open(QIODevice::WriteOnly);
      QXmlStreamWriter xmlWriter(&file);
      xmlWriter.setAutoFormatting(true);
      xmlWriter.writeStartDocument();
      xmlWriter.writeStartElement("project");
      xmlWriter.writeTextElement("name", p->getName());
      xmlWriter.writeTextElement("fps", QString::number(p->getFps()));
      xmlWriter.writeTextElement("file", p->getFile());
      xmlWriter.writeEndElement();
      xmlWriter.writeEndDocument();
      file.close();

      current.mkdir("video_frames");
      current.mkdir("drawings");
      current.cd("video_frames");
      // Split movie with avconv

      QStringList args;
      args << "-i" << p->getFile();
      args << "-r" << QString::number(p->getFps());// TODO save fps + manage to insert inside project
      args << p->getName() + "-%3d.jpeg";

      /*
       * For osx systems, avconv must be in /usr/bin
       * - test with "which avconv"
       * - if not do a symbolic link:
       *   ln -s /usr/local/bin/avconv /usr/bin/avconv
       */
      //QProcess::execute("avconv", args);
      QProcess command;
      command.setWorkingDirectory(current.absolutePath());
      command.start("avconv", args);// TODO detect avconv or avconv installation
      command.waitForFinished();

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
    this->projectDir = dir;
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

