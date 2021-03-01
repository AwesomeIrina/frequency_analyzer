#include "files_manager.h"

files_manager::files_manager()
{

}



void files_manager::console()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Input 'help' to get the list of the commands" << std::endl;
    QString command;
    QTextStream cout(stdout), cin(stdin);
    command = cin.readLine().trimmed().toLower();
    //changesCheck();
    while(true){
        if(command!="help" || command!="add" || command != "pop" || command != "unpop" || command != "probab"){
            std::cout << "Incorrect command!" << std::endl;

        }

        if(command=="help"){
           std::cout << "add /path/ - to add file for checking" << std::endl;
           std::cout << "pop - to see five the most popular symbols" << std::endl;
           std::cout << "unpop - to see three unpopulat symbols" << std::endl;
           std::cout << "probab /symbol/ - to see five the probability of your symbol" << std::endl;
       }

        if(command=="add"){
           std::cout<<"enter your path to the file: "<<std::endl;
           QString pathToFile;
           pathToFile=cin.readLine().trimmed().toInt();
           //textRead(pathToFile);

       }
    }
    //changesCheck();

}
