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
Сортировка массива по названию книг
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

void PrintBook(const LibraryB* LibBook, const int LibrarySize, int X = 0, int i = 0);
void MenuEditLib(LibraryB* LibBook, const int LibrarySize);
void SearchLib(const LibraryB* LibBook, const int LibrarySize, int search);
void BubbleSort(LibraryB* LibBook, const int LibrarySize, int X);


//		РЕАЛИЗАЦИЯ ФУНКЦИЙ		//
void PrintBook(const LibraryB* LibBook, const int LibrarySize, int X, int i) // (YES / YES)
{
	if (X == 0)
	{
		std::cout << "Название Книги\t| "
			<< "Автор книги  \t| "
			<< "Издательство \t| "
			<< "Жанр книги   \t|" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------------------" << std::endl;
	}
	for (; i < LibrarySize; i++) // Донастроить красивый вывод таблицы в консоли
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

void MenuEditLib(LibraryB* LibBook, const int LibrarySize) // (YES / YES)
{
	enum Menu { ALL = 1, NAME, AUTHOR, PUBLISH, GANRE };
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
	std::cin >> Menu;
	switch (Menu)
	{
	case ALL:
		std::cout << "Укажите название книги: ";
		std::cin >> LibBook[i].NameBook;
		std::cout << "Укажите Фамилию и инициалы автора: ";
		std::cin >> LibBook[i].AuthorBook;
		std::cout << "Укажите название издательства: ";
		std::cin >> LibBook[i].PublishBook;
		std::cout << "Укажите название жанра: ";
		std::cin >> LibBook[i].GanreBook;
		break;
	case NAME:
		std::cout << "Укажите название книги: ";
		std::cin >> LibBook[i].NameBook;
		break;
	case AUTHOR:
		std::cout << "Укажите Фамилию и инициалы автора: ";
		std::cin >> LibBook[i].AuthorBook;
		break;
	case PUBLISH:
		std::cout << "Укажите название издательства: ";
		std::cin >> LibBook[i].PublishBook;
		break;
	case GANRE:
		std::cout << "Укажите название жанра: ";
		std::cin >> LibBook[i].GanreBook;
		break;
	default:
		break;
	}
}

void SearchLib(const LibraryB* LibBook, const int LibrarySize, int search) //Если search = 0 то поиск книги по автору, если = 1 то по названию (YES / YES)
{
	char SearchName[52];
	std::cin >> SearchName;
	int SizeSearch = strlen(SearchName);
	int Size{};
	int X{};
	switch (search)
	{
	case 0:
		for (int i = 0, Y = 1; i < LibrarySize; i++)
		{
			Size = strlen(LibBook[i].AuthorBook);
			for (int j = 0; j < Size; j++)
			{
				if (LibBook[i].AuthorBook[j] == SearchName[0])
				{
					for (int l = 0; l < SizeSearch; l++)
					{
						if (LibBook[i].AuthorBook[j + l] == SearchName[l]) // поиск не по полному наименованию, а по частичному совпадению
						{
							++Y;
							if (SizeSearch == Y)
							{
								PrintBook(LibBook, i + 1, X, i);
								++X;
								break;
							}
						}
						else
							break;
					}

				}
			}
			Y = 1;
		}
		if (X == 0)
			std::cout << "Поиск не дал результатов" << std::endl;
		break;
	case 1:
		for (int i = 0, Y = 1; i < LibrarySize; i++)
		{
			Size = strlen(LibBook[i].NameBook);
			for (int j = 0; j < Size; j++)
			{
				if (LibBook[i].NameBook[j] == SearchName[0])
				{
					for (int l = 0; l < SizeSearch; l++)
					{
						if (LibBook[i].NameBook[j + l] == SearchName[l]) // поиск не по полному наименованию, а по частичному совпадению
						{
							++Y;
							if (SizeSearch == Y)
							{
								PrintBook(LibBook, i + 1, X, i);
								++X;
							}
						}
						else
							break;
					}

				}
			}
			Y = 1;
		}
		if (X == 0)
			std::cout << "Поиск не дал результатов" << std::endl;
		break;
	}
}

void BubbleSort(LibraryB* LibBook, const int LibrarySize, int X) // (YES / YES)
{
	bool swapped{};
	switch (X)
	{
	case 0: // сортировка по названию книги
		do
		{
			swapped = false;
			for (int i = 0; i < LibrarySize - 1; i++)
			{
				if (strcmp(LibBook[i].NameBook, LibBook[i + 1].NameBook) > 0)
				{
					std::swap(LibBook[i], LibBook[i + 1]);
					swapped = true;
				}
			}
		} while (swapped);
		break;
	case 1: // сортировка по автору книги
		do
		{
			swapped = false;
			for (int i = 0; i < LibrarySize - 1; i++)
			{
				if (strcmp(LibBook[i].AuthorBook, LibBook[i + 1].AuthorBook) > 0)
				{
					std::swap(LibBook[i], LibBook[i + 1]);
					swapped = true;
				}
			}
		} while (swapped);
		break;
	case 2: // сортировка по издательству книги
		do
		{
			swapped = false;
			for (int i = 0; i < LibrarySize - 1; i++)
			{
				if (strcmp(LibBook[i].PublishBook, LibBook[i + 1].PublishBook) > 0)
				{
					std::swap(LibBook[i], LibBook[i + 1]);
					swapped = true;
				}
			}
		} while (swapped);
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
	enum LibraryMenu { EXIT = 0, EDITBOOK, PRINTBOOK, SEARCHAUTHOR, SEARCHNAMEBOOK, SORTNAMEBOOK, SORTAUTHOR, SORTPUBLISH };
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
			MenuEditLib(LibBook, LibrarySize);
			system("cls");
			break;
		case PRINTBOOK:
			PrintBook(LibBook, LibrarySize);
			std::cout << "\nДля продолжения нажмите любую клавишу и после Enter ";
			std::cin >> Ch;
			system("cls");
			break;
		case SEARCHAUTHOR:
			SearchLib(LibBook, LibrarySize, 0); //Если = 0 то поиск книги по автору, если = 1 то по названию
			std::cout << "\nДля продолжения нажмите любую клавишу и после Enter ";
			std::cin >> Ch;
			system("cls");
			break;
		case SEARCHNAMEBOOK:
			SearchLib(LibBook, LibrarySize, 1); //Если = 0 то поиск книги по автору, если = 1 то по названию
			std::cout << "\nДля продолжения нажмите любую клавишу и после Enter ";
			std::cin >> Ch;
			system("cls");
			break;
		case SORTNAMEBOOK:
			BubbleSort(LibBook, LibrarySize, 0);
			std::cout << "\nСписок успешно отсортирован по Названию книг ";
			Sleep(1500);
			system("cls");
			break;
		case SORTAUTHOR:
			BubbleSort(LibBook, LibrarySize, 1);
			std::cout << "\nСписок успешно отсортирован по Автору книг";
			Sleep(1500);
			system("cls");
			break;
		case SORTPUBLISH:
			BubbleSort(LibBook, LibrarySize, 2);
			std::cout << "\nСписок успешно отсортирован по Издательству книг ";
			Sleep(1500);
			system("cls");
			break;
		default:
			break;
		}
	} while (Menu != 0);

	return 0;
}