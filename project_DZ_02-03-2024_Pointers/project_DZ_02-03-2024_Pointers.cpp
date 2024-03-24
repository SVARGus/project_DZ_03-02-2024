/*
Домашнее задание СДБ 311. Домашнее задание от 02.03.2024
				Указатели
*/
/*
Задание 1:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного размера, 
в котором нужно собрать элементы массива A, которыене включаются в массив B, без повторений.

Задание 2:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного размера, 
в котором нужно собрать элементы массивов A и B, которые не являются общими д ля них, без повторений.

Задание 3:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного размера, 
в котором нужно собрать элементы обоих массивов.

Задание 4:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного раз мера, 
в котором нужно собрать общие элементы двух массивов без повторений.

Задание 5:
Дан массив: А[M] (M вводи тся с клавиатуры). 
Необходимо удалить из массива четные или нечетные значения. 
Пользователь вводит данные в массив, а также с помощью меню решает, что нужно удалить.

Задание 6:
Написать функцию, которая получает указатель на динамический массив и его размер. 
Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.

Задание 7:
Написать функцию, которая получает указатель на статический массив и его размер. 
Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы.
*/


#include <iostream>

void GenMuss(int* muss, int size, int k = 11); // 1-5
void PrintMuss(int* muss, int size); // 1-5
int SizeNewMuss_Past_1(int* muss1, int* muss2, int size1, int size2, int* muss3 = 0, int size3 = 0); // 1
int NoRepeatNumMuss(int* muss, int size, int j); // 1
int SizeNewMuss_Past_2(int* muss1, int* muss2, int size1, int size2, int* muss3 = 0, int size3 = 0); // 2
void DateEntryMass(int* muss, int size); // 5
void DelitNum(int* muss, int size, int del); // 5
int PrimeNum(int* muss, int k); // 6


void GenMuss(int* muss, int size, int k) // Случайная генерация одномерного массива (Задание 1-5)
{
	for (int i = 0; i < size; i++)
	{
		muss[i] = rand() % k;
	}
}

void PrintMuss(int* muss, int size) // Вывод одномерного массива (Задание 1-5)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << muss[i] << " ";
	}
	std::cout << std::endl;
}

int SizeNewMuss_Past_1(int* muss1, int* muss2, int size1, int size2, int* muss3, int size3) // Определение размера массива для Задание 1, и одновременно заполняет (при повторном вызове и указании массива 3 и его размера) его если size3 != 0.
{
	int NewSize{};
	for (int i = 0; i < size1; i++)
	{
		int Key{};
		for (int j = 0; j < size2; j++)
		{
			if (muss1[i] == muss2[j])
				Key++;
		}
		if (Key > 0 && NoRepeatNumMuss(muss1, size1, i) == 0)
		{
			if (size3 != 0)
				muss3[NewSize] = muss1[i];
			NewSize++;
		}
	}
	return NewSize;
}

int NoRepeatNumMuss(int* muss, int size, int j) // Исключения повторений в массиве для функции опеделения размера массива (задание 1 и 2)
{
	int Key{};
	for (int i = j+1; i < size; i++)
	{
		if (muss[j] == muss[i])
			Key++;
	}
	return Key;
}

int SizeNewMuss_Past_2(int* muss1, int* muss2, int size1, int size2, int* muss3, int size3) // Определение размера массива для Задание 2
{
	int NewSize{};
	for (int i = 0; i < size1; i++)
	{
		int Key{};
		for (int j = 0; j < size2; j++)
		{
			if (muss1[i] == muss2[j])
				Key++;
		}
		if (Key == 0 && NoRepeatNumMuss(muss1, size1, i) == 0)
		{
			if (size3 != 0)
				muss3[NewSize] = muss1[i];
			NewSize++;
		}
	}
	for (int i = 0; i < size2; i++)
	{
		int Key{};
		for (int j = 0; j < size1; j++)
		{
			if (muss2[i] == muss1[j])
				Key++;
		}
		if (Key == 0 && NoRepeatNumMuss(muss2, size2, i) == 0)
		{
			if (size3 != 0)
				muss3[NewSize] = muss2[i];
			NewSize++;
		}
	}
	return NewSize;
}

