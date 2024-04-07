/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Многомерные динамические массивы
*/
/*
Задание 1:
Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.

Задание 2:
Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.

Задание 3:
Дана матрица порядка MxN (M строк, N столбцов). 
Необходимо заполнить ее значениями и написать функцию, осуществляющую циклический сдвиг строк и/или столбцов массива указанное количество раз и в указанную сторону.

Задание 4:
Транспонирование матрицы – это операция, после которой столбцы прежней матрицы становятся строками, 
а строки столбцами. Напишите функцию транспонирования матрицы.

Задание 5:
Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон.
Организуйте поиск по имени и по номеру телефона и возмо жность ввода и изменения данных.
*/


#include <iostream>
#include <cstring>
//#include <string.h>
#include <windows.h> 

void Creat_Multi_Array(int**& Array, int SizeLine, int SizeColumn); // 1, 2, 3
void Gen_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1, 2, 3
void Print_Multi_Array(int** Array, int SizeLine, int SizeColumn); // 1, 2, 3
void Add_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX); // 1
void Del_Column_Multi_Array(int**& Array, int SizeLine, int* SizeColumn, int ColumnX); // 2
void Shift_Array(int** Array, int SizeLine, int SizeColumn, int SizeShift, int Shift); // 3
void Matrix_TransposeX2(int** Array, int SizeLine, int SizeColumn); // 4
void swap(int* ptr1, int* ptr2); // 4
void Matrix_Transpose(int** &Array, int* SizeLine, int* SizeColumn); // 4
void DelArray(int**& Array, int SizeLine); // 1-4
template<typename T>
void Del3D_Array(T***& Array, int SizeLine, int SizeColumn); // 5
template<typename T>
void Creat3D_Multi_Array(T***& Array, int SizeLine, int SizeColumn); // 5
bool foo(char* Name, int i); // 5
void Insert_3D_Multi_Array(char*** Array, int SizeLine, int SizeColumn, char* Name, char* Phone); // 5
void Print3D_Multi_Array(char*** Array, int SizeLine, int SizeColumn); // 5
bool Flag_Name(char*** Array, int Line, int SizeColumn, char* Name); // 5
int Search_i_Name(char*** Array, int Line, int SizeColumn, char* Name); // 5
void Search_Name(char*** Array, int Line, int SizeColumn, char* Name); // 5
void Search_Section_Name(char*** Array, int Line, int SizeLine, int SizeColumn, char* Name); // 5
void Menu_1(char*** Array, int SizeLine, int SizeColumn); // 5
void Modifi_Name(char*** Array, int Line, int SizeLine, int SizeColumn); // 5
void Menu_2(char*** Array, int SizeLine, int SizeColumn); // 5
void Rise_3D_Multi_Array(char*** Array, int* SizeColumn, char* Name, char* Phone); // 5
void Menu_3(char*** Array, int SizeLine, int* SizeColumn); // 5


void Creat_Multi_Array(int**& Array, int SizeLine, int SizeColumn) //Функция создания двумерного динамического массива (Задание 1, 2)
{
	Array = new int* [SizeLine];
	for (int i = 0; i < SizeLine; i++)
	{
		Array[i] = new int[SizeColumn];
	}
}

