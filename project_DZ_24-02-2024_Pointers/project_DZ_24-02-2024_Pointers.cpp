/*
Домашнее задание СДБ 311. Домашнее задание от 24.02.2024
				Рекурсия
*/
/*
Задание 1:
Используя два указателя на массив целых чисел, скопировать один массив в другой.
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.

Задание 2:
Используя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный.
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.

Задание 3:
Используя два указателя на массивы целых чисел, скопировать один массив в другой так, 
чтобы во втором массиве элементы находились в обратном порядке.
Использовать в программе а рифметику указателей для продвижения по массиву, а также оператор разыменования.

Задание 4:
Используя указатели и оператор разыменования, определить наибольшее из двух чисел.

Задание 5:
Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры.

Задание 6:
Используя указатели и оператор разыменования, обменять местами значения двух переменных.

Задание 7:
Написать примитивный калькулятор, пользуясь только указателями.

Задание 8:
Используя указатель на массив целых чисел, посчитать сумму элементов массива. 
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
*/

#include <iostream>

template<typename T>
void GenMuss(T muss[], int size, int x = 21); // 1, 2, 3
template<typename T>
void PrintMuss(T muss[], int size); // 1, 2, 3
template<typename T>
void ReplaceMussPTR(T ptr1, T ptr2, int size); // 1
void swap(int* ptr1, int* ptr2); // 2, 6
void ReplaceMirrorMussPTR(int* ptr, int size); // 2
void MirrorM1_in_M2(int* ptr1, int* ptr2, int size); // 3
void CheckSign(int* x); // 5
double CulcPtr(double* ptr1, double* ptr2); // 7
template<typename T>
T SumMussptr(T* ptr, int size); // 8


template<typename T>
void GenMuss(T muss[], int size, int x) // шаблон генерации одномерного массива по умолчанию от 0 до 20 (Задание 1, 2, 3)
{
	for (int i = 0; i < size; i++)
	{
		muss[i] = rand() % x;
	}
}

template<typename T>
void PrintMuss(T muss[], int size) // Шаблон вывода (печати) одномерного массива (Задание 1, 2, 3)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << muss[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void ReplaceMussPTR(T ptr1, T ptr2, int size) // Подставновка значений указателя 1 в указатеь 2 (для одномерных массивов) (Задание 1). Позже можно обновить для возможности записи нескольких массивов в один.
{
	for (int i = 0; i < size; i++)
	{
		*(ptr2 + i) = *(ptr1 + i);
	}
}

void swap(int* ptr1, int* ptr2) // Функция замены значений двух указателей (Задание 2, 6)
{
	int x{};
	x = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = x;
}

void ReplaceMirrorMussPTR(int* ptr, int size) // Функция отзеркаливания одномерного массива (Задание 2)
{
	for (int i = 0, j = size - 1; i < j; i++, j--)
	{
		swap(&ptr[i], &ptr[j]);
	}
}

void MirrorM1_in_M2(int* ptr1, int* ptr2, int size) // Отзеркаливание Массива 1 в Массив 2 (Задание 3)
{
	for (int i = 0, j = size - 1; i < size; i++, j--)
	{
		*(ptr2 + j) = *(ptr1 + i); 
		//ptr2[j] = ptr1[i]; // второй вариант
	}
}

void CheckSign(int* x) // Функция для определения знаа числа (Задание 5)
{
	if (*x > 0)
		std::cout << "Число " << *x << " положительное" << std::endl;
	else if (*x < 0)
		std::cout << "Число " << *x << " отрицательное" << std::endl;
	else
		std::cout << "Число " << *x << " нулевое" << std::endl;
}

double CulcPtr(double* ptr1, double* ptr2) // Примитивный калбкулятор (Задание 7)
{
	char Ch{};
	std::cout << "Укажите действие с числами (+, -, *, /): ";
	std::cin >> Ch;
	switch (Ch)
	{
	case '+':
		return *ptr1 + *ptr2;
	case '-':
		return *ptr1 - *ptr2;
	case '*':
		return *ptr1 * *ptr2;
	case '/':
		return *ptr1 / *ptr2;
	}
}

template<typename T>
T SumMussptr(T* ptr, int size) // Суммирование массива (задание 8)
{
	T Summ{};
	for (int i = 0; i < size; i++)
	{
		Summ += *(ptr + i);
	}
	// Второй вариант суммирования
	/*for (int i = 0; i < size; i++, ptr++)
	{
		Summ += *ptr;
	}*/
	return Summ;
}

int main_1() // Задание 1. Для работы заменить main_1 на main
{
	/*setlocale(LC_ALL, "ru");
	srand(time(NULL));*/

	const int SIZE{ 10 };
	int Muss1[SIZE]{};
	int Muss2[SIZE]{};
	GenMuss(Muss1, SIZE);
	GenMuss(Muss2, SIZE);
	int* ptrM1 = &Muss1[0]; // 1 вариант присваивания
	int* ptrM2 = Muss2; // 2 вариант присваивания
	std::cout << "Выведем сгенерированный массив 1: ";
	PrintMuss(Muss1, SIZE);
	std::cout << "Выведем сгенерированный массив 2: ";
	PrintMuss(Muss2, SIZE);
	std::cout << "Давайте теперь заменем значения Массива 2 значениями массива 1 и выведем Массив 2: ";
	ReplaceMussPTR(ptrM1, ptrM2, SIZE);
	PrintMuss(Muss2, SIZE);

	return 0;
}

