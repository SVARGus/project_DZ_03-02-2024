#pragma once
#include <iostream>
//#include <stralign.h>
#include<cstring>

class PagePhoneBook
{
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

	~PagePhoneBook(); // деструктор
};

