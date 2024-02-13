/*
Домашнее задание СДБ 311. Домашнее задание 5 от 20.01.2021
				Функции.

				Задание 4

Число называется совершенным, если сумма всех его делителей равна ему самому. Напишите функцию поиска таких чисел во введенном интервале.

*/

#include <iostream>

void perfect_number(long long x1, long long x2)
{
	long long Min{};
	long long Max{};
	Min = (x1 < x2) ? x1 : x2;
	Max = (x1 > x2) ? x1 : x2;
	std::cout << "Совершенные числа в заданном интервале: ";
	int k = 0;
	for (long long i = Min; i <= Max; i++)
	{
		for (long long j = 1, long long Sum = 0; j < i; j++)
		{
			if (i % j == 0)
				Sum += j;
			if (Sum == i)
			{
				std::cout << i << " ";
				k++;
			}
		}
	}
	if (k == 0)
		std::cout << "Отсутствуют" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите первое челое интервала = ";
	long long A{};
	std::cin >> A;
	std::cout << "Введите второе челое интервала = ";
	long long N{};
	std::cin >> N;
	perfect_number(A, N);

	return 0;
}