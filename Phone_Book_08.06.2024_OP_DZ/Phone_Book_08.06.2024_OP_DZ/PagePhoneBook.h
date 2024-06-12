#pragma once
#include <iostream>
//#include <stralign.h>
#include<cstring>

class PagePhoneBook
{
	char* FirstName; // ���
	char* MiddleName; // ��������
	char* LastName; // �������
	char* HomePhone; // �������� �������
	char* WorkPhone; // ������� �������
	char* CellPhone; // ������� �������
	char* Email;
	unsigned short BirthDay : 6; // ���� ��������
	unsigned short BirthMounth : 5; // ����� ��������
	unsigned short BirthYear : 12; // ��� ��������
	char* Address; // ����� ��������
	char* Comment; // ����������� � ��������

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

	PagePhoneBook(); // ����������� �� ���������
	PagePhoneBook(char* firstname, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress);
	PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress, char* comment);

	~PagePhoneBook(); // ����������
};

