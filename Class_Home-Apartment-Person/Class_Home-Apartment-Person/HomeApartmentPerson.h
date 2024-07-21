#pragma once
#include <iostream>
#include <string>


/*
����: ��������� this. ��������� �����������. �����-������ �����������.

�������.

�������� ���������, ����������� ��������������� ���. ���������� ����� ������ ��������, ����������, ���� . 
����� ���������� �������� ������������ ������ �������� ������ �������� . ����� ���� �������� ������ �������� ������ ���������� .

������ �� ������� �������� ����������-����� � ����-���-�����, ������� ���������� ��� ���������� ������� ������. 
�������� ���� ��������, ��� ������ ��� ����-����� �������� ���������� �����������. ��������, ��� ��� � ������ �������� . 
�� ��������� ���������� ������ ���������� �������������� (����������� ����������� ����������), �������������. � main �������������� ��-���� ����������� ������ �������.
*/

/*
��� ����� ����� ������ ��� �� 3 ������, 5 ������� �� ������ ����� (2 �������, 2 ������ � 1 ������). 

����������� ����������� ����������� �� ���������� ������ � ��������
� ������� ����� �������� �� 2 �������� �� 18 ��� � ���� ������� �� 20 ���.
� ������ ����� ���� �� 2 �������� �� 18 ��� � 2 ������� �� 20 ���.
� ������ ����� ���� �� 3 �������� � �� 4 �����, �� ������� 6 ������� � �����.
*/

class Person
{
	std::string fio{};
	
	int age{};
	friend class Home;
	friend class Apartment;
	Person() {};

public:

	Person(std::string fio, int age); // OK
	~Person() { fio.clear(), age = 0; } // OK
	std::string getFIO() const { return fio; }; // OK
	int getAge() const {return age;}; // OK
	void setFIO(std::string fio) { this->fio = fio; }
	void setAge(int age) { this->age = age; }
	void print() const; // OK
	friend std::istream& operator>> (std::istream& input, Person& person); // OK
	Person& operator= (const Person& person);
	};

class Apartment
{
	static int count;
	int appartNumber{};/*����� �������� ����� ���������� ��� ������ �������� - ���� �������� ��� ����������� ������������ ����������� ������ ������ ��������
	�������� ����������� �� ����������� ���������� ������� ���������� ��� ������������� ����*/
	int room{}; // ���������� ������
	int sizePerson{}; // ������� ����� ���� ��������� � ��������
	Person* person{};

	friend class Home;
	Apartment() {};

public:
	explicit Apartment(int room);
	void print() const;
	void freeRegistrPerson(Person* person);
	void discharPersonInHome(Person& freeperson);
	void discharPersonInHome();
	//Person& operator[] (int appartNumber); // ���� �������� ��� ����������� ������ �������� ����� � ���������� ������� ���������  ����� ��������
	
};

class Home
{
	std::string street{}; // �����
	int numberHous{}; // ����� ����
	int floor{}; // ���������� ������
	int numbeOfApartmenOnFloor{}; // ���������� ������� �� �����
	int apartmentInHous{};
	Apartment** apartment{};

public:
	Apartment& operator[](int appartNumber);
	Home(std::string street, int numberHous, int floor, int numbeOfApartmenOnFloor, int* numRoomApartFloor); // ����������� �������� ����, ����� �������� � ������������� ������� ��������, �������� ������� ������� = 1
	int getApartmentInHous() const { return apartmentInHous; }
	void print() const; // ��������
	//void freeRegistrPersonInHome(Person& person, const int floor, const int numbeOfApartmenOnFloor); // ����� ���� � �������� �� ����� ����� �������� ����� ��������, ��� �������� �������� �� ����� �� ����� �������� � ��� � ������ ��������� ���� �� �������� � �������� ������� �� ���� ������
	void freeRegistrPersonInHome(Person* person, const int appartNumber);
	//void discharPersonInHome(Person& freeperson, const int floor, const int numbeOfApartmenOnFloor); // ����������� ������ ������� �� �������� ��� ����������� � ���������� ��������� � ������ �������� ����� ��� ������� ����
	void discharPersonInHome(Person& freeperson, const int appartNumber);
	void discharPersonInHome(const int appartNumber); // ������� �������� ���������� ��� ������� ������������ � ������
	
};