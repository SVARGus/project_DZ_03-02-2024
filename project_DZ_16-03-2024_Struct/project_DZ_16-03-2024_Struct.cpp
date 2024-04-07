/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Структуры
*/

/*
Задание 1:
Создайте структуру, описывающую комплексное число. Реализуйте арифметические операции с комплексными числами: сумму, разность, умножение, деление.

Задание 2:
Реализовать структуру «Автомобиль» (длина, клиренс (высота посадки), объем двигателя, мощность двигателя, диаметр колес, цвет, тип коробки передач). 
Создайте функции для задания значений, отображения значений, поиска значений.

Задание 3:
Разработайтепрограмму«Библио тека».Создайтеструктуру«Книга»( название,автор, издательство, жанр). 
Создайте массив из 10 книг. Реализуйте для него следующие возможности:
Редактировать книгу Печать всех книг Поиск книг по автору Поиск книги по названию Сортировка массива 
по наз ванию книг Сортировка массива по автору Сортировка массива по издательству 

Задание 4:
Реализовать структуру «Машина» (цвет, модель, номер). Номер машины может представлять из себя или пятизначный номер или слово до 8 символов.
Рекомендации: номер реали зовать как объединение.
Создать экземпляр структуры «Машина» и реализовать для него следующие функции:
Заполнение машины Печать машины Домашнее задание № 8 Создать массив из 10 экземпляров структуры «Машина» и реализовать для него следующие функции:
Редактировать машину Печать всех машин Поиск машины по номеру
*/

#include <iostream>
#include <Windows.h>

Complex_Number Arithmetic(Complex_Number Z1, Complex_Number Z2, char Arit);

/*
Шпаргалка по Заданию 1 
Комлпексное число z = a + bi
где a (с) это вещественные числа
b (d) мнимые числа

Сложение (a + bi) + (c + di) = (a + c) + (b + d)i
вычитание (a + bi) - (c + di) = (a - c) + (b - d)i
умножение (a + bi) * (c + di) = (ac – bd) + (ad + bc)i
деление (a + bi) / (c + di) = ((ac + bd)/(cc + dd)) + ((bc - ad)/(cc + dd))i
*/
struct Complex_Number {
	int RealNum; // Вещественные числа
	int ImaginaryNum; // Мнимые числа
};

Complex_Number Arithmetic(Complex_Number Z1, Complex_Number Z2, char Arit)
{
	Complex_Number Result;
	if (Arit == '+')
	{
		Result.RealNum = Z1.RealNum + Z2.RealNum;
		Result.ImaginaryNum = Z1.ImaginaryNum + Z2.ImaginaryNum;
	}
	else if (Arit == '-')
	{
		Result.RealNum = Z1.RealNum - Z2.RealNum;
		Result.ImaginaryNum = Z1.ImaginaryNum - Z2.ImaginaryNum;
	}
	else if (Arit == '*')
	{
		Result.RealNum = Z1.RealNum * Z2.RealNum - Z1.ImaginaryNum * Z2.ImaginaryNum;
		Result.ImaginaryNum = Z1.RealNum * Z2.ImaginaryNum + Z1.ImaginaryNum * Z2.RealNum;
	}
	else if (Arit == '/')
	{
		Result.RealNum = (Z1.RealNum * Z2.RealNum + Z1.ImaginaryNum * Z2.ImaginaryNum) / (Z2.RealNum * Z2.RealNum + Z2.ImaginaryNum * Z2.ImaginaryNum);
		Result.ImaginaryNum = (Z1.ImaginaryNum * Z2.RealNum + Z1.RealNum * Z2.ImaginaryNum) / (Z2.RealNum * Z2.RealNum + Z2.ImaginaryNum * Z2.ImaginaryNum);
	}
	return Result;
}


int main() // Задание 1. 
{
	setlocale(LC_ALL, "ru");

	Complex_Number Z1{}, Z2{}, Result{};
	char Arit{}; // *, /, +, -
	std::cout << "Введите первое вещественное число: ";
	std::cin >> Z1.RealNum;
	std::cout << "Введите первое мнимое число: ";
	std::cin >> Z1.ImaginaryNum;
	std::cout << "Введите второе вещественное число: ";
	std::cin >> Z2.RealNum;
	std::cout << "Введите второе мнимое число: ";
	std::cin >> Z2.ImaginaryNum;
	std::cout << "Укажите арифметическое дейтсвие с комплексными числами: ";
	std::cin >> Arit;
	Result = Arithmetic(Z1, Z2, Arit);
	std::cout << "Результат арифметических действий: Вещественное число = " << Result.RealNum << std::endl;
	std::cout << "Мнимое число = " << Result.ImaginaryNum << std::endl;

	return 0;
}