void DateEntryMass(int* muss, int size) // Ввод данных в массив (Задание 5)
{
	std::cout << "Введите данные: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> muss[i];
	}
}

void DelitNum(int* muss, int size, int del) // Функция удаления данных масива (задание 5). Если false - удалить четные, если true - удалить не четные.
{
	for (int i = 0; i < size; i++)
	{
		if (muss[i] % 2 == del)
			muss[i] = 0;
	}
}

int PrimeNum(int* muss, int k) // Функция определения является ли значение массива простым числом или нет (если на выходе 0 - то является, если на выходе 1 - то не является) (Задание 6)
{
	for (int i = 2; i < muss[k]; i++)
	{
		if (muss[k] % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void* CreatMussNotPrimeNum(int* muss, int size, int* muss2) // Функция зполнения массива без простых чисел из другого массива
{
	int newsize{};
	for (int i = 0; i < size; i++)
	{
		if (PrimeNum(muss, i) == 1)
			newsize++;
	}
	muss2 = new int[newsize];
	for (int i = 0, k = 0; i < size; i++)
	{
		if (PrimeNum(muss, i) == 1)
		{
			muss2[k] = muss[i];
			k++;
		}
	}
}


int main_1() // Задание 1. Для работы заменить main_1 на main
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int Size1{};
	std::cout << "Введите размер Первого массива = ";
	std::cin >> Size1;
	int Size2{};
	std::cout << "Введите размер Второго массива = ";
	std::cin >> Size2;
	int* Muss1 = new int [Size1];
	std::cout << "Сгенерируем и выведем Массив 1: ";
	GenMuss(Muss1, Size1);
	PrintMuss(Muss1, Size1);
	int* Muss2 = new int[Size2];
	std::cout << "Сгенерируем и выведем Массив 2: ";
	GenMuss(Muss2, Size2);
	PrintMuss(Muss2, Size2);
	int Size3 = SizeNewMuss_Past_1(Muss1, Muss2, Size1, Size2);
	std::cout << "Размер Третьего массива = " << Size3 << std::endl;
	std::cout << "Теперь заполним данные Массива 3 в котором собрем элементы массива 1, которыене включаются в массив 2, без повторений: ";
	int* Muss3 = new int[Size3];
	SizeNewMuss_Past_1(Muss1, Muss2, Size1, Size2, Muss3, Size3);
	PrintMuss(Muss3, Size3);
	delete[] Muss1;
	delete[] Muss2;
	delete[] Muss3;

	return 0;
}

int main_2() // Задание 2. Для работы заменить main_2 на main
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int K{ 21 }; // отвечает за диапазон числа генерации массива (по умолчании в функции стоит от 0 и до 10)
	int Size1{};
	std::cout << "Введите размер Первого массива = ";
	std::cin >> Size1;
	int Size2{};
	std::cout << "Введите размер Второго массива = ";
	std::cin >> Size2;
	int* Muss1 = new int[Size1];
	std::cout << "Сгенерируем и выведем Массив 1: ";
	GenMuss(Muss1, Size1, K);
	PrintMuss(Muss1, Size1);
	int* Muss2 = new int[Size2];
	std::cout << "Сгенерируем и выведем Массив 2: ";
	GenMuss(Muss2, Size2, K);
	PrintMuss(Muss2, Size2);
	int Size3 = SizeNewMuss_Past_2(Muss1, Muss2, Size1, Size2);
	std::cout << "Размер Третьего массива = " << Size3 << std::endl;
	std::cout << "Теперь заполним данные Массива 3 в котором собрем элементы массива 1 и 2, которые не являются общими д ля них, без повторений: ";
	int* Muss3 = new int[Size3];
	SizeNewMuss_Past_2(Muss1, Muss2, Size1, Size2, Muss3, Size3);
	PrintMuss(Muss3, Size3);
	delete[] Muss1;
	delete[] Muss2;
	delete[] Muss3;

	return 0;
}

int main_3() // Задание 3. Для работы заменить main_2 на main
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int K{ 21 }; // отвечает за диапазон числа генерации массива (по умолчании в функции стоит от 0 и до 10)
	int Size1{};
	std::cout << "Введите размер Первого массива = ";
	std::cin >> Size1;
	int Size2{};
	std::cout << "Введите размер Второго массива = ";
	std::cin >> Size2;
	int* Muss1 = new int[Size1];
	std::cout << "Сгенерируем и выведем Массив 1: ";
	GenMuss(Muss1, Size1, K);
	PrintMuss(Muss1, Size1);
	int* Muss2 = new int[Size2];
	std::cout << "Сгенерируем и выведем Массив 2: ";
	GenMuss(Muss2, Size2, K);
	PrintMuss(Muss2, Size2);
	int Size3 = Size1 + Size2;
	std::cout << "Размер Третьего массива = " << Size3 << std::endl;
	int* Muss3 = new int[Size3];
	std::cout << "Теперь заполним данные Массива 3 в котором соберем элементы обоих массивов: ";
	for (int i = 0, j = 0; i < Size3; i++)
	{
		if (i < Size1)
			Muss3[i] = Muss1[i];
		else
			Muss3[i] = Muss2[j++];
	}
	PrintMuss(Muss3, Size3);
	delete[] Muss1;
	delete[] Muss2;
	delete[] Muss3;

	return 0;
}

