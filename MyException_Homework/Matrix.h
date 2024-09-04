#pragma once
#include <iostream>
#include "MyException.h"
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
class Matrix {
    int row{}; // строка
    int col{}; // столбец
    T** array{ nullptr };
public:
    int getRow() { return row; };
    int getCol() { return col; };
    Matrix(const int row, const int col); // Базовый конструктор
    explicit Matrix(const int size); // Базовый конструктор для квадратной матрицы
    Matrix(const Matrix<T>& matrix); // конструктор копирования
    ~Matrix(); // деструктор
    void genMatrix(); //генератор случайных чисел
    void enterMatrix(); // ввод всей матрицы с клавиатуры
    T& operator() (const int row, const int col); // оператор () для внесения изменений по индексу
    const T& operator() (const int row, const int col) const; // оператор () для вывода значения по индексу
    void printMatrix() const; // вывод на экран всей матрицы
    Matrix<T>& operator= (const Matrix<T>& matrix); // оператор копирующиго присваивания
    /*операции + , -, *, /; будут применены упрощенные правила арифметики для деления.
    Если углубляться в матиматику матриц, то там много правил вычисления и при этом делить матрицы друг на друга нельзя
    (хотя некоторые называюют деление одной матрицы на другую как умножение одной матрицы на обратную другой матрицы */
    template<class T>
    friend Matrix<T> operator+ (const Matrix<T>& matrix1, const Matrix<T>& matrix2); // дружественный оператор (функция) сложения
    template<class T>
    friend Matrix<T> operator- (const Matrix<T>& matrix1, const Matrix<T>& matrix2); // Дружественный оператор (функция) вычитания 
    template<class T>
    friend Matrix<T> operator* (const Matrix<T>& matrix1, const Matrix<T>& matrix2); // Дружественный оператор (функция) умножения
    template<class T>
    friend Matrix<T> operator/ (const Matrix<T>& matrix1, const Matrix<T>& matrix2); // Дружественный оператор (функция) деления
    T max(); // поиск максимального элемента в матрице
    T min(); // поиск минимального элемента в матрице
};
template<class T>
Matrix<T>::Matrix(const int row, const int col) {
    if (row <= 0 || col <= 0)
        throw MyEsception("Неверно задан размер массива", 1);
    this->row = row;
    this->col = col;
    array = new T* [this->row];
    for (int i = 0; i < row; ++i)
        array[i] = new T[this->col];
}
template<class T>
Matrix<T>::Matrix(const int size) {
    if (size <= 0)
        throw MyEsception("Неверно задан размер массива", 1);
    this->row = size;
    this->col = size;
    array = new T* [this->row];
    for (int i = 0; i < row; ++i)
        array[i] = new T[this->col];
}
template<class T>
Matrix<T>::Matrix(const Matrix<T>& matrix) {
    row = matrix.row;
    col = matrix.col;
    array = new T* [row];
    for (int i = 0; i < row; ++i)
    {
        array[i] = new T[col];
        for (int j = 0; j < col; ++j)
            array[i][j] = matrix.array[i][j];
    }
}
template<class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < row; ++i)
        delete[] array[i];
    delete[]array;
}
template<class T>
void Matrix<T>::genMatrix() {
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            array[i][j] = rand() % 10 + (rand() % 11 * 0.1); // генератор под целые и дробные числа для будущего шаблона
        }
    }
}
template<class T>
void Matrix<T>::enterMatrix() {
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            // !!!!!! прописать ловушку для поимки неверного типа данных - надо подумать как это сделать с учетом если класс будет шаблонный
            // пока идей нету, вопрос оставлю открытым
            cin >> array[i][j];
    }
}
template<class T>
T& Matrix<T>::operator() (const int row, const int col) {
    if ((row >= this->row || row < 0) && (col >= this->col || col < 0))
        throw MyEsception("Не верно указан индекс строки и столбца", 6);
    if (row >= this->row || row < 0)
        throw MyEsception("Не верно указан индекс строки", 4);
    if (col >= this->col || col < 0)
        throw MyEsception("Не верно указан индекс столбца", 5);
    return array[row][col];
}
template<class T>
const T& Matrix<T>::operator() (const int row, const int col) const {
    if ((row >= this->row || row < 0) && (col >= this->col || col < 0))
        throw MyEsception("Не верно указан индекс строки и столбца", 6);
    if (row >= this->row || row < 0)
        throw MyEsception("Не верно указан индекс строки", 4);
    if (col >= this->col || col < 0)
        throw MyEsception("Не верно указан индекс столбца", 5);
    return array[row][col];
}
template<class T>
void Matrix<T>::printMatrix() const {
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
}
template<class T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& matrix) {
    if (this != &matrix)
    {
        if (row != matrix.row || col != matrix.col)
        {
            for (int i = 0; i < row; ++i)
                delete[] array[i];
            delete[]array;
            row = matrix.row;
            col = matrix.col;

            array = new T* [row];
            for (int i = 0; i < row; ++i)
                array[i] = new T[col];
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
                array[i][j] = matrix.array[i][j];
        }
    }
    return *this;
}
// операция сложения матриц выполнена по математическим правилам
template<class T>
Matrix<T> operator+ (const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col)
        throw MyEsception("Нельзя суммировать матрицы разных размеров", 2);
    Matrix<T> matrix{ matrix1.row, matrix1.col };
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.col; ++j)
            matrix.array[i][j] = matrix1.array[i][j] + matrix2.array[i][j];
    }
    return matrix;
}
// операция вычитания матриц выполнена по математическим правилам
template<class T>
Matrix<T> operator- (const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col)
        throw MyEsception("Нельзя вычитать одну матрицу из другой если они разного размера", 2);
    Matrix<T> matrix{ matrix1.row, matrix1.col };
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.col; ++j)
            matrix.array[i][j] = matrix1.array[i][j] - matrix2.array[i][j];
    }
    return matrix;
}
// операция умножения матриц выполнена по математическим правилам
template<class T>
Matrix<T> operator* (const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    if (matrix1.col != matrix2.row)
        throw MyEsception("умножение матриц невозможно, так как не выполнено условие: количество срок 1 матрицы должно быть равно количеству столбцов 2 матрицы", 3);
    Matrix<T> matrix{ matrix1.row, matrix2.col };
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.col; ++j)
        {
            matrix.array[i][j] = 0;
            for (int n = 0; n < matrix1.col; ++n)
            {
                matrix.array[i][j] = matrix.array[i][j] + (matrix1.array[i][n] * matrix2.array[n][j]);
            }
        }
    }
    return matrix;
}
// операция деления матриц выполнена по своему принципу равенства размеров матриц
template<class T>
Matrix<T> operator/ (const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col)
    {
        throw MyEsception("Нельзя делить матрицы друг на друга разных размеров", 2);
    }
    Matrix<T> matrix{ matrix1.row, matrix1.col };
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.col; ++j)
        {
            if (matrix2.array[i][j] == 0)
                throw MyEsception("Делить на ноль нельзя", 0);
            matrix.array[i][j] = matrix1.array[i][j] / matrix2.array[i][j];
        }
    }
    return matrix;
}
template<class T>
T Matrix<T>::max() {
    T max = array[0][0];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            max = (max > array[i][j]) ? max : array[i][j];
        }
    }
    return max;
}
template<class T>
T Matrix<T>::min() {
    T min = array[0][0];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            min = (min < array[i][j]) ? min : array[i][j];
        }
    }
    return min;
}