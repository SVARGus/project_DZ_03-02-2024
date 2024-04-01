/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Многомерные динамические массивы
*/

#include <iostream>

void Creat_Multi_Array(int**& Array, int SizeLine, int SizeColumn); // 1
void Gen_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1
void Print_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1
void Add_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX); // 1


void Creat_Multi_Array(int**& Array, int SizeLine, int SizeColumn) //Функция создания двумерного динамического массива (Задание 1)
{
	Array = new int* [SizeLine];
	for (int i = 0; i < SizeLine; i++)
	{
		Array[i] new int[SizeColumn];
	}
}

void Gen_Multi_Array(int** Array, int SizeLine, int SizeColumn) // Функция генерации случайных чисел в массиве (Задание 1)
{
	for (int i = 0; i < SizeLine; i++)
	{
		for (int j = 0; j < SizeColumn; j++)
		{
			Array[i][j] = rand() % 100;
		}
	}
}

void Print_Multi_Array(int** Array, int SizeLine, int SizeColumn) // Функция печати двумерного массива (Задание 1)
{
	for (int i = 0; i < SizeLine; i++)
	{
		for (int j = 0; j < SizeColumn; j++)
		{
			std::cout << Array[i][j] << " ";
		}
		std::cout << std::end;
	}
	std::cout << std::end;
}

void Add_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX) // Функция добавления столбца в указанную позицию двумерного массива (данный столбец зануляется) (Задание 1)
{
	SizeColumn += 1;
	for (int i = 0; i < SizeLine; i++)
	{
		int* NewArrayLine = new int[NewSizeColumn]; //Создание временного одномерного массива в динамической памяти
		for (int j = 0, k = 0; k < SizeColumn; j++, k++)
		{
			if (k == ColumnX)
			{
				NewArrayLine[k]{}; // Зануляем добавленный столбец
				k++;
			}
			NewArrayLine[k] = Array[i][j];
		}
		delete[]Array[i]; // Удаляем данные по указателю воизбежания утечки данных
		Array[i] = NewArrayLine; // Запись адресса строки с добавленным столбцом
	}
}


int main() // Задание 1
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int SizeLine{}; // Размер массива, количество строк
	int SizeColumn{}; // Размер массива, количество столбцов
	int** ptrArray{ nullptr };
	std::cout << "Выберети размер массива. Количество строк = ";
	std::cin >> SizeLine;
	std::cout << "Количество столбцов = ";
	std::cin >> SizeColumn;
	Creat_Multi_Array(ptrArray, SizeLine, SizeColumn); // Создание двумерного массива
	Gen_Multi_Array(ptrArray, SizeLine, SizeColumn);
	std::cout << "Заполним двумерный массив случайными числами и выведем на экран:" << std::endl;
	Print_Multi_Array(ptrArray, SizeLine, SizeColumn);
	int ColumnX{}; // Номер позиции столбца
	std::cout << "Выберети в какую позицию надо добавить столбец (начиная с 0): ";
	std::cin >> ColumnX;
	Add_Column_Multi_Array(Array, SizeLine, &SizeColumn, ColumnX);
	std::cout << "Теперь выведем массив с добавленным столбцем" << std::endl;
	Print_Multi_Array(ptrArray, SizeLine, SizeColumn);

	return 0;
}

int main_2()
{
	setlocale(LC_ALL, "ru");



	return 0;
}