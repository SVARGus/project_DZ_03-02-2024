﻿/*
Домашнее задание СДБ 311. Домашнее задание от 02.03.2024
				Строки
*/
/*
Задание 1:
Написать функцию, которая удаляет из строки символ с заданным номером.

Задание 2:
Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.

Задание 3:
Написать функцию, которая вставляет в строку в указанную позицию заданный символ.

Задание 4:
Написатьпрограмму,котораязаменяетвсесимволыточки"."встроке,введенной пользователем, на символы восклицательного знака "!".

Задание 5:
Пользовательвводит строку символов и искомый символ, посчитать сколько раз он встречается в строке.

Задание 6:
Пользователь вводит строку. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.

Рекомендации:
Для проверки , что символ является числом, не обязательно сравнивать его со всеми 10-ю цифрами, 
достаточно сравнить код символа с диапазоном кодов цифр. Код символа 0 – 48, 1 – 49, 2 – 50 …. 9 – 57.

Задание 7:
Дана строка символов. Заменить в ней все пробелы на табуля ции.

Задание 8:
Дана строка символов. Определить количество букв, цифр и остальных символов, присутствующих в строке.

Задание 9:
Подсчитать количество слов во введенном предложении.

Задание 10:
Дана строкасимволов. Необходимо проверить является ли этастрока палиндромом.
*/

#include <iostream>
#include <cstring>

// список Прототипов функций

void DelPoint(char* mass, int point); // 1
void DelCharPoint(char* mass, char point); // 2
void SetPositionSymbol(char* mass, int point, char symbol); // 3
void ReplaceSymbolMass(char* mass, char searchsymbol, char symbol); // 4, 7
int SearchSymbol(char* mass, char symbol, int i = 0); // 5
void VolumSymbol(char* mass, int* VolumABC, int* VolumNum, int* VolumSymbol1); // 6, 8

// Реализация функций

void DelPoint(char* mass, int point) // Функция удаления определенного символа с заданным номером (Задание 1)
{
	int size = strlen(mass);
	if (point <= size)
	{
		for (int i = point, j = point+1; i <= size; i++, j++)
			mass[i] = mass[j];
	}
	else
		std::cout << "Удаляемый номер символа " << point << " за пределами размера текста!" << std::endl;
}

void DelCharPoint(char* mass, char point) // Функция удаления определенного заданного символа (Задание 2)
{
	int size = strlen(mass);
	for (int i = 0, j = 0; j <= size; i++, j++)
	{
		if (mass[i] != point)
			mass[j] = mass[i];
		else
			--j;
	}
}

void SetPositionSymbol(char* mass, int point, char symbol) // Функция замены указанной позиции заданным символом (Задание 3)
{
	int size = strlen(mass);
	if (point <= size)
		mass[point] = symbol;
	else
		std::cout << "Заменяемый символ под номером " << point << " за пределами размера текста!" << std::endl;

}

void ReplaceSymbolMass(char* mass, char searchsymbol, char symbol) // Функция замены символов в тексте (задание 4 и 7)
{
	int size = strlen(mass);
	for (int i = 0; i <= size; i++)
	{
		if (mass[i] == searchsymbol)
			mass[i] = symbol;
	}
}

int SearchSymbol(char* mass, char symbol, int i) // Функция подсчета количества введенного символа, реализовал через рекурсию, i при первом запуске по умолчанию 0 (задание 5)
{
	for (; i <= strlen(mass); i++)
	{
		if (mass[i] == symbol)
			return 1 + SearchSymbol(mass, symbol, ++i);
	}
	return 0;
}

void VolumSymbol(char* mass, int* VolumABC, int* VolumNum, int* VolumSymbol1) // Функция для вычисления количества символов, бук и цифр (задание 6 и 8)
{
	int size = strlen(mass);
	for (int i = 0; i <= size; i++)
	{
		if (mass[i] >= 48 && mass[i] <= 57)
			*VolumNum += 1;
		else if ((mass[i] >= 65 && mass[i] <= 90) || (mass[i] >= 97 && mass[i] <= 122))
			*VolumABC += 1;
		else
			*VolumSymbol1 += 1;
	}
}

