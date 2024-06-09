#pragma once
#include <iostream>

class PagePhoneBook
{
	char* FirstName; // Имя
	char* MiddleName; // Отчество
	char* LastName; // Фамилия
	char* HomePhone; // Домашний телефон
	char* WorkPhone; // Рабочий телефон
	char* CellPhone; // Сотовый телефон
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
	void setBirth(unsigned short&, unsigned short&, unsigned short&);
	void setAddress(char*);
	void setComment(char*);
};

