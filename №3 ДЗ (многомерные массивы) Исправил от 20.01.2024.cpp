/*
Домашнее задание СДБ 311. Домашнее задание 5 от 20.01.2021
			Многомерные массивы

				Задание 3

Создайте двухмерный массив. Заполните его случайными числами и покажите на экран.
Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз).
Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический.

*/

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	const int COLUMN{ 5 };
	const int LINE{ 4 };
	int Mass[LINE][COLUMN]{};
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			Mass[i][j] = rand() % 101;
			std::cout << Mass[i][j] << " ";
		}
		std::cout << std::endl;
	}
	int Size_Shift{};
	std::cout << "Выберети количество сдигов ";
	std::cin >> Size_Shift;
	int Shift{};
	std::cout << "Вариант сдвига: \n1 - В право\n2 - В лево\n3 - В низ\n4 - В верх" << std::endl;
	std::cout << "Ваш вариант - ";
	std::cin >> Shift;
	do
	{
		switch (Shift)
		{
		case 1: //Завершил и проверил
			for (int i = Size_Shift; i > 0; i--)
			{
				for (int j = 0, y = 0; j < LINE; j++)
				{
					y = Mass[j][COLUMN - 1];
					for (int k = COLUMN - 1; k >= 0; k--)
					{
						if (k > 0)
							Mass[j][k] = Mass[j][k - 1];
						else
							Mass[j][0] = y;
					}
				}
			}
			break;
		case 2: //Завершил и проверил
			for (int i = Size_Shift; i > 0; i--)
			{
				for (int j = 0, y = 0; j < LINE; j++)
				{
					y = Mass[j][0];
					for (int k = 0; k < COLUMN; k++)
					{
						if (k < COLUMN - 1)
							Mass[j][k] = Mass[j][k + 1];
						else
							Mass[j][COLUMN - 1] = y;
					}
				}
			}
			break;
		case 3: //Завершил и проверил
			for (int i = Size_Shift; i > 0; i--)
			{
				for (int j = 0, y = 0; j < COLUMN; j++)
				{
					y = Mass[LINE - 1][j];
					for (int k = LINE - 1; k >= 0; k--)
					{
						if (k > 0)
							Mass[k][j] = Mass[k - 1][j];
						else
							Mass[0][j] = y;
					}
				}
			}
			break;
		case 4: //Завершил и проверил
			for (int i = Size_Shift; i > 0; i--)
			{
				for (int j = 0, y = 0; j < COLUMN; j++)
				{
					y = Mass[0][j];
					for (int k = 0; k < LINE; k++)
					{
						if (k < LINE - 1)
							Mass[k][j] = Mass[k + 1][j];
						else
							Mass[LINE - 1][j] = y;
					}
				}
			}
			break;
		default:
			std::cout << "Не корректный ввод варианта. Повторите ввод - ";
			std::cin >> Shift;
			break;
		}
	} while (Shift < 0 || Shift > 5);
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COLUMN; j++)
			std::cout << Mass[i][j] << " ";
		std::cout << std::endl;
	}

	return 0;
}