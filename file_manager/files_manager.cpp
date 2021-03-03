#include "files_manager.h"
#include <vector>



symbol_analyzer::symbol_analyzer()
{
    console();
}

void symbol_analyzer::frequency(QString command)
{
    QTextStream out(stdout);
    std::map<QString, int> copy;
    copy = symbNum;
    int counter = 0;
    int tmp;

    if(command == "popular"){
        tmp = 0;
        QString popular[5];
        std::cout<<"Five the most popular symbols in the text:"<<std::endl;
        while(counter!=5){
            for(auto it = copy.begin(); it != copy.end(); it++){
                if(it->second >= tmp){
                    tmp = it->second;
                    popular[counter] = it->first;
                }
            }
            out<<popular[counter]<<"-->"<<copy[popular[counter]]<<endl;
            copy[popular[counter]] = -1;
            tmp = 0;
            counter += 1;
        }
    }

    if(command == "unpopular"){
        QString unpopular[3];
        tmp = symbNum.size();
        std::cout<<"Three unpopular symbols in the text:"<<std::endl;
        while(counter!=3){
            for(auto it = copy.begin(); it != copy.end(); it++){
                if(it->second <= tmp){
                    tmp = it->second;
                    unpopular[counter] = it->first;
                }
            }
            out<<unpopular[counter]<<"-->"<<copy[unpopular[counter]]<<endl;
            copy[unpopular[counter]] = 1000;
            tmp = symbNum.size();
            counter += 1;
        }
        std::cout<<"End"<<std::endl;
    }
}

void symbol_analyzer::textRead(QString pathToFile)
{
   //pathToFile = "D:\QtProjects\file_manager\Test_1\123.txt";
   QTextStream out(stdout);
   QFile file(pathToFile);
   QTextStream in(&file);
   in.setCodec("UTF-8");
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
       symbNum.insert(std::pair<QString, int>(text[i], 0));
   }
   //теперь идём по строке и считаем количество символов
   for(int i = 0; i<text.size(); i++){
       for(auto it = symbNum.begin(); it!=symbNum.end();it++){
           if(text[i] == it->first){
               it->second+=1;
           }
       }
   }
   std::cout<<"All symbols:"<<std::endl;
   for(auto it = symbNum.begin(); it != symbNum.end(); it++){
       out<<it->first+"->"<<it->second<<endl;
   }
}

void symbol_analyzer::helpCout(){
    std::cout << "add /path/ - to add file for checking" << std::endl;
    std::cout << "popular - to see five the most popular symbols" << std::endl;
    std::cout << "unpopular - to see three unpopulat symbols" << std::endl;
    std::cout << "probab /symbol/ - to see five the probability of your symbol" << std::endl;
}

void symbol_analyzer::console()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    QString command, command1;
    QTextStream cout(stdout), cin(stdin);
    command = cin.readLine().trimmed().toLower();
    textRead(command);
    frequency("unpopular");
    //changesCheck();
//    while(true){
//                std::cout << "Input the command: " << std::endl;
//        command = cin.readLine().trimmed().toLower();
//        if(command!="help" && command!="add" && command != "popular" && command != "unpopular" && command != "probab"){
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
