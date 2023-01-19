

#include <iostream>

using namespace std;

#include"conf_prog.h"
#include"Constants.h"
#include"file_reader.h"


void output(conf_prog* rose)
{
    cout << "����� �������....   ";
    cout << rose->reader.first_name << ' ';
    cout << rose->reader.maddle_name << ' ';
    cout << rose->reader.last_name << '\n';
    cout << "������ �������....  ";
    cout << rose->start.hour << ':';
    cout << rose->start.min << '\n';
    cout << "����� �������...    ";
    cout << rose->finish.hour << ':';
    cout << rose->finish.min << '\n';
    cout << "���� �������....    ";
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
    cout << "������������ ������ #9.GIT\n";
    cout << "������� #2. ��������� �����������\n";
    cout << "�����: ������ �����\n";
    conf_prog* roses[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", roses, size);
        cout << "-----��������� �����������-----\n\n";
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
