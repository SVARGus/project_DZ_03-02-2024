// Class_Home-Apartment-Person.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "HomeApartmentPerson.h"

int Apartment::count = 0;

int main()
{
    setlocale(LC_ALL, "ru");

    // Блок теста Персоны - позже закоментировать
    //Person First{ "Kuznetsov Pavel Nikolatvich", 35 }; // OK
    //First.print(); // OK
    //std::cout << First.getFIO() << " " << First.getAge() << std::endl; // OK
    //std::cout << "Введите ФИО и возраст: "; // OK
    //std::cin >> First; // OK
    //First.print(); // OK
    //Person Second = First; // OK
    //Second.print(); // OK
    
    // Конец блока теста Персоны
    //------------------------------------------------------------------
    // Блок теста Квартиры - позже закоментировать
    Person F1{ "Arg A G", 33 };
    Person F2{ "Kuz A G", 25 };
    Person F3{ "Lot A G", 15 };
    Person F4{ "Fiv A G", 27 };
    Person F5{ "Fist A G", 20 };
    Apartment First{ 3 };
    First.freeRegistrPerson(F1);
    First.freeRegistrPerson(F2);
    First.freeRegistrPerson(F3);
    First.freeRegistrPerson(F4);
    First.freeRegistrPerson(F5);
    First.print();

    // Конец блока теста Квартиры

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