template<typename T>
void Creat3D_Multi_Array(T***& Array, int SizeLine, int SizeColumn) //Функция создания трехмерного динамического массива (Задание 5), без создания
{
	Array = new T** [SizeLine];
	for (int i = 0; i < SizeLine; i++)
	{
		Array[i] = new T*[SizeColumn];
		for (int j = 0; j < SizeColumn; j++)
		{
			Array[i][j] = nullptr;
		}
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
	int Min = (SizeLine < SizeColumn) ? SizeLine : SizeColumn;
	for (int i = 0; i < Min; i++)
	{
		for (int j = 1; j < Min; j++)
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

void Matrix_Transpose(int** &Array, int* SizeLine, int* SizeColumn) // Транспонирование двумерной матрицы любого размера: квадратная и прямоугольная (Задание 4).
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
	2.2) Нужно сделать зеркально. Также подумать как сделать через рекурсию.
	*/
	if (*SizeLine == *SizeColumn)
	{
		Matrix_TransposeX2(Array, *SizeLine, *SizeColumn); // Проверил, работает.
	}
	else
	{
		int NewSizeLine = *SizeColumn;
		int NeWSizeColumn = *SizeLine;
		int Min = (*SizeLine < *SizeColumn) ? *SizeLine : *SizeColumn;
		int** NewArray{ nullptr };
		Creat_Multi_Array(NewArray, NewSizeLine, NeWSizeColumn);
		Matrix_TransposeX2(Array, *SizeLine, *SizeColumn);
		for (int i = 0; i < Min; i++)
		{
			for (int j = 0; j < Min; j++)
				NewArray[i][j] = Array[i][j]; // Записываем в новую матрицу уже транспонированную квадратную часть изначальной матрицы
		}
		if (*SizeLine < *SizeColumn)
		{
			for (int i = *SizeLine; i < NewSizeLine; i++)
			{
				for (int j = 0; j < NeWSizeColumn; j++)
					NewArray[i][j] = Array[j][i];
			}
		}
		else
		{
			for (int i = 0; i < NewSizeLine; i++)
			{
				for (int j = *SizeColumn; j < NeWSizeColumn; j++)
					NewArray[i][j] = Array[j][i];
			}
		}
		DelArray(Array, *SizeLine);
		Array = NewArray;
		*SizeColumn = NeWSizeColumn;
		*SizeLine = NewSizeLine;
	}
}

void DelArray(int**& Array, int SizeLine) // Функция удаления двумерного динамического массива (задание 1-4)
{
	for (int i = 0; i < SizeLine; i++)
		delete[]Array[i];
	delete[]Array;
}

template<typename T>
void Del3D_Array(T***& Array, int SizeLine, int SizeColumn) // Функция удаления трехмерного динамического массива (Задание 5)
{
	for (int i = 0; i < SizeLine; i++)
	{
		for (int j = 0; j < SizeColumn; j++)
		{
			delete[]Array[i][j];
		}
		delete[]Array[i];
	}
	delete[]Array;
}

bool foo(char* Name, int i) // функция поднятия флага для задания 5
{
	if ('A' <= Name[i] && Name[i] <= 'Z')
		return true;
	else if ('a' <= Name[i] && Name[i] <= 'z')
		return true;
	else if ('0' <= Name[i] && Name[i] <= '9')
		return true;
	else
		return false;
}

void Insert_3D_Multi_Array(char*** Array, int SizeLine, int SizeColumn, char* Name, char* Phone) // Функция заполнения строк из задания 5 (чтобы каждый раз вручную не вводить данные в массив)
{
	//bool Flag{};
	char NewName[15]{};
	int NewSize{};
	int SizeName = strlen(Name);
	int SizePhone = strlen(Phone);
	char* NewArray{ nullptr };
	for (int i = 0, j = 0, k = 0; i < SizeName; i++)
	{
		if (foo(Name, i) == true)
		{
			NewName[j] = Name[i];
			++j;
		}
		if (foo(Name, i) == true && foo(Name, i + 1) == false)
		{
			NewName[j + 1] = '\0';
			NewSize = strlen(NewName) + 1;
			Array[0][k] = new char[NewSize] {};
			for (int x = 0; x < j; x++)
			{
				Array[0][k][x] = NewName[x];
			}
			++k;
			j = 0;
		}
	}
	for (int i = 0, j = 0, k = 0; i < SizePhone; i++)
	{
		if (foo(Phone, i) == 1)
		{
			NewName[j] = Phone[i];
			++j;
		}
		if (foo(Phone, i) == 1 && foo(Phone, i + 1) != 1)
		{
			NewName[j + 1] = '\0';
			NewSize = strlen(NewName) + 1;
			Array[1][k] = new char[NewSize] {};
			for (int x = 0; x < j; x++)
			{
				Array[1][k][x] = NewName[x];
			}
			++k;
			j = 0;
		}
	}
}

void Print3D_Multi_Array(char*** Array, int SizeLine, int SizeColumn) // Функция вывода для задания 5, но для удобства строки выводятся как столбцы.
{
	for (int j = 0; j < SizeColumn; j++)
	{
		for (int i = 0; i < SizeLine; i++)
		{
			std::cout << Array[i][j];
			//std::cout << " " << strlen(Array[i][j]); //временно - удалить потом
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
}

bool Flag_Name(char*** Array, int Line, int SizeColumn, char* Name)
{
	for (int i = 0; i < SizeColumn; i++)
	{
		if (strcmp(Array[Line][i], Name) == 0)
			return  true;
	}
	return false; // обязательно прописывать return false если условие в цикле не выполнилось?
}

int Search_i_Name(char*** Array, int Line, int SizeColumn, char* Name) // (Задание 5) Поиск в массиве по полному имени (Line = 0) и телефону (Line = 1) и вывод позиции в массиве
{
	for (int i = 0; i < SizeColumn; i++)
	{
		if (strcmp(Array[Line][i], Name) == 0)
			return i;
	}
	return 0; // Учесть и добавить булевскую проверку не позволяющая запустить данную функцию
}

void Search_Name(char*** Array, int Line, int SizeColumn, char* Name) // (Задание 5) Поиск в массиве по полностью введенному имени (Line = 0) и телефону (Line = 1)
{
	if (Flag_Name(Array, Line, SizeColumn, Name) == false)
	{
		std::cout << "Искомые данные не найдены!!! Повторите поиск" << std::endl;
	}
	else
	{
		int i = Search_i_Name(Array, Line, SizeColumn, Name);
		std::cout << "Данные найдены: #" << i << " Имя: " << Array[0][i] << " Телефон: " << Array[1][i] << std::endl;
	}
}

void Search_Section_Name(char*** Array, int Line, int SizeLine, int SizeColumn, char* Name) // (Задание 5) Поиск в массиве по частично введенному имени или отдельному символу (Line = 0) и телефону (Line = 1)
{
	int Size = strlen(Name);
	std::cout << "Найдены совпадения по ";
	if (Line == 0)
		std::cout << "Имени следующие Телефоны: " << std::endl;
	else
		std::cout << "номеру телефона следующие Имена: " << std::endl;
	for (int i = 0; i < SizeColumn; i++)
	{
		int SizeArray = strlen(Array[Line][i]);
		for (int j = 0, k = 0; j < SizeArray && Size <= SizeArray; j++)
		{
			if (Array[Line][i][j] != Name[k])
				k = 0;
			else
				++k;
			if (k == Size)
			{
				std::cout << "Данные найдены: #" << i << " Имя: " << Array[0][i] << " Телефон: " << Array[1][i] << std::endl;
				break;
			}
		}
	}
}

void Menu_1(char*** Array, int SizeLine, int SizeColumn) // Меню 1 - обычный поиск данных в массиве данных имен и телефонов и вывод на экран
{
	char Name[20]{};
	int Menu1{};
	std::cout << "1) Искать по полному Имени" << std::endl;
	std::cout << "2) Искать по нескольким буквам из Имени" << std::endl;
	std::cout << "3) Искать по целому номеру телефона (11 цифр)" << std::endl;
	std::cout << "4) Искать по сочетанию нескоьких цифр Телефона" << std::endl;
	std::cout << "0) Выход" << std::endl;
	std::cin >> Menu1;
	do
	{
		switch (Menu1)
		{
		case 1:
			std::cin >> Name;
			Search_Name(Array, 0, SizeColumn, Name);
			break;
		case 2:
			std::cin >> Name;
			Search_Section_Name(Array, 0, SizeLine, SizeColumn, Name);
			break;
		case 3:
			std::cin >> Name;
			Search_Name(Array, 1, SizeColumn, Name);
			break;
		case 4:
			std::cin >> Name;
			Search_Section_Name(Array, 1, SizeLine, SizeColumn, Name);
			break;
		default:
			std::cin >> Menu1;
			break;
		}
	} while (Menu1 != 0);
}

void Modifi_Name(char*** Array, int Line, int SizeLine, int SizeColumn)
{
	int Index{};
	char Name[20]{};
	if (Line == 0)
	{
		std::cout << "Укажите индекс имени который вы хотите изменить: ";
		std::cin >> Index;
		std::cout << "Пропишите новое имя для замены: ";
		std::cin >> Name;
	}
	else
	{
		std::cout << "Укажите индекс телефона который вы хотите изменить: ";
		std::cin >> Index;
		std::cout << "Пропишите новый телефон для замены: ";
		std::cin >> Name;
	}
	delete[]Array[Line][Index];
	Array[Line][Index] = new char[strlen(Name)+1];
	#pragma warning(disable:4996); 
	strcpy(Array[Line][Index], Name); // выдавало ишибку, пришлось подключить перед вызовом #pragma warning(disable:4996); strcpy_s не работает почемуто
	std::cout << "Вывод измененных данных: # " << Index << " Имя: " << Array[0][Index] << " Телефон: " << Array[1][Index] << std::endl;
}

void Menu_2(char*** Array, int SizeLine, int SizeColumn)
{
	char Name[20]{};
	int Index{};
	int Menu2{};
	std::cout << "1) Внести изменение в Имя" << std::endl;
	std::cout << "2) Внести изменение в Телефон" << std::endl;
	std::cout << "0) Выход" << std::endl;
	do
	{
		std::cin >> Menu2;
		switch (Menu2)
		{
		case 1:
			Modifi_Name(Array, 0, SizeLine, SizeColumn);
			break;
		case 2:
			Modifi_Name(Array, 1, SizeLine, SizeColumn);
			break;
		}
	} while (Menu2 != 0);
}

void Rise_3D_Multi_Array(char*** Array, int *SizeColumn, char* Name, char* Phone)
{
#pragma warning(disable:4996);
	int NewSizeColume = *SizeColumn + 1;
	int Size{};
	char** NewArray = new char* [NewSizeColume];
	for (int i = 0; i < NewSizeColume; i++)
	{
		if (i < *SizeColumn)
		{
			Size = strlen(Array[0][i]) + 1;
			NewArray[i] = new char[Size]; 
			strcpy(NewArray[i], Array[0][i]);
		}
		else
		{
			Size = strlen(Name) + 1;
			NewArray[i] = new char[Size];
			strcpy(NewArray[i], Name);
		}
	}
	for (int i = 0; i < *SizeColumn; i++)
	{
		delete[]Array[0][i];
	}
	delete[]Array[0];
	Array[0] = NewArray;

	NewArray = new char* [NewSizeColume];
	for (int i = 0; i < NewSizeColume; i++)
	{
		if (i < *SizeColumn)
		{
			Size = strlen(Array[1][i]) + 1;
			NewArray[i] = new char[Size];
			strcpy(NewArray[i], Array[1][i]);
		}
		else
		{
			Size = strlen(Phone) + 1;
			NewArray[i] = new char[Size];
			strcpy(NewArray[i], Phone);
		}
	}
	for (int i = 0; i < *SizeColumn; i++)
	{
		delete[]Array[1][i];
	}
	delete[]Array[1];
	Array[1] = NewArray;
	*SizeColumn = NewSizeColume;
}

void Menu_3(char*** Array, int SizeLine, int *SizeColumn)
{
	char Name[20]{};
	char Phone[20]{};
	std::cout << "Введите Имя: ";
	std::cin >> Name;
	std::cout << "Введите Телефон: ";
	std::cin >> Phone;
	Rise_3D_Multi_Array(Array, SizeColumn, Name, Phone);
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
	DelArray(ptrArray, SizeLine);

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
	DelArray(ptrArray, SizeLine);

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
	DelArray(ptrArray, SizeLine);

	return 0;
}

int main_4() // Задание 4. Транспонирование матрицы
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
	DelArray(ptrArray, SizeLine);

	return 0;
}

int main_5() // Задание 5.
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int SizeLine{2}; // Размер массива, количество строк
	int SizeColumn{10}; // Размер массива, количество столбцов
	char*** ptrArray{ nullptr };
	Creat3D_Multi_Array(ptrArray, SizeLine, SizeColumn);
	//char* ArrayName[] = new char* { "Jon", "Alex", "Den", "Piter", "Jordan", "Olivia", "Clara", "Sara", "Klarisa", "Anton" };
	char Name[] = "Jon Alex Den Piter Jordan Olivia Clara Sara Klarisa Anton"; // Массив имен чтобы каждый раз не вводить.
	char Phone[] = "79784524513 77051363415 79024263570 79011108191 79532877598 79341152699 79588331866 79339942050 79045453738 79084437628"; // Массив телефонов чтобы каждый раз не вводить.
	Insert_3D_Multi_Array(ptrArray, SizeLine, SizeColumn, Name, Phone);
	std::cout << "" << std::endl;
	Print3D_Multi_Array(ptrArray, SizeLine, SizeColumn); // временный вывод
	int Menu{};
	do
	{
		std::cout << "Меню взаимодействия с базой имен ителефонов" << std::endl;
		std::cout << "1) Найти данные по имени или номеру телефона" << std::endl; // готово
		std::cout << "2) Внести изменения в данные" << std::endl; // готово
		std::cout << "3) Добавить новые данные в базу" << std::endl; // Осталось доделать добавление данных
		std::cout << "0) Выход" << std::endl;
		std::cin >> Menu;
		switch (Menu)
		{
		case 1:
			Menu_1(ptrArray, SizeLine, SizeColumn);
			break;
		case 2:
			Menu_2(ptrArray, SizeLine, SizeColumn);
			break;
		case 3:
			Menu_3(ptrArray, SizeLine, &SizeColumn);
			break;
		default:
			break;
		}
	} while (Menu != 0);

	Print3D_Multi_Array(ptrArray, SizeLine, SizeColumn); // временный вывод для просмотра изменений во всем массиве

	Del3D_Array(ptrArray, SizeLine, SizeColumn);

	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int Menu{};
	do
	{
		std::cout << "Меню выполнения домашнего задания. Выберети вариант от 1 до 5, а 0 это выход: ";
		std::cin >> Menu;
		switch (Menu)
		{
		case 1:
			std::cout << "Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию." << std::endl;
			main_1();
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "Написать функцию, удаляющую столбец двухмерного массива по указанному номеру." << std::endl;
			main_2();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "Дана матрица порядка MxN (M строк, N столбцов). \nНеобходимо заполнить ее значениями и написать функцию, осуществляющую циклический сдвиг \nстрок и/или столбцов массива указанное количество раз и в указанную сторону." << std::endl;
			main_3();
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "Транспонирование матрицы – это операция, после которой столбцы прежней матрицы становятся строками, \nа строки столбцами. Напишите функцию транспонирования матрицы." << std::endl;
			main_4();
			std::cout << std::endl;
			break;
		case 5:
			std::cout << "Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон.\nОрганизуйте поиск по имени и по номеру телефона и возмо жность ввода и изменения данных." << std::endl;
			main_5();
			std::cout << std::endl;
			break;
		}
	} while (Menu != 0);

	return 0;
}