// Основное тело программы с функциями заданий по типу int main_i(), где i это номер задания

int main_1() // Задание 1. для работы заменить main_1 на main.
{
	setlocale(LC_ALL, "ru");
		
	char Message[]{ "Жил-был ежик-бегун. Он любил бегать по лесу и собирать грибы. Однажды он решил пробежать марафон. Но не тут то было. Оказалось, что он забыл надеть кроссовки." };
	std::cout << "Давайте удалим определенное значение из предложенного текста: " << Message << std::endl;
	int Point{};
	int MenuDel{};
	do
	{
		std::cout << "Укажите позицию: ";
		std::cin >> Point;
		DelPoint(Message, Point);
		std::cout << Message << std::endl;
		std::cout << "Хотите еще удалить символ? если да - нажмите 1, нет - 0: " << std::endl;
		std::cin >> MenuDel;
	} while (MenuDel != 0);

	return 0;
}

int main_2() // Задание 2. для работы заменить main_2 на main.
{
	setlocale(LC_ALL, "ru");
	/*
	Почемуто если в массиве кирилица и при вводе знака для удаления он не удаляется, унжно уточнить и разобраться
	*/
	char Message[]{ "Once upon a time there was a hedgehog runner. He loved to run through the woods and pick mushrooms. One day he decided to run a marathon. But that was not the case." };
	std::cout << "Давайте удалим определенное символ из предложенного текста: " << Message << std::endl;
	char Point{};
	int MenuDel{};
	do
	{
		std::cout << "Укажите символ: ";
		std::cin >> Point;
		DelCharPoint(Message, Point);
		std::cout << Message << std::endl;
		std::cout << "Хотите еще удалить символ? если да - нажмите 1, нет - 0: " << std::endl;
		std::cin >> MenuDel;
	} while (MenuDel != 0);

	return 0;
}

int main_3() // Задание 3. для работы заменить main_3 на main.
{
	setlocale(LC_ALL, "ru");

	char Message[]{ "Жил-был ежик-бегун. Он любил бегать по лесу и собирать грибы. Однажды он решил пробежать марафон. Но не тут то было. Оказалось, что он забыл надеть кроссовки." };
	std::cout << "Давайте вставим символ вопределенное место предложенного текста: " << Message << std::endl;
	int Point{};
	char Symbol{};
	int MenuDel{};
	do
	{
		std::cout << "Укажите символ: ";
		std::cin >> Symbol;
		std::cout << "И куда вставить: ";
		std::cin >> Point;
		SetPositionSymbol(Message, Point, Symbol);
		std::cout << Message << std::endl;
		std::cout << "Хотите еще заменить символ? если да - нажмите 1, нет - 0: " << std::endl;
		std::cin >> MenuDel;
	} while (MenuDel != 0);

	return 0;
}

int main_4() // Задание 4. для работы заменить main_4 на main.
{
	setlocale(LC_ALL, "ru");

	const int SIZE{ 100 };
	char Message[SIZE]{};
	std::cout << "Введите любое предложение длиной не более " << SIZE - 1 << " и обязательно используйте символы '.' и ','" << std::endl;
	std::cin >> Message;
	std::cout << "Ваше предложение: " << Message << std::endl;
	char SymbolSearch{};
	std::cout << "Какой символ из текста вы хотите заменить? ";
	std::cin >> SymbolSearch;
	char Symbol{};
	std::cout << "И на какой? ";
	std::cin >> Symbol;
	ReplaceSymbolMass(Message, SymbolSearch, Symbol);
	std::cout << "Произведен замену символов и выведем вновь текст: " << Message << std::endl;

	return 0;
}

