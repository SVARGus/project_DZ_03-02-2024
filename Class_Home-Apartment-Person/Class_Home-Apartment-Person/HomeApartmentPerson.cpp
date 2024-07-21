#include "HomeApartmentPerson.h"

// ������ �������

Person::Person(std::string fio, int age) : fio{ fio }, age {age} {}

//std::string Person::getFIO () const
//{
//	return fio;
//}
//int Person::getAge() const
//{
//	return age;
//}
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

void Apartment::freeRegistrPerson(Person* person) // ��������� � �������� // ��
{
	// ����� ������������ �������� ���� ����������� � ������ ���� � ��� �������� ������ ����� ��� ������
	if (person->age != 0 || person->fio != "")
	{
		for (int i = 0; i < this->sizePerson; i++)
		{
			if (this->person[i].age == 0)
			{
				this->person[i] = *person; // ��������� �� ��������? (��������� ��� �����������)
				person->~Person(); //
				return;
			}
		}
		std::cout << "� ������ �������� ���������� ��������� " << person->fio << ", �������� ������ ��������" << std::endl;
	}
	else
		std::cout << " ��� �������� - ������� ��� ����������� �����" << std::endl; // ����� ������ ��� ���������� ��� ���������������
}
void Apartment::discharPersonInHome(Person& freeperson)
{
	if (freeperson.age != 0 && freeperson.fio != "")
	{
		this->print();
		int i{};
		std::cout << "����� ������� ��������? ������� ���������� ����� �� ������ ���� (���� ���������� ������ - �������� ����� ������� �� 1 �� " << sizePerson << "): " << std::endl;
		std::cin >> i;
		while (i < 1 || i > sizePerson)
		{
			std::cout << "�� ����� ������ ���������� �����, ��������� ����: ";
			std::cin >> i;
		}
		if (freeperson.age == 0 || freeperson.fio == "")
		{
			std::cout << "���������� ������" << std::endl;
			return;
		}
		freeperson = person[i-1];
		person[i].~Person();
	}
	else
	{
		std::cout << "������!!! � ��� ��� ����� �������� ������ ��������, �������� ������ ����� ������� ��� �������" << std::endl;
	}
}
void Apartment::discharPersonInHome()
{
	this->print();
	int i{};
	std::cout << "����� ������� ��������? ������� ���������� ����� �� ������ ���� (���� ���������� ������ - �������� ����� ������� �� 1 �� " << sizePerson << "): " << std::endl;
	std::cin >> i;
	if (i < 1 || i > sizePerson)
		return;
	if (person[i].age != 0 || person[i].fio != "")
	{
		std::cout << "������� " << person[i].age << " �������� �� ��������" << std::endl;
		person[i].~Person();
	}
}


// ������ ����

Apartment& Home::operator[](int appartNumber)
{
	--appartNumber;
	return apartment[appartNumber / numbeOfApartmenOnFloor][appartNumber % numbeOfApartmenOnFloor];
	// ���� �������� ���������� ���� �������� �� ������� ��� ����� �������� ������� �� ����� (���� ����� �������� �������� �� �����, ��� ��� ��������� � ���� ���� �� ������� � ���������� ������� �� ����� ����������)
}

Home::Home(std::string street, int numberHous, int floor, int numbeOfApartmenOnFloor, int* numRoomApartFloor) : street{ street }, numberHous { numberHous }, floor{ floor }, numbeOfApartmenOnFloor{ numbeOfApartmenOnFloor }
{
	Apartment::count = 1; // �������� ���������� ������� � ���� � ��� �������� ������ �������� ���������� ��� ����� �������� c ��������� ���������� � 1
	apartment = new Apartment*[this->floor];
	for (int i = 0; i < this->floor; ++i)
	{
		apartment[i] = new Apartment[this->numbeOfApartmenOnFloor];
		for (int j = 0; j < numbeOfApartmenOnFloor; ++j)
		{
			apartment[i][j] = Apartment(numRoomApartFloor[j]);
		}
	}
	this->apartmentInHous = floor * numbeOfApartmenOnFloor;
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

//void Home::freeRegistrPersonInHome(Person& person, const int floor, const int numbeOfApartmenOnFloor) // �� ���������� ��������� ��������� [] ��� �������� ���������� �������� � ����� ����� � �������� �� �����
//{
//	if (floor < 1 || floor > this->floor)
//	{
//		std::cout << "�� ������� �� ������ ����, � ���� ����� ������: " << this->floor << std::endl;
//		return;
//	}
//	if (numbeOfApartmenOnFloor < 1 || numbeOfApartmenOnFloor > this->numbeOfApartmenOnFloor)
//	{
//		std::cout << "�� ������� �� ������ �������� �� �����, �� ����� ����� �������: " << this->numbeOfApartmenOnFloor << std::endl;
//		return;
//	}
//	this->apartment[floor-1][numbeOfApartmenOnFloor-1].freeRegistrPerson(person);
//}
void Home::freeRegistrPersonInHome(Person* person, const int appartNumber) // ����������� ����������� ������ � �������������� ���������� [] �� ������ �������� � ����
{
	(*this)[appartNumber].freeRegistrPerson(person);
}

//void Home::discharPersonInHome(Person& freeperson, const int floor, const int numbeOfApartmenOnFloor) // �� ���������� ��������� ��������� [] ��� �������� ���������� �������� � ����� ����� � �������� �� �����
//{
//	if (floor < 1 || floor > this->floor)
//	{
//		std::cout << "�� ������� �� ������ ����, � ���� ����� ������: " << this->floor << std::endl;
//		return;
//	}
//	if (numbeOfApartmenOnFloor < 1 || numbeOfApartmenOnFloor > this->numbeOfApartmenOnFloor)
//	{
//		std::cout << "�� ������� �� ������ �������� �� �����, �� ����� ����� �������: " << this->numbeOfApartmenOnFloor << std::endl;
//		return;
//	}
//	this->apartment[floor - 1][numbeOfApartmenOnFloor - 1].discharPersonInHome(freeperson);
//}
void Home::discharPersonInHome(Person& freeperson, const int appartNumber) // ����������� ����������� ������ � �������������� ���������� [] �� ������ �������� � ����
{
	(*this)[appartNumber].discharPersonInHome(freeperson);
}

void Home::discharPersonInHome(const int appartNumber)
{
	(*this)[appartNumber].discharPersonInHome();
}
