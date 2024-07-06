#include "HomeApartmentPerson.h"

// ������ �������

Person::Person(std::string fio, int age) : fio{ fio }, age {age} {}

std::string Person::getFIO () const
{
	return fio;
}
int Person::getAge() const
{
	return age;
}
//Person Person::operator= (char* fio, signed int age) // ���������� �� ������������� ������ � ������
//{
//	fiosize = strlen(fio);
//	this->fio = new char[fiosize + 1];
//	for (int i = 0; i <= fiosize; i++)
//		this->fio[i] = fio[i];
//	this->age = age;
//}


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

Home::Home(std::string street, int numberHous, int floor, int numbeOfApartmenOnFloor, int* numRoomApartFloor) : street{ street }, numberHous { numberHous }, floor{ floor }, numbeOfApartmenOnFloor{ numbeOfApartmenOnFloor }
{
	Apartment::count = 1; // �������� ���������� ������� � ���� � ��� �������� ������ �������� ���������� ��� ����� �������� ������� � 1
	apartment = new Apartment*[this->floor];
	for (int i = 0; i < this->floor; ++i)
	{
		apartment[i] = new Apartment[this->numbeOfApartmenOnFloor];
		for (int j = 0; j < numbeOfApartmenOnFloor; ++j)
		{
			apartment[i][j] = Apartment(numRoomApartFloor[j]);
		}
	}
}
