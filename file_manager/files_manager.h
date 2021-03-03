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

class symbol_analyzer
{
public:
    symbol_analyzer();
    void textRead(QString pathToFile);
    void commandAnalize(QString&);
    void console();
    void changesCheck();
    void helpCout();
    void check(const QString& condition, const QString& path);
private:
    std::map<char, int> frequency;
    QVector<QString> filesNames;
};

#endif // FILES_MANAGER_H
