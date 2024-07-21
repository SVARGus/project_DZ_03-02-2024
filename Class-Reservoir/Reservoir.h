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
5. ��� ����������� ��������; � ����� � �������������� ���������� String (� ��� ��� ���������� ����� �����������), � ��������� ���������� �� ���������� ������������ ������ � �� ��������� ��������� ���������=
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
	string nameReservoir{};
	int width{};
	int length{};
	int maxDepth{};
	string typeReservoir{}; // ��� �������

public:
	void setNameReservoir(string nameReservoir) { this->nameReservoir = nameReservoir; }
	void setWidth(int width) { this->width = width; }
	void setLength(int length) { this->length = length; }
	void serMaxDepth(int maxDepth) { this->maxDepth = maxDepth; }

	string getNameReservoir() const { return nameReservoir; }
	int getWidth() const { return width; }
	int getLength() const { return length; }
	int gerMaxDepth() const { return maxDepth; }

	void volumeReservoir(); // ����� �������
	void areaReservoir(); // ������� ������
	void definitTypeReservoir(); // ����������� ���� �������
	void printReservoir(); // ����� �� ������


};

