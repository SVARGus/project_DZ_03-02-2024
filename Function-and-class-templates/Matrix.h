#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::swap;

/*
����: ������� ������� (����� ���������� ��������� �����)

�������.
�������� ��������� ����� �������. ���������� �����-������ ������������ ��������� ������ (�����������), ������� ������ (�����������), ���������� ������� � ����������,
���������� ��������-�� ����������, ����������� �������, �������������� �������� � ������� ������������� ���������� (+, �, *, /), ����� ������������� � ������������ ��������
*/

template<class T>
class Matrix
{
	int size{};
	T** array{ nullptr };

public:
	Matrix(int size) : size{ size } {};
	~Matrix();

	void createDynamicMatrix(T**& array, int size);

};
