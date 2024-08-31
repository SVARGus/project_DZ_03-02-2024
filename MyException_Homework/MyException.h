#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;

class MyEsception : public exception
{
	int dateState;

public:
	MyEsception(const char* message, int dateState) :exception(message) { this->dateState = dateState; } // �� ������ ���� ����� �������� ��� ������ ������� ����� �������� ������ � ������������ �� ����� (����������, ���������...)
	MyEsception(const char* message) :exception(message) {}
	int getDateState() { return dateState; }
};