int main_5() // Задание 5. для работы заменить main_5 на main.
{
	setlocale(LC_ALL, "ru");

	const int SIZE{ 51 };
	char Message[SIZE]{};
	std::cout << "Введите любые символы в количестве не более " << SIZE - 1 << std::endl;
	std::cin >> Message;
	std::cout << "Теперь давайте виберем какой символ будем искать в ранее введенных символах: ";
	char SymbolSearch{};
	std::cin >> SymbolSearch;
	std::cout << "Искомый символ " << SymbolSearch << " встречается в массиве символво " << SearchSymbol(Message, SymbolSearch) << " раз." << std::endl;

	return 0;
}

int main_6() // Задание 6. для работы заменить main_6 на main.
{
	setlocale(LC_ALL, "ru");

	const int SIZE{ 100 };
	char Message[SIZE]{};
	std::cout << "Введите любое предложение на латинице длиной не более " << SIZE - 1 << std::endl;
	std::cin >> Message; // При вводе текста с использованием пробела, пробел программа считает окончанием ввода текста (Как с этим бороться или это особенность такая?)
	std::cout << "Ваш введенная строка: " << Message << std::endl;
	int VolumABC{}; // количество букв
	int VolumNum{}; // количество цифр
	int VolumSymbol1{}; // количество символов
	VolumSymbol(Message, &VolumABC, &VolumNum, &VolumSymbol1);
	std::cout << "В строке количество букв = " << VolumABC << ". Количество цифр = " << VolumNum << ". Количество прочих символов = " << VolumSymbol1 << std::endl;

	return 0;
}

int main_7() // Задание 7. для работы заменить main_7 на main. Аналог 4 Задания.
{
	setlocale(LC_ALL, "ru");

	char Message[]{ "Once upon a time there was a hedgehog runner. He loved to run through the woods and pick mushrooms. One day he decided to run a marathon. But that was not the case." };
	std::cout << "Ваше предложение: " << Message << std::endl;
	char SymbolSearch{' '};
	char Symbol{'\t'};
	ReplaceSymbolMass(Message, SymbolSearch, Symbol);
	std::cout << "Произведен замену пробелов на табуляцию и выведем вновь текст: " << Message << std::endl;

	return 0;
}

int main_9() // Задание 8. для работы заменить main_8 на main. Аналог 6 Задания.
{
	setlocale(LC_ALL, "ru");

	char Message[]{ "She makes $20,000 a month to make 1-minute YouTube videos. Inside Google’s strategy to beat TikTok" };
	std::cout << "Строка текста: " << Message << std::endl;
	int VolumABC{};
	int VolumNum{};
	int VolumSymbol1{}; // что делать если имя переменной совподает с именем функции?
	VolumSymbol(Message, &VolumABC, &VolumNum, &VolumSymbol1);
	std::cout << "В строке количество букв = " << VolumABC << ". Количество цифр = " << VolumNum << ". Количество прочих символов = " << VolumSymbol1 << std::endl;

	return 0;
}

int main() // Задание 9. для работы заменить main_9 на main.
{
	setlocale(LC_ALL, "ru");



	return 0;
}

//int main_Menu() // Главное меню заданий
//{
//	setlocale(LC_ALL, "ru");
//	//int MenuLibStrF{};
//	int Menu{};
//	std::cout << "Выберети какое задание хотите выполнить от 1 до 10, 0 - это выход." << std::endl;
//	do
//	{
//		std::cin >> Menu;
//		switch (Menu)
//		{
//		case 1:
//			main_1();
//			break;
//		case 2:
//			main_2();
//			break;
//		case 3:
//			main_3();
//			break;
//		case 4:
//			main_4();
//			break;
//		case 5:
//			main_5();
//			break;
//		case 6:
//			main_6();
//			break;
//		case 7:
//			main_7();
//			break;
//		case 8:
//			main_8();
//			break;
//		case 9:
//			main_9();
//			break;
//		case 10:
//			break;
//		}
//	} while (Menu != 0);
//
//	return 0;
//}