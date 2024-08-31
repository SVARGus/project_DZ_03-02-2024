#include "Matrix.h"

/*
Тема: Шаблоны классов (Будет реализован отдельный класс)

Задание.
Создайте шаблонный класс матрица. Необходимо реали-зовать динамическое выделение памяти, очистку памяти, заполнение матрицы с клавиатуры,
заполнение случайны-ми значениями, отображение матрицы, арифметические операции с помощью перегруженных операторов (+, –, *, /), поиск максимального и минимального элемента
*/

template<class T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < size; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}
template<class T>
void Matrix<T>::createDynamicMatrix(T**& array, int size) {
	array = new * T[size];
	for (int i = 0; i < size; ++i)
	{
		array[i] = new T[size];
	}
}

