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

int CommonDivisor(int Num1, int Num2);
void GenNum(int Mass[], int size);
int GameBullsCows(int Num);
void PrintNum(int Mass[], int size);
int CowsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]);
int BullsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]);


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

void GenNum(int Mass[], int size) //функция генерации одномерного массива
{
	for (int i = 0; i < size; i++)
	{
		Mass[i] = rand() % 10;
	}
}

void PrintNum(int Mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << Mass[i];
	}
}

int CowsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]) // количество Коров и заполнение специального булевского массива для нахождения в дальнейшем Быков
{
	int Cows{};
	for (int i = 0; i < size; i++)
	{
		if (MassSearch[i] == Muss[i])
		{
			Cows++;
			BoolMass[i] = 1;
		}
	}
	return Cows;
}

int BullsNum(int MassSearch[], int Muss[], int size, bool BoolMass[]) //Количество Быков
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

int GameBullsCows(int MassSearch[], int Muss[], int size, bool BoolMass[])
{
	int MussUser[size]{};
	int NumUser{};
	bool BoolMass[SIZE]{}; /*специальный массив для исключения конкрентной порядковой цифры если она уже ранее прошла проверку на Корову, в противном случае Быки не корректно будут считаться.
	Например если заказдонное число 1041 и пользователь вводит 1111, то программа будет выводить 2 коровы и 6 быков, а должно выводить 2 коровы и 0 быков */
	

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
	setlocale(LC_ALL, "ru");

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

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	const int SIZE{ 4 };
	int SearchNum[SIZE]{};
	GenNum(SearchNum, SIZE);
	PrintNum(SearchNum, SIZE);
	//std::cout << SearchNum << std::endl;
	//std::cout <<"Количество попыток = " << GameBullsCows(SearchNum) << std::endl;

	return 0;
}