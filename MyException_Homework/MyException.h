#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;
/*
Задание 2.

1) Деление на ноль
2) Ввод числа вместо буквы
3) Выход за границы массива(матрицы).Матрица 2х2, мы, к примеру, перемножаем элементы(3; 3)
4) Неверный тип входных параметров(вместо Int пишем double)
*/

class MyEsception : public exception
{
	string message;
	int dateState{-1};
public:
	MyEsception(const char* message, int dateState) : message(message), dateState(dateState) {} // на случай если нужно передать код ошибки который будет подробно описан в документации на класс (библиотеку, программу...)
	explicit MyEsception(const char* message) :message(message) {}
	explicit MyEsception(int dateState) : dateState(dateState) {}
	int getDateState() { return dateState; }
	virtual const char* what() const throw() { return message.c_str(); }
};

