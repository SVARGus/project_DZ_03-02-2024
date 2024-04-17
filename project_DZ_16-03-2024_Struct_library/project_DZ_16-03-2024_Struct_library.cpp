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

struct LibraryB
{
	char NameBook[30]; // Название книги
	char AuthorBook[50]; // Автор книги (состоит из Имени и Фамилии)
	char FirsNameAuthor[15]; // Имя автора
	char LastNameAuthor[35]; // Фамилия автора
	char PublishBook[40]; // Издательство
	char GanreBook[20]; // Жанр книги
};

int main()
{
	setlocale(LC_ALL, "ru");

	FILE* LibraryF;
	const char* direct = "Library.txt";
	int LibrarySize{};
	if ((fopen_s(&LibraryF, direct, "r")) != NULL)
		std::cout << "!!!Ошибка загрузки Библиотеки книг!!!" << std::endl;
	else
	{
		fscanf_s(LibraryF, "%d ", &LibrarySize);
		fscanf_s(LibraryF, "\n ");
		LibraryB* LibBook = new LibraryB[LibrarySize]{};
		for (int i = 0; i < LibrarySize; i++)
		{
			fscanf_s(LibraryF, "%s ", LibBook[i].NameBook);
			fscanf_s(LibraryF, "%s ", LibBook[i].FirsNameAuthor);
			fscanf_s(LibraryF, "%s ", LibBook[i].LastNameAuthor);
			fscanf_s(LibraryF, "%s ", LibBook[i].PublishBook);
			fscanf_s(LibraryF, "%s ", LibBook[i].GanreBook);
			strcat(LibBook[i].AuthorBook, LibBook[i].FirsNameAuthor);
			strcat(LibBook[i].AuthorBook, " ");
			strcat(LibBook[i].AuthorBook, LibBook[i].LastNameAuthor); // Может проверить запись сразу в полное имя ФИО через "%s %s"
		}
	}
	enum LibraryMenu {EXIT = 0, EDITBOOK, PRINTBOOK, SEARCHAUTHOR, SEARCHNAMEBOOK, SORTNAMEBOOK, SORTAUTHOR, SORTPUBLISH};
	int Menu{};
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
			break;
		case EDITBOOK:
			break;
		case PRINTBOOK:
			break;
		case SEARCHAUTHOR:
			break;
		case SEARCHNAMEBOOK:
			break;
		case SORTNAMEBOOK:
			break;
		case SORTAUTHOR:
			break;
		case SORTPUBLISH:
			break;
		default:
			break;
		}
	} while (Menu != 0);

	return 0;
}