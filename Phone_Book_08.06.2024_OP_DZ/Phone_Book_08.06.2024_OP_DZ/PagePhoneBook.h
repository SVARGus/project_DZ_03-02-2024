#pragma once
#include <iostream>

class PagePhoneBook
{
	char* FirstName; // ���
	char* MiddleName; // ��������
	char* LastName; // �������
	char* HomePhone; // �������� �������
	char* WorkPhone; // ������� �������
	char* CellPhone; // ������� �������
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
	void setBirth(unsigned short&, unsigned short&, unsigned short&);
	void setAddress(char*);
	void setComment(char*);
};

