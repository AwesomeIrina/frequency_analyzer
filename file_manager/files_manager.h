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
    void console();
    void helpCout();
    void frequency(QString command);
    void probability();
    void commands(QString command);
private:
    std::map<QString, int> symbNum;
    QVector<QString> filesNames;
};

#endif // FILES_MANAGER_H
