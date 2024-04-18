/*
Домашнее задание СДБ 311. Домашнее задание от 16.03.2024
				Структуры
*/

/*
Задание 3:
Разработайтепрограмму «Библиотека». Создайте структуру «Книга» ( название,автор, издательство, жанр).
Создайте массив из 10 книг. Реализуйте для него следующие возможности:
Редактировать книгу 
Печать всех книг 
Поиск книг по автору 
Поиск книги по названию 
Сортировка массива по наз ванию книг 
Сортировка массива по автору 
Сортировка массива по издательству
*/

#include <iostream>
#include <Windows.h>
#include <cstring>
#include <chrono>
#include <cstdio>

struct LibraryB
{
	char NameBook[30]; // Название книги
	char AuthorBook[52]; // Автор книги (Фамилия и инициалы)
	char PublishBook[40]; // Издательство
	char GanreBook[20]; // Жанр книги
};

//		ПРОТОТИПЫ ФУНКЦИЙ		//

void PrintBook(const LibraryB* LibBook, const int LibrarySize);


//		РЕАЛИЗАЦИЯ ФУНКЦИЙ		//
void PrintBook(const LibraryB* LibBook, const int LibrarySize)
{
	std::cout	<< "Название Книги\t| "
				<< "Автор книги  \t| "
				<< "Издательство \t| "
				<< "Жанр книги   \t|" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < LibrarySize; i++) // Донастроить красивый вывод таблицы в консоли
	{
		if (strlen(LibBook[i].NameBook) <= 7)
			std::cout << LibBook[i].NameBook << "\t\t| ";
		else if (strlen(LibBook[i].NameBook) <= 15)
			std::cout << LibBook[i].NameBook << "\t| ";
		else
			std::cout << LibBook[i].NameBook << "| ";

		if (strlen(LibBook[i].AuthorBook) <= 5)
			std::cout << LibBook[i].AuthorBook << "\t\t| ";
		else if (strlen(LibBook[i].AuthorBook) <= 15)
			std::cout << LibBook[i].AuthorBook << "\t| ";
		else
			std::cout << LibBook[i].AuthorBook << "| ";

		if (strlen(LibBook[i].PublishBook) <= 7)
			std::cout << LibBook[i].PublishBook << "\t| ";
		else if (strlen(LibBook[i].PublishBook) <= 15)
			std::cout << LibBook[i].PublishBook << "\t| ";
		else
			std::cout << LibBook[i].PublishBook << "| ";

		if (strlen(LibBook[i].GanreBook) <= 5)
			std::cout << LibBook[i].GanreBook << "\t\t| " << std::endl;
		else if (strlen(LibBook[i].GanreBook) <= 15)
			std::cout << LibBook[i].GanreBook << "\t| " << std::endl;
		else
			std::cout << LibBook[i].GanreBook << "|\t" << std::endl;
	}
}

void MenuEditLib(LibraryB* LibBook, const int LibrarySize)
{
	enum Menu{ ALL = 1, NAME, AUTHOR, PUBLISH, GANRE};
	int Menu{};
	int i{};
	std::cout << "Укажите какую позицию в базе будете править, от 0 до " << LibrarySize << ": ";
	std::cin >> i;
	std::cout << "Теперь укажите какие данные будите менять\n"
		<< "\t(1) Полные данные\n"
		<< "\t(2) Название книги\n"
		<< "\t(3) Имя и Фамилия автора\n"
		<< "\t(4) Издательство\n"
		<< "\t(5) Жанр книги\n" << std::endl;
	switch (Menu)
	{
	case ALL:
		std::cout << "Укажите название книги: ";
		std::cin >> LibBook[i].NameBook;
		std::cout << "Укажите Имя и Фамилию автора: ";
		std::cin >> LibBook[i].AuthorBook;
		std::cout << "Укажите название издательства: ";
		std::cin >> LibBook[i].PublishBook;
		std::cout << "Укажите название жанра: ";
		std::cin >> LibBook[i].GanreBook;
		break;
	case NAME:
		break;
	case AUTHOR:
		break;
	case PUBLISH:
		break;
	case GANRE:
		break;
	default:
		break;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

	FILE* LibraryF;
	const char* direct = "Library.txt";
	int LibrarySize{};
	LibraryB* LibBook{};
	if ((fopen_s(&LibraryF, direct, "r")) != NULL)
		std::cout << "!!!Ошибка загрузки Библиотеки книг!!!" << std::endl;
	else
	{
		fscanf_s(LibraryF, "%d ", &LibrarySize);
		fscanf_s(LibraryF, "\n ");
		LibBook = new LibraryB[LibrarySize]{};
		for (int i = 0; i < LibrarySize; i++)
		{
			fscanf_s(LibraryF, "%s ", LibBook[i].NameBook, sizeof(LibBook[i].NameBook));
			fscanf_s(LibraryF, "%s ", LibBook[i].AuthorBook, sizeof(LibBook[i].AuthorBook));
			fscanf_s(LibraryF, "%s ", LibBook[i].PublishBook, sizeof(LibBook[i].PublishBook));
			fscanf_s(LibraryF, "%s ", LibBook[i].GanreBook, sizeof(LibBook[i].GanreBook));
		}
	}
	if (fclose(LibraryF) == EOF)
		std::cout << "Ошибка завершения загрузки Библиотечной базы!!! Перезапустите программу" << std::endl;
	else
		std::cout << "Библиотечная база успешно загружена!" << std::endl;
	Sleep(1500);
	system("cls");
	enum LibraryMenu {EXIT = 0, EDITBOOK, PRINTBOOK, SEARCHAUTHOR, SEARCHNAMEBOOK, SORTNAMEBOOK, SORTAUTHOR, SORTPUBLISH};
	int Menu{};
	char Ch{};
	do
	{
		std::cout << "Меню библиотеки" << std::endl;
		std::cout << "(1) Редактировать книгу\n"
			<< "(2) Печать всех книг\n"
			<< "(3) Поиск книг по автору\n"
			<< "(4) Поиск книги по названию\n"
			<< "(5) Сортировка массива по названию книг\n"
			<< "(6) Сортировка массива по автору\n"
			<< "(7) Сортировка массива по издательству\n"
			<< "(0) ВЫХОД" << std::endl;
		std::cin >> Menu;
		switch (Menu)
		{
		case EXIT:
			delete[]LibBook;
			return 0;
			break;
		case EDITBOOK:
			
			system("cls");
			break;
		case PRINTBOOK:
			PrintBook(LibBook, LibrarySize);
			std::cout << "\nДля продолжения нажмите любую клавишу и после Enter ";
			std::cin >> Ch;
			system("cls");
			break;
		case SEARCHAUTHOR:

			system("cls");
			break;
		case SEARCHNAMEBOOK:

			system("cls");
			break;
		case SORTNAMEBOOK:

			system("cls");
			break;
		case SORTAUTHOR:

			system("cls");
			break;
		case SORTPUBLISH:

			system("cls");
			break;
		default:
			break;
		}
	} while (Menu != 0);

	return 0;
}