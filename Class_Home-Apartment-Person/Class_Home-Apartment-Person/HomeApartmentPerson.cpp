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
void Person::print() const
{
	std::cout << "��� " << fio << ", ������� - " << age << std::endl;
}
std::istream& operator>> (std::istream& input, Person& person)
{
	std::getline(std::cin, person.fio);
	input >> person.age;
	std::cin.ignore();
	return input;
}
Person& Person::operator= (const Person& person)
{
	this->fio = person.fio;
	this->age = person.age;
	return *this;
}


// ������ ��������

Apartment::Apartment(int room) : appartNumber{count}, room {room}
{
	switch (room)
	{
	case 1:
		sizePerson = 3;
		person = new Person[sizePerson];
		break;
	case 2:
		sizePerson = 4;
		person = new Person[sizePerson];
		break;
	case 3:
		sizePerson = 6;
		person = new Person[sizePerson];
		break;
	default: // ���� ��������� ���� �� ������ ���� ������������ ������ ����� 3 ������ � ��������!
		break;
	}
	++count;
}
void Apartment::print() const
{
	std::cout << "����� ��������: " << appartNumber << ". ���������� ������: " << room << std::endl;
	for (int i = 0; i < sizePerson; i++)
	{
		// ��������� ������� ������ ������ ����������� �������
		person[i].print();
	}
}

void Apartment::freeRegistrPerson(Person& person)
{
	// ����� ������������ �������� ���� ����������� � ������ ���� � ��� �������� ������ ����� ��� ������
	for (int i = 0; i < this->sizePerson; i++)
	{
		if (this->person[i].age == 0)
		{
			this->person[i] = person; // ��������� �� ��������? (��������� ��� �����������)
			return;
		}
	}
	std::cout << "� ������ �������� ���������� ��������� " << person.fio << ", �������� ������ ��������" << std::endl;
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
			apartment[i][j] = Apartment(numRoomApartFloor[j]); // ������ �������� ������������� �������?
		}
	}
}

void Home::print() const
{
	std::cout << street << ", " << numberHous << std::endl;
	std::cout << "���������� ������: " << floor << std::endl;
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < numbeOfApartmenOnFloor; j++)
		{
			apartment[i][j].print();
			std::cout << std::endl;
		}
	}
}
