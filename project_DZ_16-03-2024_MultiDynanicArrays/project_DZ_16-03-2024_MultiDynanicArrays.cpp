/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Многомерные динамические массивы
*/

#include <iostream>

void Creat_Multi_Array(int**& Array, int SizeLine, int SizeColumn); // 1, 2
void Gen_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1, 2
void Print_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1, 2
void Add_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX); // 1
void Del_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX); // 2


void Creat_Multi_Array(int**& Array, int SizeLine, int SizeColumn) //Функция создания двумерного динамического массива (Задание 1, 2)
{
	Array = new int* [SizeLine];
	for (int i = 0; i < SizeLine; i++)
	{
		Array[i] = new int[SizeColumn];
	}
}

void Gen_Multi_Array(int** Array, int SizeLine, int SizeColumn) // Функция генерации случайных чисел в массиве (Задание 1, 2)
{
	for (int i = 0; i < SizeLine; i++)
	{
		for (int j = 0; j < SizeColumn; j++)
		{
			Array[i][j] = rand() % 100;
		}
	}
}

void Print_Multi_Array(int** Array, int SizeLine, int SizeColumn) // Функция печати двумерного массива (Задание 1, 2)
{
	for (int i = 0; i < SizeLine; i++)
	{
		for (int j = 0; j < SizeColumn; j++)
		{
			std::cout << Array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Add_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX) // Функция добавления столбца в указанную позицию двумерного массива (данный столбец зануляется) (Задание 1)
{
	*SizeColumn += 1; // пока в этом месте не поставил * - программа вылетала с ошибкой. Наверное стоило изначально в теле программы создать указатель и присвоить его переменной
	for (int i = 0; i < SizeLine; i++)
	{
		int* NewArrayLine = new int[*SizeColumn]; //Создание временного одномерного массива в динамической памяти
		for (int j = 0, k = 0; k < *SizeColumn; j++, k++)
		{
			if (k == ColumnX)
			{
				NewArrayLine[k] = 0; // Зануляем добавленный столбец
				k++;
			}
			NewArrayLine[k] = Array[i][j];
		}
		delete[]Array[i]; // Удаляем данные по указателю воизбежания утечки данных
		Array[i] = NewArrayLine; // Запись адресса строки с добавленным столбцом
	}
}

void Del_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX) // Функция добавления столбца в указанную позицию двумерного массива (данный столбец зануляется) (Задание 2)
{
	*SizeColumn -= 1;
	for (int i = 0; i < SizeLine; i++)
	{
		int* NewArrayLine = new int[*SizeColumn]; //Создание временного одномерного массива в динамической памяти
		for (int j = 0, k = 0; k < *SizeColumn; j++, k++)
		{
			if (k == ColumnX)
				j++;
			NewArrayLine[k] = Array[i][j];
		}
		delete[]Array[i]; // Удаляем данные по указателю воизбежания утечки данных
		Array[i] = NewArrayLine; // Запись адресса строки с добавленным столбцом
	}
}
// функции удаления и добавления столбца по своей суте идентичны и при желании их можно обьеденить и добавить вводимую переменную которая будет определяться в теле программы через switch (-1 и 1)

void Shift_Array(int** Array, int SizeLine, int SizeColumn, int SizeShift, int Shift)
{
	int* NewArrayLine{ nullptr };
	NewArrayLine = Array[0];
	for (int i = 0; i < SizeLine; i++)
	{
		if (i < SizeLine - 1)
		{
			Array[i] = Array[i + 1];
		}
		else
		{
			Array[i] = NewArrayLine;
		}
		
	}

}

int main_1() // Задание 1. (готово)
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
	Add_Column_Multi_Array(ptrArray, SizeLine, &SizeColumn, ColumnX);
	std::cout << "Теперь выведем массив с добавленным столбцем" << std::endl;
	Print_Multi_Array(ptrArray, SizeLine, SizeColumn);

	return 0;
}

int main_2() // Задание 2. (готово)
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
	std::cout << "Выберети какой столбец надо удалить (начиная с 0): ";
	std::cin >> ColumnX;
	Del_Column_Multi_Array(ptrArray, SizeLine, &SizeColumn, ColumnX);
	std::cout << "Теперь выведем массив" << std::endl;
	Print_Multi_Array(ptrArray, SizeLine, SizeColumn);

	return 0;
}

int main() // Задание 3. Циклический сдвиг
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
	int SizeShift{};
	std::cout << "Выберети количество сдигов ";
	std::cin >> SizeShift;
	enum Direction{RIGHT=1, LEFT, DOWN, UP};
	std::cout << "Вариант сдвига: \n1 - В право\n2 - В лево\n3 - В низ\n4 - В верх" << std::endl;
	std::cout << "Ваш вариант - ";
	int Shift{};
	std::cin >> Shift;
	do
	{
		switch (Shift)
		{
		case RIGHT:
			break;
		case LEFT:
			break;
		case DOWN:
			break;
		case UP:
			break;
		default:
			std::cout << "Не корректный ввод варианта. Повторите ввод - ";
			std::cin >> Shift;
			break;
		}
	} while (Shift < 0 || Shift > 5);

	return 0;
}