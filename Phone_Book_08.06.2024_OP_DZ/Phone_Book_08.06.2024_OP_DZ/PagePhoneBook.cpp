#include "PagePhoneBook.h"


#pragma warning(disable:4996)
void PagePhoneBook::setFirstName(char* name) {
	if (FirstName != nullptr)
	{
		delete[] FirstName;
		FirstName = nullptr;
	}
	if (name != nullptr)
	{
		int Size = strlen(name) + 1;
		FirstName = new char[Size];
		strcpy(FirstName, name);
	}
}
void PagePhoneBook::setMiddleName(char* name) {
	if (MiddleName != nullptr)
	{
		delete[] MiddleName;
		MiddleName = nullptr;
	}
	if (name != nullptr)
	{
		int Size = strlen(name) + 1;
		MiddleName = new char[Size];
		strcpy(MiddleName, name);		
	}
}
void PagePhoneBook::setLastName(char* name) {
	if (LastName != nullptr)
	{
		delete[] LastName;
		LastName = nullptr;
	}
	if (name != nullptr)
	{
		int Size = strlen(name) + 1;
		LastName = new char[Size];
		strcpy(LastName, name);
	}
}
void PagePhoneBook::setHomePhone(char* phone) {
	if (HomePhone != nullptr)
	{
		delete[] HomePhone;
		HomePhone = nullptr;
	}
	if (phone != nullptr)
	{
		int Size = strlen(phone) + 1;
		HomePhone = new char[Size];
		strcpy(HomePhone, phone);
	}
}
void PagePhoneBook::setWorkPhone(char* phone) {
	if (WorkPhone != nullptr)
	{
		delete[] WorkPhone;
		WorkPhone = nullptr;
	}
	if (phone != nullptr)
	{
		int Size = strlen(phone) + 1;
		WorkPhone = new char[Size];
		strcpy(WorkPhone, phone);
	}
}
void PagePhoneBook::setCellPhone(char* phone) {
	if (CellPhone != nullptr)
	{
		delete[] CellPhone;
		CellPhone = nullptr;
	}
	if (phone != nullptr)
	{
		int Size = strlen(phone) + 1;
		CellPhone = new char[Size];
		strcpy(CellPhone, phone);
	}
}
void PagePhoneBook::setEmail(char* email) {
	if (Email != nullptr)
	{
		delete[] Email;
		Email = nullptr;
	}
	if (email != nullptr)
	{
		int Size = strlen(email) + 1;
		Email = new char[Size];
		strcpy(Email, email);
	}
}
void PagePhoneBook::setBirth(unsigned short day, unsigned short mounth, unsigned short year) {
	if (day > 0 && day <= 31)
		BirthDay = day;
	else
		BirthDay = 0;
	if (mounth > 0 && mounth <=  12)
		BirthMounth = mounth;
	else
		BirthMounth = 0;
	if (year > 0)
		BirthYear = year;
	else
		BirthYear = 0;
}
void PagePhoneBook::setAddress(char* address) {
	if (Address != nullptr)
	{
		delete[] Address;
		Address = nullptr;
	}
	if (address != nullptr)
	{
		int Size = strlen(address) + 1;
		Address = new char[Size];
		strcpy(Address, address);
	}
}
void PagePhoneBook::setComment(char* comment) {
	if (Comment != nullptr)
	{
		delete[] Comment;
		Comment = nullptr;
	}
	if (comment != nullptr)
	{
		int Size = strlen(comment) + 1;
		Comment = new char[Size];
		strcpy(Comment, comment);
	}
}
#pragma warning(default:4996)

char* PagePhoneBook::getFirstName() const {
	return FirstName;
}


