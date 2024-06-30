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
    Y = name + " HELLO " + name1;
    Y.print(); // проверка сложения MyString с С строкой
    Y = " HELLO " + name1;
    Y.print(); // проверка сложения С строкой c MyString
    mystring Equate{};
    Equate = xy1;
    Equate.print(); 
    Equate = Y;
    Equate.print(); // Оператор приравнивания проверен
    std::cout << Equate[2] << " 3 символ равен 'r'" << std::endl;
    Equate[2] = '9';
    std::cout << Equate[2] << " 3 символ равен '9'" << std::endl;
    Equate.print(); // Оператор [] проверен в двух исполнениях
    name = "getstscv"; 
    name1 = "get";
    std::cout << "Проверка равенства двух строк " << (name == name1) << std::endl; // при равенстве все ок
    mystring IsOperator;
    std::cin >> IsOperator;
    IsOperator.print(); // проверка корректности ввода текста пользователем
    std::cout << name1 << std::endl;


    return 0;
}