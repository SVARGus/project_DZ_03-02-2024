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
	unsigned short BirthDay : 6; // День рождения
	unsigned short BirthMounth : 5; // Месяц рождения
	unsigned short BirthYear : 12; // Год рождения
	char* Address; // Адрес контакта
	char* Comment; // Комментарии к контакту

public:
	
	void setFirstName(char*);
	void setMiddleName(char*);
	void setLastName(char*);
	void setHomePhone(char*);
	void setWorkPhone(char*);
	void setCellPhone(char*);
	void setEmail(char*);
	void setBirth(unsigned short&, unsigned short&, unsigned short&);
	void setAddress(char*);
	void setComment(char*);
	void setAddInPage(bool add = 0);

	static int getSize() {
		return Size; // как прописать метод в cpp а не в h?
	}

	PagePhoneBook(); // конструктор по умолчанию
	PagePhoneBook(char* firstname, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress, char* comment);

	PagePhoneBook* setPageAppEnd(PagePhoneBook*& Book, const PagePhoneBook* Page); // Метод добавляющий в телефонную книгу новый контакт
	PagePhoneBook* setPageDell_i(PagePhoneBook*& Book, int i); // Метод удаления определенной страницы в телефонной книге
	
	void printPageBook(); // Позже добавить номер страницы книги для вывода

	~PagePhoneBook(); // деструктор
};


