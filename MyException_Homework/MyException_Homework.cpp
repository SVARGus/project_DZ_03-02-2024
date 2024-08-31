/*
Создать свой класс Exception

Задание 2.

1) Деление на ноль
2) Ввод числа вместо буквы
3) Выход за границы массива(матрицы). Матрица 2х2, мы, к примеру, перемножаем элементы (3;3)
4) Неверный тип входных параметров(вместо Int пишем double)

*/

#include <iostream>
#include "MyException.h"
// подключить класс матрица из ДЗ по шаблонам классов (также добавить туда поимку исключений)

using std::cout;
using std::cin;
using std::endl;
using std::string;

double deleteNum(int x, int y) {
	if (y == 0)
	{
		throw MyEsception("Делить на 0 нельзя");
	}
	return (double)x / y;
}

int main()
{
    setlocale(LC_ALL, "ru");

	int x{ 5 };
	int y{};
	try
	{
		cout << deleteNum(x, y);
	}
	catch (MyEsception &ex)
	{
		cout << ex.what() << endl;
		cout << "Код ошибки: " << ex.getDateState() << endl;
	}

    return 0;
}