int main_4() // Задание 4. Для работы заменить main_4 на main (Задание полностью идентично заданию 1, ток формулировка отличается)
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	
	int K{ 21 }; // отвечает за диапазон числа генерации массива (по умолчании в функции стоит от 0 и до 10)
	int Size1{};
	std::cout << "Введите размер Первого массива = ";
	std::cin >> Size1;
	int Size2{};
	std::cout << "Введите размер Второго массива = ";
	std::cin >> Size2;
	int* Muss1 = new int[Size1];
	std::cout << "Сгенерируем и выведем Массив 1: ";
	GenMuss(Muss1, Size1, K);
	PrintMuss(Muss1, Size1);
	int* Muss2 = new int[Size2];
	std::cout << "Сгенерируем и выведем Массив 2: ";
	GenMuss(Muss2, Size2, K);
	PrintMuss(Muss2, Size2);
	int Size3 = SizeNewMuss_Past_1(Muss1, Muss2, Size1, Size2);
	std::cout << "Размер Третьего массива = " << Size3 << std::endl;
	std::cout << "Теперь заполним данные Массива 3 в котором собрем общие элементы двух массивов без повторений: ";
	int* Muss3 = new int[Size3];
	SizeNewMuss_Past_1(Muss1, Muss2, Size1, Size2, Muss3, Size3);
	PrintMuss(Muss3, Size3);
	delete[] Muss1;
	delete[] Muss2;
	delete[] Muss3;

	return 0;
}

int main_5() // Задание 5. Для работы заменить main_5 на main
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int Size{};
	std::cout << "Введите размер массива = ";
	std::cin >> Size;
	int* Muss = new int[Size];
	int Menu{};
	do
	{
		std::cout << "Выберите действие с массивом: \n1) рандомная генерация массива.\n2) Ручной ввод данных в массив.\n3) Удалить из массива четные значения.\n4) Удалить из массива не четные значения\n5) Выход.\nВаш выбор: ";
		std::cin >> Menu;
		switch (Menu)
		{
		case 1:
			GenMuss(Muss, Size);
			PrintMuss(Muss, Size);
			break;
		case 2:
			DateEntryMass(Muss, Size);
			PrintMuss(Muss, Size);
			break;
		case 3:
			DelitNum(Muss, Size, 0);
			PrintMuss(Muss, Size);
			break;
		case 4:
			DelitNum(Muss, Size, 1);
			PrintMuss(Muss, Size);
			break;
		}
	} while (Menu != 5);
	delete[] Muss;

	return 0;
}

int main() // Задание 6. Для работы заменить main_6 на main
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int Size{};
	std::cout << "Введите размер массива = ";
	std::cin >> Size;
	int* Muss = new int[Size];
	std::cout << "Сгенерируем новый массив и выведем его на экарн: ";
	GenMuss(Muss, Size);
	PrintMuss(Muss, Size);
	int* Muss2{nullptr};
	CreatMussNotPrimeNum(Muss, Size, Muss2);
	

	return 0;
}