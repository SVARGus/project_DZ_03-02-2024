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
	std::string getFIO() const; // OK
	int getAge() const; // OK
	void print() const; // OK
	friend std::istream& operator>> (std::istream& input, Person& person); // OK
	Person& operator= (const Person& person);

	//Person operator= (char* fio, int age);
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
	void freeRegistrPerson(Person& person);
	//Person& operator[] (int appartNumber); // ���� �������� ��� ����������� ������ �������� ����� � ���������� ������� ���������  ����� ��������
	
};

class Home
{
	std::string street{}; // �����
	int numberHous{}; // ����� ����
	int floor{}; // ���������� ������
	int numbeOfApartmenOnFloor{}; // ���������� ������� �� �����
	Apartment** apartment{};

public:
	Home(std::string street, int numberHous, int floor, int numbeOfApartmenOnFloor, int* numRoomApartFloor); // ����������� �������� ����, ����� �������� � ������������� ������� ��������, �������� ������� ������� = 1
};