/*
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


int main_Menu() // Главное меню заданий
{
	//int MenuLibStrF{};
	int Menu{};
	std::cout << "Выберети какое задание хотите выполнить от 1 до 9, 0 - это выход. А 10 выбор использования библиотеки cstring (1) или нет (0)" << std::endl;
	do
	{
		switch (Menu)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		/*case 10:
			std::cin >> MenuLibStrF;
			break;*/
		}
	} while (Menu != 0);

	return 0;
}