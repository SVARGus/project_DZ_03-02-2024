#pragma once
#include <iostream>
//#include <stralign.h>
#include<cstring>

class PagePhoneBook
{
	static int Size; // количество страниц в телефонной книге
	char* FirstName; // Имя
	char* MiddleName; // Отчество
	char* LastName; // Фамилия
	char* HomePhone; // Домашний телефон
	char* WorkPhone; // Рабочий телефон
	char* CellPhone; // Сотовый телефон
	char* Email;
	unsigned short BirthDay; // День рождения
	unsigned short BirthMounth; // Месяц рождения
	unsigned short BirthYear; // Год рождения
	char* Address; // Адрес контакта
	char* Comment; // Комментарии к контакту

public:
	
	inline void setFirstName(char*);
	inline void setMiddleName(char*);
	inline void setLastName(char*);
	inline void setHomePhone(char*);
	inline void setWorkPhone(char*);
	inline void setCellPhone(char*);
	inline void setEmail(char*);
	inline void setBirth(unsigned short, unsigned short, unsigned short);
	inline void setAddress(char*);
	inline void setComment(char*);
	inline char* getFirstName() const;
	inline void setAddInPage(bool add = 0);

	static int getSize() {
		return Size; 
	}

	PagePhoneBook(); // конструктор по умолчанию
	PagePhoneBook(char* firstname, char* cellphone);
	/*PagePhoneBook(char* firstname, char* lastname, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress, char* comment);*/

	PagePhoneBook(const PagePhoneBook& Book); // Оператор глубокого копирования
	PagePhoneBook& operator=(const PagePhoneBook& Book); // Оператор перегрузки приравнивания

	//PagePhoneBook setPageAppEnd(PagePhoneBook* Book, const PagePhoneBook* Page); // Метод добавляющий в телефонную книгу новый контакт
	//PagePhoneBook* setPageDell_i(PagePhoneBook*& Book, int i); // Метод удаления определенной страницы в телефонной книге
	
	inline void printPageBook();

	//void sortNameBook(PagePhoneBook* Book);

	~PagePhoneBook(); // деструктор
};

PagePhoneBook *setPageAppEnd(PagePhoneBook* Book, const PagePhoneBook* Page);
PagePhoneBook* setPageDell_i(PagePhoneBook* Book, int i);
void sortNameBook(PagePhoneBook* Book);


