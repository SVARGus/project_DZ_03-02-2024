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
#include <string.h>

// список Атрибутов функции



// Реализация функций

//void SearchNewSizeMessage(char*& Message, int Size) // Функция привидения размера Строкового массива к фактически заполненному, до первого детерменирующего нуля - '\0'
//{
//	int NewSize{};
//	for (int i = 0; i < Size && Message[i] != '\0'; i++, NewSize++)
//	{
//		if (Message[i] == '\0')
//			++NewSize;
//	}
//	char *str1[NewSize];
//	strcpy(*str1, *Message);
//	del Message[];
//}



// Основное тело программы с функциями заданий по типу int main_i(), где i это номер задания

int main() // Задание 1. для работы заменить main_1 на main.
{
	setlocale(LC_ALL, "ru");

	int SizeMessage{ 256 }; // По умолчанию размер массива строки установлен с ограничением 255 символами + детерменирующий ноль
	char Message[SizeMessage]{ nullptr };
	char* PtrM = Message;
	std::cin >> *PtrM;

	return 0;
}