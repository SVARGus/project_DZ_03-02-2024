#include "HomeApartmentPerson.h"

// ������ �������

Person::Person(char* fio, int age)
{
	fiosize = strlen(fio);
	this->fio = new char[fiosize + 1];
	for (int i = 0; i <= fiosize; i++)
		this->fio[i] = fio[i];
	this->age = age;
}
char Person::getFIO()
{
	return fio;
}
int Person::getAge()
{
	return age;
}
Person Person::operator= (char* fio, signed int age) // ���������� �� ������������� ������ � ������
{
	fiosize = strlen(fio);
	this->fio = new char[fiosize + 1];
	for (int i = 0; i <= fiosize; i++)
		this->fio[i] = fio[i];
	this->age = age;
}


// ������ ��������

Apartment::Apartment(int room) : appartNumber{count}, room {room}
{
	switch (room)
	{
	case 1:
		person = new Person[3];
		break;
	case 2:
		person = new Person[4];
		break;
	case 3:
		person = new Person[6];
		break;
	default: // ���� ��������� ���� �� ������ ���� ������������ ������ ����� 3 ������ � ��������!
		break;
	}
	++count;
}

// ������ ����


