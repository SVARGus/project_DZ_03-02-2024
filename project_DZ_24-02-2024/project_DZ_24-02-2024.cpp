/*
Домашнее задание СДБ 311. Домашнее задание от 24.02.2024
				Рекурсия
*/

/*
Задание 1:
Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.

Задание 2:
Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющ ий должен угадать его. 
После ввода пользователем числа программа сообщает, сколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). 
После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток. В программе необходимо использовать рекурсию.

Задание 3:
Дана шахматная доска размером 8х8 и шахматный конь. Программа должна запросить у пользователя координаты клетки поля и поставить туда коня. 
Задача программы найти и вывести путь коня, при котором он обойдет все клетки доски, становясь в каждую клетку только один раз. 
(Так как процесс отыскания пути для разных начальных клеток может затянуться, то рекомендуется сначала опробовать задачу на поле размером 6х6). 
В программе необходимо использовать рекурсию.

Задание 4:
Написать рекурсивную функцию нахождения степени числа.

Задание 5:
Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь.
Проиллюстрируйте работу функции примером.

Задание 6:
Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.
Пользователь вводит a и b. Проиллюстрируйте работу функции примером.

Задание 7:
Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел , заполненных случайным образом , и находит позицию, 
с которой начинается последовательность из 10 чисел, сумма которых минимальна.
*/

#include <iostream>

int CommonDivisor(int Num1, int Num2); // 1
void GenNum(int Mass[], int size, int x = 10); // 2 и 7
void PrintNum(int Mass[], int size); // 2 и 7
int CowsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]); // 2
int BullsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]); // 2
void MussNumUser(int NumUser, int Muss[], int size); // 2
int GameBullsCows(int MassSearch[], int Muss[], int size, bool BoolMass[], int NumAttempts); // 2
int Exponentiation(int a, int n); // 4
void PrintChar(char x, int n); // 5
int SumAB(int a, int b); // 6
int MinNum(int a, int b); // 6
int MaxNum(int a, int b); // 6
int SearchISumMuss(int Muss[], int Size, int MinSum, int i = 0, int Key = 0, int SizeSum = 10); // 7
int SumMuss10(int Muss[], int i, int k = 0); // 7


int CommonDivisor(int Num1, int Num2) //Функция рекурсии по заданию 1, Использовал алгоритм Евклида
{
	int x{}; //делитель
	int NumX{}; //остаток
	x = Num1 / Num2;
	NumX = Num1 - Num2 * x;
	if (NumX == 0)
		return Num2;
	CommonDivisor(Num2, NumX);
}

void GenNum(int Mass[], int size, int x) //функция генерации одномерного массива по заданию 2 и 7
{
	for (int i = 0; i < size; i++)
	{
		Mass[i] = rand() % x;
	}
}

void PrintNum(int Mass[], int size) //функция вывода одномерного массива для задания 2 и 7
{
	for (int i = 0; i < size; i++)
	{
		std::cout << Mass[i] << " ";
	}
	std::cout << std::endl;
}

int CowsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]) // количество Коров и заполнение специального булевского массива для нахождения в дальнейшем Быков (задание 2)
{
	int Cows{};
	for (int i = 0; i < size; i++)
	{
		if (MassSearch[i] == Muss[i])
		{
			Cows++;
			BoolMass[i] = 1;
		}
		else
			BoolMass[i] = 0;
	}
	return Cows;
}

int BullsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]) //Количество Быков (задание 2)
{
	int Bulls{};
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (BoolMass[i] != 1 && MassSearch[i] == Muss[j] && BoolMass[j] != 1)
			{
				Bulls++;
			}
		}
	}
	return Bulls;
}

void MussNumUser(int NumUser, int Muss[], int size) //перевод вводимого числа пользователем в массив (задание 2)
{
	for (int i = size - 1; i >= 0; i--)
	{
		Muss[i] = NumUser % 10;
		NumUser /= 10;
	}
}


