
#ifndef PROJECT_H
#define PROJECT_H
#include <QString>
#include <QVector>
#include <QDir>
/**
* @class Project
* @brief manage pawns type and rules
*/
class Project
{
/**
* @brief Project name
*/
QString name;
/**
* @brief Project description
*/
int fps;
/**
* @brief Project input file
*/
QString file;

QDir projectDir;
public:
/**
* @brief Create a new project
* @param aName project name
* @param aDescription project description
* @param aFile project input file
*/
Project(QString aName, int aFps, QString aFile);
/**
* @brief getName
* @return project name
*/
QString getName();
/**
* @brief getDescription
* @return project description
*/
int getFps();
/**
* @brief getVersion
* @return project version
*/
QString getFile();

QDir getProjectDir();
void setProjectDir(QDir dir);
};
#endif // PROJECT_H
