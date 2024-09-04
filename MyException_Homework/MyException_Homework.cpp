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
#include "Matrix.h"
#include <limits>
// подключить класс матрица из ДЗ по шаблонам классов (также добавить туда поимку исключений)

using std::cout;
using std::cin;
using std::endl;
using std::string;

double deleteNum(int x, int y) {
	if (y == 0)
	{
		throw MyEsception("Делить на 0 нельзя", 0);
	}
	return (double)x / y;
}

int main()
{
    setlocale(LC_ALL, "ru");
	// 1
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
	// 2
	char simbol{};
	cout << "Введите букву: ";
	try
	{
		cin >> simbol;
		if (simbol >= '0' && simbol <= '9')
		{
			throw MyEsception("Введено число вместо буквы");
		}
		if (cin.peek() != '\n') // если введено более одного символа
		{
			//cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw MyEsception("Ошибка ввода! Введено несколько символов в место одного");
		}
	}
	catch (MyEsception& ex)
	{
		cout << ex.what() << endl;
	}
	// 3
	int row{};
	int col{};
	cout << "Введите размер матрицы: количество строк: "; 
	cin >> row;
	cout << "И количество столбцов: ";
	cin >> col;
	Matrix<int> Array{ row, col };
	Array.genMatrix();
	Array.printMatrix();
	cout << endl;
	try
	{
		cout << "Укажите индекс для обращения к данным из массива: ";
		cin >> row >> col;
		cout << "Значение массива = " << Array(row, col) << endl;
	}
	catch (MyEsception& ex)
	{
		cout << ex.what() << endl;
		cout << "Code Error: " << ex.getDateState() << endl;
	}
	// 4
	double num{};
	cout << "Введите целое число: ";
	try
	{
		int x{};
		cin >> num;
		if (0 != (num - (int) num))
		{
			throw MyEsception ("Указано дробное число");
		}
	}
	catch (MyEsception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	

    return 0;
}

