

#include "pch.h" 
#include "CppUnitTest.h" 
#include "../main-project/conf_prog.h" 
#include "../main-project/processing.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{

    conf_prog* build_Confirence(int start_hour, int start_minutes, int finish_hour, int finish_minutes)
    {
        conf_prog* Confirences = new conf_prog;
        Confirences->start.hour = start_hour;
        Confirences->start.min = start_minutes;
        Confirences->finish.hour = finish_hour;
        Confirences->finish.min = finish_minutes;
        return Confirences;
    }


    void delete_Confirence(conf_prog* array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            delete array[i];
        }
    }

    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestMethod1) // время охватывает некий диапазон времени(часов) 
        {
            conf_prog* conf_prog[3];
            conf_prog[0] = build_Confirence(10, 10, 13, 10); // 2 часа 
            conf_prog[1] = build_Confirence(11, 10, 15, 10); // 4 часа 
            conf_prog[2] = build_Confirence(13, 30, 16, 30); // 3 часа 
            /*Assert::AreEqual(240, process(conf_prog, 3));*/
            delete_Confirence(conf_prog, 3);
        }

        TEST_METHOD(TestMethod2) // время охватывает 1 час 
        {
            conf_prog* conf_prog[3];
            conf_prog[0] = build_Confirence(10, 10, 11, 10); // 1 час 
            conf_prog[1] = build_Confirence(11, 10, 12, 10); // 1 час 
            conf_prog[2] = build_Confirence(12, 30, 13, 30); // 1 час 
            /*Assert::AreEqual(60, process(conf_prog, 3));*/
            delete_Confirence(conf_prog, 3);
        }

        TEST_METHOD(TestMethod3) // время до обеда/после обеда 
        {
            conf_prog* conf_prog[2];
            conf_prog[0] = build_Confirence(00, 00, 12, 00); // 12 часов  
            conf_prog[1] = build_Confirence(12, 00, 23, 59); // 11 часов 59 минут 
           /* Assert::AreEqual(720, process(conf_prog, 2));*/
            delete_Confirence(conf_prog, 2);
        }
    };
}