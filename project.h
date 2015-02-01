
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
* @brief Project version
*/
QString version;
public:
/**
* @brief Create a new project
* @param aName project name
* @param aDescription project description
* @param aVersion project version
*/
Project(QString aName, QString aDescription, QString aVersion);
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
QString getVersion();
};
#endif // PROJECT_H