void PagePhoneBook::setAddInPage(bool add) {
	int Menu{};
	char name[100]{};
	unsigned short day{};
	unsigned short mounth{};
	unsigned short year{};
	std::cout << "Какие данные изменит:\n1) Имя \n2) Сотовый телефон \n";
	if (add == false)
		std::cout << "3) Фамилия \n4) Отчество \n5) Рабочий телефон \n6) Домашний телефон \n7) Электронная почта \n8) Дата рождения \n9) Адресс \n10) комментарий \n0) Закончить" << std::endl;
	do
	{
		std::cin >> Menu;
		switch (Menu)
		{
		case 1:
			std::cin >> name;
			setFirstName(name);
			break;
		case 2:
			std::cin >> name;
			setCellPhone(name);
			break;

			if (add == false)
			{
			case 3:
				std::cin >> name;
				setLastName(name);
				break;
			case 4:
				std::cin >> name;
				setMiddleName(name);
				break;
			case 5:
				std::cin >> name;
				setWorkPhone(name);
				break;
			case 6:
				std::cin >> name;
				setHomePhone(name);
				break;
			case 7:
				std::cin >> name;
				setEmail(name);
				break;
			case 8:
				std::cout << "День: ";
				std::cin >> day;
				std::cout << "Месяц: ";
				std::cin >> mounth;
				std::cout << "год: ";
				std::cin >> year;
				setBirth(day, mounth, year);
				break;
			case 9:
				std::cin.getline(name, 100);
				setAddress(name);
				break;
			case 10:
				std::cin >> name;
				setComment(name);
			}
		}
	} while (Menu!=0);
}

PagePhoneBook::PagePhoneBook() : FirstName{ nullptr }, LastName{ nullptr }, MiddleName{ nullptr }, CellPhone{ nullptr }, WorkPhone{ nullptr }, HomePhone{ nullptr }, Email{ nullptr }, BirthDay{ 0 }, BirthMounth{ 0 }, BirthYear{ 0 }, Address{ nullptr }, Comment{ nullptr } {
	std::cout << "Констуктор по умолчанию" << std::endl;
	Size++;
}

PagePhoneBook::PagePhoneBook(char* firstname, char* cellphone) 
	: PagePhoneBook() 
{
	setFirstName(firstname);
	setCellPhone(cellphone);
}

//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* cellphone) 
//	: PagePhoneBook(firstname, cellphone) {
//	setLastName(lastname);
//}
//
//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone) 
//	: PagePhoneBook(firstname, lastname, cellphone) {
//	setMiddleName(middlename);
//}
//
//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email) 
//	: PagePhoneBook(firstname, lastname, middlename, cellphone) {
//	setEmail(email);
//}
//
//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year) 
//	: PagePhoneBook(firstname, lastname, middlename, cellphone, email) {
//	setBirth(day, mounth, year);
//}
//
//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress) 
//	: PagePhoneBook(firstname, lastname, middlename, cellphone, email, day, mounth, year) {
//	setAddress(adress);
//}
//
//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress) 
//	: PagePhoneBook(firstname, lastname, middlename, cellphone, email, day, mounth, year, adress) {
//	setWorkPhone(workphone);
//}
//
//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress) 
//	: PagePhoneBook(firstname, lastname, middlename, cellphone, workphone, email, day, mounth, year, adress) {
//	setHomePhone(homephone);
//}
//
//PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress, char* comment) 
//	: PagePhoneBook(firstname, lastname, middlename, cellphone, workphone, homephone, email, day, mounth, year, adress) {
//	setComment(comment);
//}

/* нужно отдельно вынести из класса метод и сделать его функцией в методе.
Это касается метода добавления страницы в книгу и удаления (setPageAppEnd и setPageDell_i), 
и добавить в функцию перегрузку метода приравнивания или копирования */

PagePhoneBook::PagePhoneBook(const PagePhoneBook& Book) // ПРОВЕРЕН метод глубокого копирования
{
	setFirstName(Book.FirstName);
	setLastName(Book.LastName);
	setMiddleName(Book.MiddleName);
	setCellPhone(Book.CellPhone);
	setWorkPhone(Book.WorkPhone);
	setHomePhone(Book.HomePhone);
	setEmail(Book.Email);
	setBirth(Book.BirthDay, Book.BirthMounth, Book.BirthYear);
	setAddress(Book.Address);
	setComment(Book.Comment);
}
PagePhoneBook& PagePhoneBook::operator=(const PagePhoneBook& Book) // ПРОВЕРЕН оператор перегрузки приравнивания
{
	if (this == &Book)
		return *this;
	//*this = PagePhoneBook(Book); // проверить работает или нет
	setFirstName(Book.FirstName);
	setLastName(Book.LastName);
	setMiddleName(Book.MiddleName);
	setCellPhone(Book.CellPhone);
	setWorkPhone(Book.WorkPhone);
	setHomePhone(Book.HomePhone);
	setEmail(Book.Email);
	setBirth(Book.BirthDay, Book.BirthMounth, Book.BirthYear);
	setAddress(Book.Address);
	setComment(Book.Comment);
	return *this;
}

