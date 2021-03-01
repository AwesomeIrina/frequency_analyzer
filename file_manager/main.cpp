#include <QCoreApplication>
#include "files_manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    files_manager obj;
    obj.console();


    return a.exec();
}
