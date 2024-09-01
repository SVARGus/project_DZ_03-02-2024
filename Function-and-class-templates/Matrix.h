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
	template<class T>
	/*friend Matrix<T>& operator+ (const Matrix<T>& array1, const Matrix<T>& array2);*/
	/*template<class T>
	friend Matrix<T>& operator= (Matrix<T>& array1, const Matrix<T>& array2);*/

public:
	Matrix(int size);
	~Matrix();

	int getSize() { return size; };
	void printMatrix() const;
	void genMatrix(); 
	void enterMatrix();
	T& operator () (const int row, const int col);
	const T& operator() (const int row, const int col) const;
	/*Matrix<T>& operator= (const Matrix<T>& array1);
	Matrix<T>& operator= (const Matrix<T>&& array1);*/
	
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
void Matrix<T>::genMatrix() {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = rand() % 11 + (rand() % 11 * 0.1);
		}
	}
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
const T& Matrix<T>::operator() (const int row, const int col) const {
	return array[row][col];
}
//template<class T>
//Matrix<T>& Matrix<T>::operator= (const Matrix<T>& array1) {
//	if (this == &array1)
//	{
//		return *this;
//	}
//	if (size != array1.size)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			delete[] array[i];
//		}
//		delete[] array;
//		size = array1.size;
//		array = new  T * [size];
//		for (int i = 0; i < size; ++i)
//		{
//			array[i] = new T[size];
//			for (int j = 0; j < size; j++)
//			{
//				array[i][j] = array1.array[i][j];
//			}
//		}
//	}
//	else if (this->size == array1.size)
//	{
//		for (size_t i = 0; i < array1.size; i++)
//		{
//			for (int j = 0; j < array1.size; j++)
//			{
//				array[i][j] = array1.array[i][j];
//			}
//		}
//	}
//	return *this;
//}
//template<class T>
//Matrix<T>& Matrix<T>::operator= (const Matrix<T>&& array1) {
//	if (this == &array1)
//	{
//		return *this;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		delete[] array[i];
//	}
//	delete[] array;
//	size = array1.size;
//	array = array1.array;
//	array1.size = 0;
//	array1.array = nullptr;
//	return *this;
//}
//
//template<class T>
//Matrix<T>& operator+ (const Matrix<T>& array1, const Matrix<T>& array2){
//	int newSize = (array1.size > array2.size) ? array1.size : array2.size;
//	Matrix<T> result(newSize);
//	if (array1.size == array2.size)
//	{
//		for (int i = 0; i < newSize; i++)
//		{
//			for (int j = 0; j < newSize; j++)
//				result.array[i][j] = array1.array[i][j] + array2.array[i][j];
//		}
//	}
//	else if (array1.size < array2.size)
//	{
//		for (int i = 0; i < newSize; i++)
//		{
//			if (i < array1.size)
//			{
//				for (int j = 0; j < newSize; j++)
//				{
//					if (j < array1.size)
//					{
//						result.array[i][j] = array1.array[i][j] + array2.array[i][j];
//					}
//					result.array[i][j] = array2.array[i][j];
//				}
//			}
//			for (int j = 0; j < newSize; j++)
//			{
//				result.array[i][j] = array2.array[i][j];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < array2.size; i++)
//		{
//			for (int j = 0; j < array2.size; j++)
//				result(i, j) = array1(i, j) + array2(i, j);
//		}
//		for (int i = array2.size; i < array1.size; i++)
//		{
//			for (int j = array2.size; j < array1.size; j++)
//				result(i, j) = array2(i, j);
//		}
//	}
//	return result;
//}
