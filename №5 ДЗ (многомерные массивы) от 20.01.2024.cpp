/*
Домашнее задание СДБ 311. Домашнее задание 5 от 20.01.2021
			Многомерные массивы

				Задание 5

В двумерном массиве целых чисел посчитать сумму элементов: в каждой строке; в каждом столбце; одновременно по всем строкам и всем столбцам. Оформить следующим образом:
 3 5 6 7 | 21  
 12 1 1 1 | 15  
 0 7 12 1 | 20  
 ---------------------
 15 3 19 9 | 56

*/

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	const int COLUMN{ 4 };
	const int LINE{ 3 };
	int Mass[LINE][COLUMN]{};
	int Sum{};
	int Mass_Sum[COLUMN]{};
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			Mass[i][j] = rand() % 11;
			std::cout << Mass[i][j] << " ";
			Sum += Mass[i][j];
		}
		std::cout << " | " << Sum << std::endl;
		Sum = 0;
	}
	std::cout << "----------------" << std::endl;
	for (int i = 0; i < COLUMN; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			Mass_Sum[i] += Mass[j][i];
		}
		std::cout << Mass_Sum[i] << " ";
		Sum += Mass_Sum[i];
		if (LINE == i)
		{
			std::cout << " | " << Sum << std::endl;
		}
	}

	return 0;
}