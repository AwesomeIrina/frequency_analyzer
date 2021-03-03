#include "files_manager.h"

symbol_analyzer::symbol_analyzer()
{

}

void symbol_analyzer::textRead(QString pathToFile)
{
   QTextStream out(stdout);
   QFile file(pathToFile);
   // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
   QTextStream in(&file);
   // С помощью метода open() открываем файл в режиме чтения
   if (!file.open(QIODevice::ReadOnly)) {
     qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
   }
   // Считываем файл строка за строкой
   while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
     QString line = in.readLine(); // метод readLine() считывает одну строку из потока
     out << line << endl;
   }

   // Закрываем файл
   file.close();
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
