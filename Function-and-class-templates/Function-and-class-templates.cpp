﻿/*
Тема: Шаблоны функций

Задание.
Реализуйте шаблонные функции для поиска максимума (OK), минимума (OK), сортировки массива (OK) (любым алгоритмом сортировки), 
двоичного поиска в массиве (OK), замены элемента массива на переданное значение (OK).
*/

/*
Тема: Шаблоны классов (Будет реализован отдельный класс) + в шаблонном класе добавил поимку исключений на основе своего класса MyException

Задание.
Создайте шаблонный класс матрица. Необходимо реали-зовать динамическое выделение памяти, очистку памяти, заполнение матрицы с клавиатуры, 
заполнение случайны-ми значениями, отображение матрицы, арифметические операции с помощью перегруженных операторов (+, –, *, /), поиск максимального и минимального элемента
*/

#include <iostream>
#include "Matrix.h"
#include "MyException.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::swap;

template<typename T>
void bubbleSort(T* array, int size); // OK
template<typename T>
void printArray(T* array, int size); // OK
template<typename T>
void searchInArray(T* array, int size, T searchNum); // OK
template<typename T>
T searchMax(T* array, int size); // OK
template<typename T>
T searchMin(T* array, int size); // OK
template<typename T>
int binarySearch(T* array, int size, T searchNum); // OK
template<typename T>
void replaceValue(T* array, int size, int i, T value); // OK


template<typename T>
void bubbleSort(T* array, int size)
{
    if (size <= 1) return;
    bool flag{};
    for (int i = 0; i < size-1; ++i)
    {
        flag = false;
        for (int j = 0; j < size-1; ++j)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j], array[j + 1]);
                flag = true;
            }
        }
        if (flag)
            flag = false;
        else
            return;
    }
}
template<typename T>
void printArray(T* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
template<typename T>
void searchInArray(T* array, int size, T searchNum)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i]== searchNum)
        {
            cout << "Искомое значение " << searchNum << " имеет индекс " << i << endl;
            return;
        }
    }
    cout << "Искомое значение " << searchNum << " не найдено в массиве" << endl;
}
template<typename T>
T searchMax(T* array, int size)
{
    T max = array[0];
    for (int i = 0; i < size; ++i)
    {
        if (max < array[i])
            max = array[i];
    }
    return max;
}
template<typename T>
T searchMin(T* array, int size)
{
    T min = array[0];
    for (int i = 0; i < size; ++i)
    {
        if (min > array[i])
            min = array[i];
    }
    return min;
}
template<typename T>
int binarySearch(T* array, int size, T searchNum)
{
    int left{};
    int right = size - 1;
    int middle{};
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (array[middle] == searchNum)
            return middle;
        else if (array[middle] < searchNum)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
template<typename T>
void replaceValue(T* array, int size, int i, T value)
{
    if (i < 0 || i >= size) return;
    array[i] = value;
}


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    // тестирование шаблонных функций
    int i{};
    int size{ 10 };
    int searchNum{};
    int* array = new int[size] {6, 5, 2, 9, 1, 12, 18, 0, 10, 11};
    printArray(array, size);
    cout << "Максимальное значение = " << searchMax(array, size) << " Минимальное значение = " << searchMin(array, size) << endl;
    cout << "Введите искомое значение массива ";
    cin >> searchNum;
    searchInArray(array, size, searchNum);
    bubbleSort(array, size);
    printArray(array, size);
    cout << "Введите искомое значение массива ";
    cin >> searchNum;
    searchInArray(array, size, searchNum);
    cin >> searchNum;
    cout << binarySearch(array, size, searchNum) << endl;
    cin >> i;
    cin >> searchNum;
    replaceValue(array, size, i, searchNum);
    printArray(array, size);
    double searchNum1{};
    double* array1 = new double[size] {5.5, 6.0, 4.4, 1.5, 1.6, 2.6, 9.6, 5.6, 4, 7.1};
    printArray(array1, size);
    cout << "Максимальное значение = " << searchMax(array1, size) << " Минимальное значение = " << searchMin(array1, size) << endl;
    cout << "Введите искомое значение массива ";
    cin >> searchNum1;
    searchInArray(array1, size, searchNum1);
    bubbleSort(array1, size);
    printArray(array1, size);
    cout << "Введите искомое значение массива ";
    cin >> searchNum1;
    searchInArray(array1, size, searchNum1);
    cin >> searchNum1;
    cout << binarySearch(array1, size, searchNum1) << endl;

    //Тестирование шаблонного класса матрица
    
    Matrix<int> arr1{ 4,4 };
    arr1.genMatrix();
    arr1.printMatrix();
    cout << endl;
    Matrix<int> arr2{ 4 };
    arr2.genMatrix();
    //arr2.enterMatrix();
    arr2.printMatrix();
    cout << endl;
    Matrix<int> arr3{ 3 };
    arr3.genMatrix();
    arr3.printMatrix();
    cout << endl;
    Matrix<int> arr4{ 2 };
    arr4.genMatrix();
    try
    {
        arr4 = arr3 + arr1;
    }
    catch (MyEsception &ex)
    {
        cout << ex.what() << endl;
        cout << "Error #" << ex.getDateState() << endl;
    }
    arr4.printMatrix();
    cout << endl;
    try
    {
        arr4 = arr3 - arr1;
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Error #" << ex.getDateState() << endl;
    }
    arr4.printMatrix();
    cout << endl;
    try
    {
        arr4 = arr3 / arr1;
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Error #" << ex.getDateState() << endl;
    }
    arr4.printMatrix();
    cout << endl;
    try
    {
        arr4 = arr3 * arr1;
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Error #" << ex.getDateState() << endl;
    }
    arr4.printMatrix();
    cout << endl;
    int row{-1};
    int col{-1};
    try
    {
        cin >> row;
        cin >> col;
        cout << arr1(row, col) << endl;
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Error #" << ex.getDateState() << endl;
    }

    Matrix<double> darr1{ 2,3 };
    darr1.genMatrix();
    darr1.printMatrix();
    cout << endl;
    Matrix<double> darr2{ 3,2 };
    darr2.genMatrix();
    darr2.printMatrix();
    cout << endl;
    Matrix<double> darr3{ 2 };
    darr3.genMatrix();
    darr3.printMatrix();
    cout << endl;
    try
    {
        darr3 = darr1 * darr2;
    }
    catch (MyEsception & ex)
    {
        cout << ex.what() << endl;
        cout << "Error #" << ex.getDateState() << endl;
    }

    return 0;
}

