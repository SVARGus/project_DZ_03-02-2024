/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Многомерные динамические массивы
*/

#include <iostream>

void Creat_Multi_Array(int**& Array, int SizeLine, int SizeColumn); // 1, 2, 3
void Gen_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1, 2, 3
void Print_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1, 2, 3
void Add_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX); // 1
void Del_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX); // 2
void Shift_Array(int** Array, int SizeLine, int SizeColumn, int SizeShift, int Shift); // 3
void Matrix_TransposeX2(int** Array, int SizeLine, int SizeColumn); // 4
void swap(int* ptr1, int* ptr2); // 4
void Matrix_Transpose(int** &Array, int* SizeLine, int* SizeColumn); // 4
void DelArray(int**& Array, int SizeLine);


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

void Shift_Array(int** Array, int SizeLine, int SizeColumn, int SizeShift, int Shift) // Функция сдвига двумерного динамического массива (Задание 3)
{
	enum Direction { RIGHT = 1, LEFT, DOWN, UP };
	int* NewArrayLine{ nullptr };
	int NewColumX{};
	do
	{
		switch (Shift)
		{
		case RIGHT:
			for (int i = 0; i < SizeLine; i++)
			{
				NewColumX = Array[i][SizeColumn - 1];
				for (int j = SizeColumn - 1; j >= 0; j--)
				{
					if (j > 0)
						Array[i][j] = Array[i][j - 1];
					else
						Array[i][j] = NewColumX;
				}
			}
			break;
		case LEFT:
			for (int i = 0; i < SizeLine; i++)
			{
				NewColumX = Array[i][0];
				for (int j = 0; j < SizeColumn; j++)
				{
					if (j < SizeColumn - 1)
						Array[i][j] = Array[i][j + 1];
					else
						Array[i][j] = NewColumX;
				}
			}
			break;
		case DOWN:
			NewArrayLine = Array[SizeLine - 1];
			for (int i = SizeLine - 1; i >= 0; i--)
			{
				if (i > 0)
					Array[i] = Array[i - 1];
				else
					Array[i] = NewArrayLine;
			}
			break;
		case UP:
			NewArrayLine = Array[0];
			for (int i = 0; i < SizeLine; i++)
			{
				if (i < SizeLine - 1)
					Array[i] = Array[i + 1];
				else
					Array[i] = NewArrayLine;
			}
			break;
		default:
			std::cout << "Не корректный ввод варианта. Повторите ввод - ";
			std::cin >> Shift;
			break;
		}
	} while (Shift < 0 || Shift > 5);
	
	if (SizeShift > 1)
	{
		--SizeShift;
		Shift_Array(Array, SizeLine, SizeColumn, SizeShift, Shift);
	}
}

void Matrix_TransposeX2(int** Array, int SizeLine, int SizeColumn) // Транспонирование квадратной матрицы (Задание 4) (Проверил - работает!!!)
{
	int Temp{};
	for (int i = 0; i < SizeLine; i++)
	{
		for (int j = 1; j < SizeLine; j++)
		{
			if (j > i)
				swap(&Array[i][j], &Array[j][i]);
		}
	}
}

void swap(int* ptr1, int* ptr2) // Функция замены значений двух указателей (Задание 4) для транспонирования квадратной матрицы
{
	int x{};
	x = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = x;
}

void Matrix_Transpose(int** &Array, int* SizeLine, int* SizeColumn) // Транспонирование двумерной матрицы любого размера: квадратная и прямоугольная (Задание 4). В процессе!!!
{
	/*
	Описание транспонирование матрицы по шагам (решил сначала написать алгоритм действий и потом реализовать, позде описание оставить!!!):
	1) сначала транспонируем квадратную часть матрицы по наименьшему размеру матрицы
	2) Делаем условие если Столбцов больше чем строк, то выполняем действие 2.1, иначе 2.2, а также условие где количество срок равно количествуо столбцов и делаем выход из функции!!!
	2.1) Создаем временную новую матрицу где количество строк равно количеству столбцев и временные размеры матрицы.
	- Записываем адреса строк от 0 до нового количества столбцов.
	- Создаем добавленные строки по размеру нового количества столбцов.
	- начинаем заполнять транспонируя столбец из старой матрицы в послеюднюю строку и продолжаем пока не дойдем по условиям до  #строки > #столбца (в нашем случае Line>=Column, так как 1 страка у нас под 0)
		-- Далее создаем временный указатель на одномерный массив по размеру новой строки. Записываем в него данные из уже транспонированного квадрата в следующую строку
		-- Продолжаем поочередно переписывать пока не дойдемдо конца (0 строка)
	- Удяляем старую матрицу по схеме (удаление данных столбцов, а потом удаление строк с указателями) предотварщения утечки данных.
	- Присваиваем адрес старому указателю на новую мтрицу. (Временный указатель после выхода из функции удалится)
	- Меняем данные матрицы по ранее перданному указателю на новые размеры матрицы.
	2.2) 
	*/
	if (*SizeLine == *SizeColumn)
	{
		Matrix_TransposeX2(Array, *SizeLine, *SizeColumn); // Проверил, работает.
	}
	else if (*SizeLine < *SizeColumn)
	{
		int NewSizeLine = *SizeColumn;
		int NeWSizeColumn = *SizeLine;
		int** NewArray{ nullptr };
		Creat_Multi_Array(NewArray, NewSizeLine, NeWSizeColumn);
		Matrix_TransposeX2(Array, *SizeLine, *SizeColumn);
		for (int i = 0; i < *SizeLine; i++)
		{
			for (int j = 0; j < *SizeLine; j++)
				NewArray[i][j] = Array[i][j]; // Записываем в новую матрицу уже транспонированную квадратную часть изначальной матрицы
		}
		for (int i = *SizeLine; i < NewSizeLine; i++)
		{
			for (int j = 0; j < NeWSizeColumn; j++)
				NewArray[i][j] = Array[j][i];
		}
		DelArray(Array, *SizeLine);
		Array = NewArray;
		*SizeColumn = NeWSizeColumn;
		*SizeLine = NewSizeLine;
	}
	else
	{

	}
}

void DelArray(int**& Array, int SizeLine) // Функция удаления массива
{
	for (int i = 0; i < SizeLine; i++)
		delete[]Array[i];
	delete[]Array;
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

int main_3() // Задание 3. Циклический сдвиг
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
	std::cout << "Вариант сдвига: \n1 - В право\n2 - В лево\n3 - В низ\n4 - В верх" << std::endl;
	std::cout << "Ваш вариант - ";
	int Shift{};
	std::cin >> Shift;
	Shift_Array(ptrArray, SizeLine, SizeColumn, SizeShift, Shift);
	std::cout << "После сдвига выведем получившийся результат:" << std::endl;
	Print_Multi_Array(ptrArray, SizeLine, SizeColumn);

	return 0;
}

int main() // Задание 4. Транспонирование матрицы
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
	std::cout << "Теперь транспонируем матрицу двумерного массива и выведем на экран:" << std::endl;
	Matrix_Transpose(ptrArray, &SizeLine, &SizeColumn);
	//Matrix_TransposeX2(ptrArray, SizeLine, SizeColumn); //Временный вариант транспонирования квадратной матрицы
	Print_Multi_Array(ptrArray, SizeLine, SizeColumn);

	return 0;
}