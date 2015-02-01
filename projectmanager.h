#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include <QVector>
#include "project.h"
#include <QDir>
#include <QDomDocument>
#include <QCoreApplication>
/**
* @class ProjectManager
* @brief manage projects
*/
class ProjectManager
{
/**
* @brief List of projects
*/
QVector<Project*>* projects;
/**
* @brief Current project
*/
Project* currentProject;
public:
/**
* @brief Default constructor
*/
ProjectManager();
/**
* @brief getProject
* @return project list
*/
QVector<Project*>* getProjects();
/**
* @brief getCurrentProject
* @return project object
*/
Project* getCurrentProject();
/**
* @brief getName
* @param index : index of projects list
*/
void setCurrentProject(int index);
/**
* @brief updateProjects
*/
void updateProjects();
/**
* @brief addProject
* @param dir : project directory
*/
void addProject(QDir* dir);
};
#endif // PROJECTMANAGER_H
