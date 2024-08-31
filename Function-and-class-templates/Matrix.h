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
Создайте шаблонный класс матрица. Необходимо реали-зовать динамическое выделение памяти (реализовано), очистку памяти (реализовано), 
заполнение матрицы с клавиатуры (реализовано + частично через оператор перегрузки),
заполнение случайны-ми значениями, отображение матрицы (реализовано, частичный вывод реализован через перегрузку оператора ()), 
арифметические операции с помощью перегруженных операторов (+, –, *, /), поиск максимального и минимального элемента
*/

template<class T>
class Matrix
{
	int size{};
	T** array{ nullptr };

public:
	Matrix(int size);
	~Matrix();

	void printMatrix() const;
	T genMatrix(); // Дописать единый для целых и дробных чисел, и отдельный для char
	void enterMatrix();
	T& operator () (const int row, const int col);
	const T& operator () (const int row, const int col) const;
};



template<class T>
Matrix<T>::Matrix(int size) {
	this->size = size;
	array = new  T * [this->size];
	for (int i = 0; i < size; ++i)
	{
		array[i] = new T[this->size]{};
	}
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < size; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

template<class T>
void Matrix<T>::printMatrix() const {
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}
}
template<class T>
T Matrix<T>::genMatrix() {

}
template<class T>
void Matrix<T>::enterMatrix() {
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cin >> array[i][j];
	}
}
template<class T>
T& Matrix<T>::operator () (const int row, const int col) {
	return array[row][col];
}
template<class T>
const T& Matrix<T>::operator () (const int row, const int col) const {
	return array[row][col];
}