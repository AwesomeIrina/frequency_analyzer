#include "files_manager.h"

symbol_analyzer::symbol_analyzer()
{

}

void symbol_analyzer::textRead(QString pathToFile)
{
   //pathToFile = "D:\QtProjects\file_manager\Test_1\123.txt";
   QTextStream out(stdout);
   QFile file(pathToFile);
   QTextStream in(&file);
   if (!file.open(QIODevice::ReadOnly)) {
     qWarning("Cannot open file for reading");
   }
   QString text;
   //считываем весь текст из файла построчно
   while (!in.atEnd()) {
     text += in.readLine().trimmed().toLower() + " ";
   }
   file.close();
   //занесли все символы в мапу
   for(int i = 0; i<text.size(); i++){
       frequency.insert(std::pair<QString, int>(text[i], 0));
   }
   //теперь идём по строке и считаем количество символов
   for(int i = 0; i<text.size(); i++){
       for(auto it = frequency.begin(); it!=frequency.end();it++){
           if(text[i] == it->first){
               it->second+=1;
           }
       }
   }
   for(auto it = frequency.begin(); it!=frequency.end();it++){
       out << it->first <<" "<<it->second << endl;
   }

}

void symbol_analyzer::helpCout(){
    std::cout << "add /path/ - to add file for checking" << std::endl;
    std::cout << "pop - to see five the most popular symbols" << std::endl;
    std::cout << "unpop - to see three unpopulat symbols" << std::endl;
    std::cout << "probab /symbol/ - to see five the probability of your symbol" << std::endl;

}

void symbol_analyzer::console()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    QString command;
    QTextStream cout(stdout), cin(stdin);
    command = cin.readLine().trimmed().toLower();
    textRead(command);
    //changesCheck();
//    while(true){
//                std::cout << "Input the command: " << std::endl;
//        command = cin.readLine().trimmed().toLower();
//        if(command!="help" && command!="add" && command != "pop" && command != "unpop" && command != "probab"){
//            std::cout << "Incorrect command! Input 'help' to see the list of commands" << std::endl;

//        }

//        if(command=="help"){
//            helpCout();
//     }

//        if(command=="add"){
//           std::cout<<"enter your path to the file: "<<std::endl;
//           QString pathToFile;
//           pathToFile=cin.readLine().trimmed().toInt();
//           //textRead(pathToFile);

//       }
//    }
    //changesCheck();

}
