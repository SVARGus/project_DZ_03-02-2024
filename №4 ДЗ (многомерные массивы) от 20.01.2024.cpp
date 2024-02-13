/*
Домашнее задание СДБ 311. Домашнее задание 5 от 20.01.2021
			Многомерные массивы

				Задание 4

В двумерном массиве целых числе посчитать:
1) Сумму всех элементов массива 
2) Среднее арифметическое всех элементов массива 
3) Минимальный элемент 
4) Максимальный элемент

*/

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	const int COLUMN{ 5 };
	const int LINE{ 4 };
	int Mass[LINE][COLUMN]{};
	std::cout << "Для начала выведем весь массив" << std::endl;
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			Mass[i][j] = rand() % 100;
			std::cout << Mass[i][j] << " ";
		}
		std::cout << std::endl;
	}
	int Sum{}; // Сумма всех элементов
	double Average{}; // Средне арифметическое всех элементов массива
	int Min{}; // Минимальный элемент
	int Max{}; // Максимальный элемент
	Min = Mass[0][0];
	Max = Mass[0][0];
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (Min > Mass[i][j])
				Min = Mass[i][j];
			if (Max < Mass[i][j])
				Max = Mass[i][j];
			Sum += Mass[i][j];
		}
	}
	Average = (double) Sum / (COLUMN * LINE);
	std::cout << "1) Сумму всех элементов массива = " << Sum << std::endl;
	std::cout << "2) Среднее арифметическое всех элементов массива = " << Average << std::endl;
	std::cout << "3) Минимальный элемент = " << Min << std::endl;
	std::cout << "4) Максимальный элемент = " << Max << std::endl;

	return 0;
}