﻿/*
Домашнее задание СДБ 311. Домашнее задание 5 от 20.01.2021
			Многомерные массивы

				Задание 6

Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5.
Первый массив заполняется случайными числа ми, в диапазоне от 0 до 50. Второй массив заполняется по следующему принципу: 
первый элемент второго массива равен сумме первого и второго элемента первого массива, второй элемент второго массива равен сумму третьего и четвертого элемента первого массива.

*/

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	const int X5{ 5 };
	const int X10{ 10 };
	int Mass_Big[X5][X10]{};
	int Mass_Smal[X5][X5]{};
	std::cout << "Объявим массив размером 5х10 и заполним случайными числами от 0 до 50:" << std::endl;
	for (int i = 0; i < X5; i++)
	{
		for (int j = 0; j < X10; j++)
		{
			Mass_Big[i][j] = rand() % 51;
			std::cout << Mass_Big[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Теперь высчитаем массив размером 5х5" << std::endl;
	std::cout << "Принцип заполнения : \nпервый элемент второго массива равен сумме первого и второго элемента первого массива, \nвторой элемент второго массива равен сумму третьего и четвертого элемента первого массива.\n";
	for (int i = 0; i < X5; i++)
	{
		for (int j = 0; j < X5; j++)
		{
			Mass_Smal[i][j] = Mass_Big[i][j * 2] + Mass_Big[i][j * 2 + 1];
			std::cout << Mass_Smal[i][j] << " ";
		}
		std::cout << std::endl;
	}
	

	return 0;
}