#pragma once
#include <iostream>


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
	int fiosize{};
	std::string fio{};
	
	int age{};
	friend class Home;
	friend class Apartment;

public:

	Person() {};
	Person(std::string fio, int age);
	std::string getFIO() const;
	int getAge() const;
	//Person operator= (char* fio, int age);
};

class Apartment
{
	static int count;
	int appartNumber;/*����� �������� ����� ���������� ��� ������ �������� - ���� �������� ��� ����������� ������������ ����������� ������ ������ ��������
	�������� ����������� �� ����������� ���������� ������� ���������� ��� ������������� ����*/
	int room{}; // ���������� ������
	Person* person{};

	friend class Home;
	Apartment();

public:
	explicit Apartment(int room);
	//Apartment[](int numbeOfApartmenOnFloor, int* numRoomApartFloor);
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