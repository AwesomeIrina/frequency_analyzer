#include "files_manager.h"
#include <thread>
#include <mutex>

std::mutex mtx;

symbol_analyzer::symbol_analyzer()
{
    console();
}

void symbol_analyzer::probability()
{
    if(symbNum.empty()){
        std::cout<<"First you need to add some text"<<std::endl;
    }else{
        QTextStream out(stdout), cin(stdin);
        std::cout<<"Input the symbol: "<<std::endl;
        QString symbol;
        symbol = cin.readLine().trimmed().toLower();
        int counter = 0;
        for(auto it = symbNum.begin(); it != symbNum.end(); it++){
            counter+=it->second;
        }
        out<<symbNum[symbol]<<endl;
        double probab = double(symbNum[symbol])/double(counter);
        std::cout<<double(probab)<<std::endl;
    }
}

void symbol_analyzer::frequency(QString command)
{
    if(symbNum.empty()){
        std::cout<<"First you need to add some text"<<std::endl;
    }else{
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
        }
    }

}

void symbol_analyzer::textRead(QString pathToFile)
{
   QTextStream cout(stdout);
   QFile file(pathToFile);
   QTextStream in(&file);
   in.setCodec("UTF-8");
   if (!file.open(QIODevice::ReadOnly)) {
     qWarning("Cannot open file for reading");
   }else{
       QString text;
       //считываем весь текст из файла построчно
       while (!in.atEnd()) {
         text += in.readLine().trimmed().toLower() + " ";
       }
       file.close();
       int split = text.size()/2;
       std::map<QString, int> saver;
       std::thread th([&](){
           for(int i = 0; i<split; i++){
               saver.insert(std::pair<QString, int>(text[i], 0));
           }
           //теперь идём по строке и считаем количество символов
           for(int i = 0; i<split; i++){
               for(auto it = saver.begin(); it!=saver.end();it++){
                   if(text[i] == it->first){
                       it->second+=1;
                   }
               }
           }
       });
       std::thread th1([&,this](){
           for(int i = split; i<text.size(); i++){
               symbNum.insert(std::pair<QString, int>(text[i], 0));
           }
           //теперь идём по строке и считаем количество символов
           for(int i = split; i<text.size(); i++){
               for(auto it = symbNum.begin(); it!=symbNum.end();it++){
                   if(text[i] == it->first){
                       it->second+=1;
                   }
               }
           }
       });
       th.join();
       th1.join();

       for(auto it = symbNum.begin(); it != symbNum.end(); it++){
           for(auto it_saver = saver.begin(); it_saver != saver.end(); it_saver++){
               if(it->first == it_saver->first){
                   it->second+=it_saver->second;
               }
           }
       }
   }
}

void symbol_analyzer::helpCout(){
    std::cout << "add - to add file for checking" << std::endl;
    std::cout << "popular - to see five the most popular symbols" << std::endl;
    std::cout << "unpopular - to see three unpopulat symbols" << std::endl;
    std::cout << "probab - to see five the probability of your symbol" << std::endl;
}

void symbol_analyzer::commands(QString command)
{
    QTextStream cout(stdout), cin(stdin);

    if(command!="help" && command!="add" && command != "popular" && command != "unpopular" && command != "probab"){
        std::cout << "Incorrect command! Input 'help' to see the list of commands" << std::endl;
    }

    if(command=="help"){
        helpCout();
    }

    if(command=="add"){
        std::cout<<"enter your path to the file: "<<std::endl;
        QString pathToFile;
        pathToFile=cin.readLine();
        textRead(pathToFile);
        std::cout<<"All symbols:"<<std::endl;
        for(auto it = symbNum.begin(); it != symbNum.end(); it++){
            cout<<it->first+"->"<<it->second<<endl;
        }
    }

    if(command=="popular"){
        frequency("popular");
    }

    if(command=="unpopular"){
        frequency("unpopular");
    }

    if(command=="probab"){
        probability();
    }
}

void symbol_analyzer::console()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    QString command;
    QTextStream cout(stdout), cin(stdin);
    while(true){
        std::cout << "Input the command: " << std::endl;
        command = cin.readLine().trimmed().toLower();
        commands(command);
    }

}
