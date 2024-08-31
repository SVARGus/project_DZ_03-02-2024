#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::swap;

/*
Тема: Шаблоны классов (Будет реализован отдельный класс)

Задание.
Создайте шаблонный класс матрица. Необходимо реали-зовать динамическое выделение памяти (реализовано), очистку памяти (реализовано), заполнение матрицы с клавиатуры,
заполнение случайны-ми значениями, отображение матрицы, арифметические операции с помощью перегруженных операторов (+, –, *, /), поиск максимального и минимального элемента
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
