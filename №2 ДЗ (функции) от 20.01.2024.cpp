/*
Домашнее задание СДБ 311. Домашнее задание 5 от 20.01.2021
				Функции.

				Задание 2

Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму чисел из диапазона между ними.

*/

#include <iostream>

int sum_between(int x1, int x2) 
{
	int Sum{};
	int Max{};
	int Min{};
	Max = (x1 > x2) ? x1 : x2;
	Min = (x1 < x2) ? x1 : x2;
	if (Max == Min + 1)
		return 0;
	for (int i = Min + 1; i < Max; i++)
		Sum += i;
	return Sum;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	std::cout << "Введите первое челое число = ";
	int A{};
	std::cin >> A;
	std::cout << "Введите второе челое число = ";
	int N{};
	std::cin >> N;
	std::cout << "Сумма чисел из диапазона введенных чисел между ними = " << sum_between(A, N) << std::endl;

	return 0;
}