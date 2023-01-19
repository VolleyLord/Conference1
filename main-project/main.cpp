

#include <iostream>

using namespace std;

#include"conf_prog.h"
#include"Constants.h"
#include"file_reader.h"


void output(conf_prog* rose)
{
    cout << "Автор доклада....   ";
    cout << rose->reader.first_name << ' ';
    cout << rose->reader.maddle_name << ' ';
    cout << rose->reader.last_name << '\n';
    cout << "Начало доклада....  ";
    cout << rose->start.hour << ':';
    cout << rose->start.min << '\n';
    cout << "Конец доклада...    ";
    cout << rose->finish.hour << ':';
    cout << rose->finish.min << '\n';
    cout << "Тема доклада....    ";
    cout << rose->title << '\n';
    cout << '\n';
}



int main()
{

    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #2. Conference Program\n";
    cout << "Author: Buinov Artem\n";
    cout << "Group 14\n";

    setlocale(LC_ALL, "RUSSIAN");
    cout << "Лабораторная работа #9.GIT\n";
    cout << "Вариант #2. Программа конференции\n";
    cout << "Автор: Буйнов Артем\n";
    conf_prog* roses[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", roses, size);
        cout << "-----Программа конференции-----\n\n";
        for (int i = 0; i < size; i++)
        {
            output(roses[i]);
        }
       

        for (int i = 0; i < size; i++)
        {
            delete roses[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    return 0;
}