PagePhoneBook* setPageAppEnd(PagePhoneBook* Book, const PagePhoneBook* Page) {
	int size = Book->getSize();
	PagePhoneBook* newbook = new PagePhoneBook[size]{};
	for (int i = 0; i < size; i++)
	{
		if (Book != nullptr && i < size - 1)
			newbook[i] = Book[i];
		else
			newbook[i] = Page[0];
	}
	delete[] Book;
	delete Page;
	return newbook;
}

PagePhoneBook* setPageDell_i(PagePhoneBook* Book, int i) {
	int size = Book->getSize() - 1;
	PagePhoneBook* newbook = new PagePhoneBook[size]{};
	for (int j = 0, k = 0; j < size; ++j, ++k)
	{
		if (j == i)
			newbook[j] = Book[++k];
		else
			newbook[j] = Book[k];
	}
	delete[] Book;
	return newbook;
}

/* Старая Версия - позже удалить
PagePhoneBook* PagePhoneBook::setPageAppEnd(PagePhoneBook*& Book, const PagePhoneBook* Page) {
	int size = Size;
	PagePhoneBook* newbook = new PagePhoneBook[size]{};
	for (int i = 0; i < size; i++)
	{
		if (Book != nullptr && i < size-1)
			newbook[i] = Book[i];
		else
			newbook[i] = Page[0];
	}
	if (Book != nullptr)
		delete[] Book;
	return newbook;
}

PagePhoneBook* PagePhoneBook::setPageDell_i(PagePhoneBook*& Book, int i) {
	int size = Size - 1;
	PagePhoneBook* newbook = new PagePhoneBook[size]{};
	for (int j = 0; j < size; j++)
	{
		if (j < i)
			newbook[j] = Book[j];
		else
			newbook[j] = Book[j+1];
	}
		delete[] Book;
	return newbook;
}*/

void PagePhoneBook::printPageBook() {
	std::cout << "Имя: " << FirstName << std::endl;
	if (MiddleName!=nullptr)
		std::cout << "Отчетство: " << MiddleName << std::endl;
	if (LastName != nullptr)
		std::cout << "Фамилия: " << LastName << std::endl;
	std::cout << "Сотовый телефон: " << CellPhone << std::endl;
	if (WorkPhone != nullptr)
		std::cout << "Рабочий телефон: " << WorkPhone << std::endl;
	if (HomePhone != nullptr)
		std::cout << "Домашний телефон: " << HomePhone << std::endl;
	if (Email != nullptr)
		std::cout << "Электронная почта: " << Email << std::endl;
	if (BirthDay != 0)
		std::cout << "Дата рождения: " << BirthDay << "." << BirthMounth << "." << BirthYear << std::endl;
	if (Address != nullptr)
		std::cout << "Адресс: " << Address << std::endl;
	if (Comment != nullptr)
		std::cout << "Комментарий: " << Comment << std::endl;
}

void sortNameBook(PagePhoneBook* Book) {
	int size = Book->getSize() - 1;
	PagePhoneBook Swap{};
	bool x{0};
	if (size == 1)
		return;
	do
	{
		x = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (strcmp(Book[i].getFirstName(), Book[i + 1].getFirstName()) < 0)
			{
				//std::swap(Book[i], Book[i + 1]);
				Swap = Book[i];
				Book[i] = Book[i + 1];
				Book[i + 1] = Swap;
				x = 1;
			}
		}
	} while (x == false);
}

PagePhoneBook::~PagePhoneBook() {
	delete[] FirstName;
	delete[] MiddleName;
	delete[] LastName;
	delete[] HomePhone;
	delete[] WorkPhone;
	delete[] CellPhone;
	delete[] Email;
	delete[] Address;
	delete[] Comment;
	Size--;
	std::cout << "Маркер деструктора" << std::endl; // Временно для проверки
	std::cout << "Маркер static Size: " << Size << std::endl; // Временно для проверки
	// позже дописать запись телефонной книги в отдельный файл
}