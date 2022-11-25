// dz_files2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>


/*
 Дан текстовий файл. Знайти і замінити в ньому задане слово. 
 Що шукати і на що заміняти визначається користувачем.
*/
int main() {
    const char readername[] = "file.txt";
    const char writername[] = "fole.txt";

    char find[10];
    puts("Enter the word that should be replaced: ");
    std::cin.getline(find, 10);             // пользователь вводит слово под замену

    char replace[10];
    puts("The word you want to insert: ");
    std::cin.getline(replace, 10);          // пользователь вводит слово на замену

    const size_t MAX_STR = 256;             // размер буфера
    char str[MAX_STR];

    std::ifstream reader;                   // файловая переменная для чтения
    std::ofstream writer;                   // файловая переменная для записи замены

    reader.open(readername);
    if (!reader) {
        std::cout << "Reader open error" << std::endl;
        return -1;
    }
    
    writer.open(writername);
    if (!writer) {
        std::cout << "Writer open error" << std::endl;
        return -2;
    }
 
    while (!reader.eof()) {
        reader >> str;                      // считываем строку
        if (strcmp(str, find) == 0) {       // если найдено совпадение
            writer << replace << " ";       // записать замену в  writer
        }
        else {
            writer << str << " ";
        }      
    }  
    writer.flush();
    reader.close();
    writer.close();

    return 0;
}


/*
 Завдання 1. Дан текстовий файл. Видалити з нього останній рядок. 
 Результат записати в інший файл.
*/
int main3() {
    std::ifstream reader;                               
    std::ofstream writer;  
    const std::string file2 = "file2.txt";      // константы для типа файла
    const std::string file = "file.txt";        // константы для типа файла

    short rows = 0;                             // переменная для подсчета строк
    const size_t BUF = 100;                     // буфер для строки
    char str[BUF];
    char str2[BUF];
    
    
    writer.open(file2);  
    if (!writer) {                              // проверка открылся ли файл  
        std::cout << "Writer open error" 
            << std::endl;
        return -1;
    }

    reader.open(file);
    if (!reader) {                              // проверка открылся ли файл
        std::cout << "Reader open error" 
            << std::endl;
        return -1;
    }
    
    while (!reader.eof()) {                     // цикл - пока не конец файла
        reader.getline(str, BUF);               // считываем строку
        rows++;                                 // добавляем кол-во строк
    }
    reader.close();                             // закрыть файл                                 
    reader.open(file);                          // и снова открыть, чтобы дальше
                                                //  проводить следующие действия
    if (!reader)                                // проверка открылся ли файл
    {
        std::cout << "Reader open error" 
            << std::endl;
        return -2;
    }

    for (size_t i = 0; i < rows - 1; i++) {     // цикл до кол-ва строк минус 1
        reader.getline(str2, BUF);              // считываем и выводим строку
        writer << str2 << std::endl;
    }
    writer.flush();
    reader.close(); 
    writer.close();

    return 0;   
}

/*
 Завдання 2. Дан текстовий файл. Знайти довжину найдовшого рядка.
*/
int main2() {
    const size_t MAX_STR = 256;                    // размер буфера (макс длина строки)
    char str[MAX_STR];                             // буфер для хранения строки файла
    const char filename[] = "file.txt";            // имя файла

    size_t max_length = 0;
    std::ifstream reader(filename);                // открываем файл
    if (!reader) {                                 // проверка - открылся ли файл
        std::cout << "Reader open error";  
        return -1;                         
    }
    while (!reader.eof()) {
        reader.getline(str, MAX_STR);              // читаем строку
        size_t length = strnlen_s(str, MAX_STR);   // длина строки
        if (length > max_length) {                 // сравниваем длину с максимальной, если есть длиннее
            max_length = length;                   // то заменяем макс на эту найденную
        }
    }
    reader.close();
    std::cout << "Max length of file's string = " << max_length << std::endl;
    return 0;
}


int main1()
{
    std::ofstream writer;
    std::ifstream reader;
    const char filename[] = "file.txt";  // константа для типа файла

    writer.open("filename");             // по своему типу (ofstream) файл - на запись 
                                         //  (сразу же открывается в режиме записи)
    if (!writer) {                       // проверка - открылся ли файл
        std::cout << "Writer open error" 
            << std::endl;
        return -1;
    }
    writer << "String 1 in file\n"       // запись данных в файл
        << "String 2 in next line\n"     // запись данных в файл
        << "String 3 in next line";      // запись данных в файл

    writer.flush();                      // чтобы данные попали на диск
    writer.close();                      // закрываем файл - освобождаем системный ресурс

    return 0;
}

