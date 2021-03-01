#ifndef FILES_MANAGER_H
#define FILES_MANAGER_H
#include <iostream>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QTextStream>
#include <fstream>
#include <map>
#include <QVector>
#include <windows.h>

class files_manager
{
public:
    files_manager();
    void textRead(QString pathToFile);
    void commandAnalize(QString&);
    void console();
    void changesCheck();
    void check(const QString& condition, const QString& path);
private:
    std::map<char, int> frequency;
    QVector<QString> filesNames;
};

#endif // FILES_MANAGER_H
