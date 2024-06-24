// MyString_vork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "mystring.h"

int mystring::count = 0;

int main()
{
    setlocale(LC_ALL, "ru");
    char xy[] = "help";
    std::cout << xy << " " << strlen(xy) << std::endl;
    mystring name{xy};
    name.print(); // проверка метода печати
    mystring name1{ name };
    name1.print(); // проверка корректности глубокого копирования
    char xy1[] = "forever";
    name.setmString(xy1);
    name.print();
    mystring Y = name + name1;
    Y.print(); // проверка оператора сложения (позже проверить несколько одновременных сложений)
    mystring Equate{};
    Equate = xy1;
    Equate.print(); // Проверка оператора приравнивания - не проверен еще

    return 0;
}