int main_2() // Задание 2. Для работы заменить main_2 на main
{
	/*setlocale(LC_ALL, "ru");
	srand(time(NULL));*/

	const int SIZE{ 10 };
	int Muss[SIZE]{};
	int* ptrM{ nullptr };
	GenMuss(Muss, SIZE);
	PrintMuss(Muss, SIZE);
	ptrM = Muss;
	ReplaceMirrorMussPTR(ptrM, SIZE);
	PrintMuss(Muss, SIZE);

	return 0;
}

int main_3() // Задание 3. Для работы заменить main_3 на main
{
	/*setlocale(LC_ALL, "ru");
	srand(time(NULL));*/

	const int SIZE{ 10 };
	int Muss1[SIZE]{};
	int Muss2[SIZE]{};
	int* ptrM1{ nullptr };
	int* ptrM2{ nullptr };
	ptrM1 = Muss1;
	ptrM2 = Muss2;
	GenMuss(Muss1, SIZE);
	std::cout << "Выведем Массив 1: ";
	PrintMuss(Muss1, SIZE);
	std::cout << "Занесем Массив 1 в Массив 2 в обратном порядке и выведем массив 2: ";
	MirrorM1_in_M2(ptrM1, ptrM2, SIZE);
	PrintMuss(Muss2, SIZE);

	return 0;
}

int main_4() // Задание 4. Для работы заменить main_4 на main
{
	//setlocale(LC_ALL, "ru");
	//srand(time(NULL));

	int Num1{};
	int Num2{};
	std::cout << "Введите число 1 = ";
	std::cin >> Num1;
	std::cout << "Введите число 2 = ";
	std::cin >> Num2;
	int* Max{ nullptr };
	Max = (Num1 > Num2) ? &Num1 : &Num2;
	std::cout << "Наибольшее число из двух " << *Max << std::endl;

	return 0;
}

int main_5() // Задание 5. Для работы заменить main_5 на main
{
	//setlocale(LC_ALL, "ru");
	//srand(time(NULL));

	int Num{};
	std::cout << "Введите число ";
	std::cin >> Num;
	CheckSign(&Num);

	return 0;
}

int main_6() // Задание 6. Для работы заменить main_6 на main
{
	//setlocale(LC_ALL, "ru");
	//srand(time(NULL));

	int Num1{};
	int Num2{};
	std::cout << "Введите число 1 = ";
	std::cin >> Num1;
	std::cout << "Введите число 2 = ";
	std::cin >> Num2;
	std::cout << "Поменяем цисла местами.\n";
	swap(&Num1, &Num2);
	std::cout << "Число 1 = " << Num1 << ", а число 2 = " << Num2 << std::endl;

	return 0;
}

int main_7() // Задание 7. Для работы заменить main_7 на main
{
	/*setlocale(LC_ALL, "ru");*/
	
	double Num1{};
	double Num2{};
	double* ptrN1{ nullptr };
	double* ptrN2{ nullptr };
	ptrN1 = &Num1;
	ptrN2 = &Num2;
	std::cout << "Произведем вычисление с числом ";
	std::cin >> Num1;
	std::cout << " и числом ";
	std::cin >> Num2;
	std::cout << "Результат вычисления " << CulcPtr(ptrN1, ptrN2) << std::endl;

	return 0;
}

int main_8() // Задание 8. Для работы заменить main_8 на main
{
	/*setlocale(LC_ALL, "ru");
	srand(time(NULL));*/

	const int SIZE{ 10 };
	int Muss[SIZE]{};
	int* ptrM{ nullptr };
	GenMuss(Muss, SIZE);
	PrintMuss(Muss, SIZE);
	ptrM = Muss;
	std::cout << "Сумма элементов массива = " << SumMussptr(ptrM, SIZE) << std::endl;

	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	std::cout << "Меню по домашнему заданию на Указатели" << std::endl;
	int Menu{};
	do
	{
		std::cout << "Введите номер задания от 1 до 8, 0 - выход: ";
		std::cin >> Menu;
		switch (Menu)
		{
		case 1:
			std::cout << "Задание 1:\nИспользуя два указателя на массив целых чисел, скопировать один массив в другой.\nИспользовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования." << std::endl << std::endl;
			main_1();
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "Задание 2:\nИспользуя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный.\nИспользовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования." << std::endl << std::endl;
			main_2();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "Задание 3:\nИспользуя два указателя на массивы целых чисел, скопировать один массив в другой так,\nчтобы во втором массиве элементы находились в обратном порядке.\nИспользовать в программе а рифметику указателей для продвижения по массиву, а также оператор разыменования." << std::endl << std::endl;
			main_3();
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "Задание 4:\nИспользуя указатели и оператор разыменования, определить наибольшее из двух чисел." << std::endl << std::endl;
			main_4();
			std::cout << std::endl;
			break;
		case 5:
			std::cout << "Задание 5:\nИспользуя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры." << std::endl << std::endl;
			main_5();
			std::cout << std::endl;
			break;
		case 6:
			std::cout << "Задание 6:\nИспользуя указатели и оператор разыменования, обменять местами значения двух переменных." << std::endl << std::endl;
			main_6();
			std::cout << std::endl;
			break;
		case 7:
			std::cout << "Задание 7:\nНаписать примитивный калькулятор, пользуясь только указателями." << std::endl << std::endl;
			main_7();
			std::cout << std::endl;
			break;
		case 8:
			std::cout << "Задание 8:\nИспользуя указатель на массив целых чисел, посчитать сумму элементов массива.\nИспользовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования." << std::endl << std::endl;
			main_8();
			std::cout << std::endl;
			break;
		}
	} while (Menu != 0);

	return 0;
}