int GameBullsCows(int MassSearch[], int Muss[], int size, bool BoolMass[], int NumAttempts = 1) // игра Быки и коровы (задание 2)
{
	int y{ 1 };
	int NumUser{};
	std::cout << "Введите ваше число: ";
	std::cin >> NumUser;
	MussNumUser(NumUser, Muss, size);
	std::cout << "Количество коров = " << CowsNum(MassSearch, Muss, size, BoolMass);
	std::cout << ". Количество быков = " << BullsNum(MassSearch, Muss, size, BoolMass) << std::endl;
	if (CowsNum(MassSearch, Muss, size, BoolMass) == 4)
		return NumAttempts;
	else
	{
		NumAttempts++;
		GameBullsCows(MassSearch, Muss, size, BoolMass, NumAttempts);
	}
}

int Exponentiation(int a, int n) // возведение в степень через рекурсию (задание 4)
{
	int x{};
	if (n == 1)
		return a;
	else
		x = a * Exponentiation(a, --n);
	return x;
}

void PrintChar(char x, int n) // вывод звезд в ряд N раз (задание 5)
{
	if (n == 0)
		return;
	PrintChar(x, --n);
	std::cout << "* ";
}

int SumAB(int a, int b) // Сумма чисел от А до В (задание 6)
{
	if (a < b)
		return a + SumAB(a+1, b);
}

int MinNum(int a, int b) // Определение минимального числа из двух чисел (Для задания 6)
{
	return (a < b) ? a : b;
}

int MaxNum(int a, int b) // Определение максимального числа из двух чисел (Для задания 6)
{
	return (a > b) ? a : b;
}

int SearchISumMuss(int Muss[], int Size, int MinSum, int i, int Key, int SizeSum) // Определение индекса массива с минимальной суммой последовательных чисел i+9 (задание 7)
{
	if (MinSum > SumMuss10(Muss, i))
	{
		Key = i;
		MinSum = SumMuss10(Muss, i);
		//std::cout << "Key " << Key << " Min " << MinSum << std::endl; // временный вывод позиции с минимальной суммой
	}
	if (i == Size - SizeSum)
		return Key;
	else
		SearchISumMuss(Muss, Size, MinSum, i + 1, Key);
}

int SumMuss10(int Muss[], int i, int k) // Сумма 10 последовательных чисел массива включая i (Задание 7)
{
	if (++k <= 10)
		return Muss[i] + SumMuss10(Muss, i + 1, k);
}

/*int GameBullsCows(int Num)
{
	int NumAttempts{ 0 }; // надо понять как вывести верное количество попыток
	int NumUser{};
	std::cout << "Введите ваше четырехзначное число: ";
	std::cin >> NumUser;
	int Bulls{}; //Быки, сколько угадано чисел
	int Cows{}; //Коровы, сколько угадано чисел и стоит на своем месте
	for (int i{}, x{}, NumX = Num, x1{}; i < 4; i++, x1=0)
	{
		x = NumX % 10;
		for (int j{}, y{}, NumY = NumUser; j < 4; j++)
		{
			y = NumY % 10;
			if (i == j && x == y)
			{
				Cows++;
			}
			else if (x == y && i != j)
			{
				x1++;
			}
			NumY /= 10;
		}
		if (x1 == 1)
		{
			Bulls++;
		}
		NumX /= 10;
	}
	std::cout << "Количество Быков = " << Bulls << std::endl;
	std::cout << "Количество Коров = " << Cows << std::endl;
	++NumAttempts;
	if (Cows == 4)
		return NumAttempts;
	GameBullsCows(Num);
	return NumAttempts;
}*/




int main_1() // Тело программы для задания 1, для работы заменить main_1 на main
{
	/*setlocale(LC_ALL, "ru");*/

	int Num1{};
	int Num2{};
	std::cout << "Введите первое число = ";
	std::cin >> Num1;
	std::cout << "Введите второе число число = ";
	std::cin >> Num2;
	if (Num1 >= Num2)
		std::cout << "Наибольшый общий делитель числа " << Num1 << " и числа " << Num2 << " = " << CommonDivisor(Num1, Num2) << std::endl;
	else
		std::cout << "Наибольшый общий делитель числа " << Num1 << " и числа " << Num2 << " = " << CommonDivisor(Num2, Num1) << std::endl;

	return 0;
}

