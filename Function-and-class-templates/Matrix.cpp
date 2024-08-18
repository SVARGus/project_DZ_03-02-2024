#include "Matrix.h"

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

