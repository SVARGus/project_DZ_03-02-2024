#pragma once

/*
�������� ������� ��� �������
*/

/*
����: ����������� �������-����, explicit �����������.
�������.
����������� ����� Reservoir(������). ����� ������ ����������� ����� ���� ���������.
����� ������ ���������: ����������� �� ���������, ����������� � �����������,
��� ������������� ����������� ���������� � ����������� �����������.

�������� ������ ���:
1. ����������� ���������������� ������ (������*�����*������������ �������);
2. ����������� ������� ������ �����������;
3. ����� ��� �������� ��������� �� ������� � ������ ���� (����-����; �������-����);
4. ��� ��������� ������� ������ ����������� �������� ������ ����;
5. ��� ����������� ��������; � ����� � �������������� ���������� String (� ��� ��� ���������� ����� �����������), 
   � ��������� ���������� �� ���������� ������������ ������ � �� ��������� ��������� ���������=, �� ����� ��������� ����������� �� ��������� �������������.
6. ��������� ������ �� ���������� ������������ (������ set � get).

�������� ��������� ��� ������ � �������.
����������� ������������ ������ �������� ������ � ������������ ����������, �������� �������� �� �������.
����������� ����������� ������ ���������� �� �������� ������� � ��������� ����, �������� ����.
����������� explicit ����������� � ����������� ������������ (��������, ��� ����������� ������ � ������ � �.�.).

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Reservoir
{
	string nameReservoir{}; // ��� �������
	int width{}; // ������ � ������
	int length{}; // ����� � ������
	int maxDepth{}; // ������������ ������� � ������
	int typeReservoir{}; // ��� �������
	enum TYPETESERVOIR{PUDDLE = 1, POND, LAKE, SEA, OCEAN};


public:
	Reservoir() {};
	Reservoir(string nameReservoir, int width, int length, int maxDepth, int typeReservoir = 0) : // ���� �������� ������ � ������������� ��������, �� ��� ��� ����� - �� ������� ���������� ��� typeReservoir
		nameReservoir{ nameReservoir }, width{ width }, length{ length }, maxDepth{ maxDepth }, typeReservoir{ typeReservoir } {if (typeReservoir == 0){this->definitTypeReservoir();}};
	Reservoir(const Reservoir& reservoir) :
		nameReservoir{ reservoir.nameReservoir }, width{ reservoir.width }, length{ reservoir.length }, maxDepth{ reservoir.maxDepth }, typeReservoir{ reservoir.typeReservoir } {};
	Reservoir& operator= (const Reservoir& reservoir);
	~Reservoir() {};

	// �������� ������� ����� ������
	void setNameReservoir(string nameReservoir) { this->nameReservoir = nameReservoir; }
	void setWidth(int width) { this->width = width; }
	void setLength(int length) { this->length = length; }
	void setMaxDepth(int maxDepth) { this->maxDepth = maxDepth; }
	void setTypeReservoit(int typeReservoir) { this->typeReservoir = typeReservoir; }

	string getNameReservoir() const { return nameReservoir; }
	int getWidth() const { return width; }
	int getLength() const { return length; }
	int getMaxDepth() const { return maxDepth; }
	int getTypeReservoir() const { return typeReservoir; }

	// �������� ��������� ������ ������� � ������ � ������ ��� ����� ������� ����������� ���������� ��� ������ ������
	int areaReservoir() const { return length * width; }; // ������� ������ � ��2
	int volumeReservoir() const { return areaReservoir() * (maxDepth / 1000.0); }; // ������ ������� � ��3

	void definitTypeReservoir(); // ����������� ���� �������
	bool compareTypeReservoir(Reservoir reservoir) const { return this->typeReservoir == reservoir.typeReservoir; }; // ��������� ����� �������
	bool compareAreaReservoir(Reservoir reservoir) const { return this->areaReservoir() > reservoir.areaReservoir(); }; // ��������� ������� �������� ������ ����?????


	void printVolumeReservoir() const; // ������ ������ �������
	void printAreaReservoir() const; // ������ ������� ������
	void printTypeReservoir() const; // ����� �� ������ ���� �������
	void printReservoir() const; // ����� �� ������

	

};