int main_2() // Тело программы для задания 2, для работы заменить main_2 на main
{
	/*setlocale(LC_ALL, "ru");
	srand(time(NULL));*/

	const int SIZE{ 4 };
	int SearchNum[SIZE]{};
	int MussUser[SIZE]{};
	GenNum(SearchNum, SIZE);
	//PrintNum(SearchNum, SIZE); // позже надо закомитить
	bool BoolMass[SIZE]{}; /*специальный массив для исключения конкрентной порядковой цифры если она уже ранее прошла проверку на Корову, в противном случае Быки не корректно будут считаться.
	Например если заказдонное число 1041 и пользователь вводит 1111, то программа будет выводить 2 коровы и 6 быков, а должно выводить 2 коровы и 0 быков */
	std::cout <<"Количество попыток = " << GameBullsCows(SearchNum, MussUser, SIZE, BoolMass) << std::endl;

	return 0;
}

int main_4() // Тело программы для задания 4, для работы заменить main_4 на main
{
	/*setlocale(LC_ALL, "ru");*/

	int a{}; // возводимое число
	int n{}; //степень
	std::cout << "Введите возводимое число = ";
	std::cin >> a;
	std::cout << "Введите в какую степень возводите = ";
	std::cin >> n;
	std::cout << "Результат возведения числа " << a << " в степень " << n << " = " << Exponentiation(a, n) << std::endl;

	return 0;
}

int main_5() // Тело программы для задания 5, для работы заменить main_5 на main
{
	/*setlocale(LC_ALL, "ru");*/

	char Z{'*'};
	int N{};
	std::cout << "Сколько раз вывести звезд в ряд? ";
	std::cin >> N;
	PrintChar(Z, N);

	return 0;
}

int main_6() // Тело программы для задания 6, для работы заменить main_6 на main
{
	/*setlocale(LC_ALL, "ru");*/

	int A{};
	int B{};
	std::cout << "Введите число A = ";
	std::cin >> A;
	std::cout << "Введите число B = ";
	std::cin >> B;
	std::cout << "Сумма чисел от " << MinNum(A, B) << " до " << MaxNum(A, B) << " = " << SumAB(MinNum(A, B), MaxNum(A, B)) << std::endl;

	return 0;
}

int main_7() // Тело программы для задания 7, для работы заменить main_7 на main
{
	/*setlocale(LC_ALL, "ru");
	srand(time(NULL));*/

	const int SIZE{ 100 };
	int Muss100[SIZE]{};
	GenNum(Muss100, SIZE, 20);
	PrintNum(Muss100, SIZE); // вывод массива, временно или оставить
	std::cout << std::endl;
	int MinSum = SumMuss10(Muss100, 0);
	//std::cout << "Минимальная сумма " << MinSum << std::endl; // временный вывод суммы с 0 позиции
	std::cout << "Позиция с минимальной суммой 10 послеждовательных чисел = " << SearchISumMuss(Muss100, SIZE, MinSum) << std::endl;

	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int Menu{};
	do
	{
		std::cout << "Выбирете ДЗ для его выполнения с 1 по 7, 0 - выход: ";
		std::cin >> Menu;
		switch (Menu)
		{
		case 1:
			main_1();
			break;
		case 2:
			main_2();
			break;
		case 3:
			std::cout << "Задание с шахмотной доской пока не выполнено, ожидайте обновления )))" << std::endl;
			break;
		case 4:
			main_4();
			break;
		case 5:
			main_5();
			break;
		case 6:
			main_6();
			break;
		case 7:
			main_7();
			break;
		}
	} while (Menu != 0);

	return 0;
}