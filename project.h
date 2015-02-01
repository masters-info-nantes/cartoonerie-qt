
#ifndef PROJECT_H
#define PROJECT_H
#include <QString>
#include <QVector>
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
QString description;
/**
* @brief Project input file
*/
QString file;
public:
/**
* @brief Create a new project
* @param aName project name
* @param aDescription project description
* @param aFile project input file
*/
Project(QString aName, QString aDescription, QString aFile);
/**
* @brief getName
* @return project name
*/
QString getName();
/**
* @brief getDescription
* @return project description
*/
QString getDescription();
/**
* @brief getVersion
* @return project version
*/
QString getFile();
};
#endif // PROJECT_H
