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
    name1.print();
    char xy1[] = "forever";
    name.setmString(xy1);
    name.print();
    mystring Y = name + name1;
    Y.print();

    return 0;
}