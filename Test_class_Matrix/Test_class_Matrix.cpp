// Данный проект создан для создания своего класса Матрица без шаблонов, для тестирования корректности создания. Позже данный класс будет шаблонизирован в отщдельной работе для ДЗ
//

#include <iostream>
#include "MyException.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
/*
Перечень кодов ошибок: 
-1 - Неизвестная ошибка
0 - делить на ноль нельзя
1 - размер массива не может быть нулевым или отрицательным
2 - сложение, вычитание и деление матриц может быть только с одинаковым размером
3 - умножение матриц невозможно, так как не выполнено условие: количество срок 1 матрицы должно быть равно количеству столбцов 2 матрицы
4 - неверно указан индекс строки
5 - неверно указан индекс столбца
6 - неверно указан индекс строки и столбца
7 - введен не верный тип данных
*/

class Matrix {
    int row{}; // строка
    int col{}; // столбец
    int** array{ nullptr };
public:
    int getRow() { return row; };
    int getCol() { return col; };
    Matrix(const int row, const int col); // Базовый конструктор
    explicit Matrix(const int size); // Базовый конструктор для квадратной матрицы
    Matrix(const Matrix& matrix); // конструктор копирования
    ~Matrix(); // деструктор
    void genMatrix(); //генератор случайных чисел
    void enterMatrix(); // ввод всей матрицы с клавиатуры
    int& operator() (const int row, const int col); // оператор () для внесения изменений по индексу
    const int& operator() (const int row, const int col) const; // оператор () для вывода значения по индексу
    void printMatrix() const; // вывод на экран всей матрицы
    Matrix& operator= (const Matrix& matrix); // оператор копирующиго присваивания
    /*операции + , -, *, /; будут применены упрощенные правила арифметики для деления.
    Если углубляться в матиматику матриц, то там много правил вычисления и при этом делить матрицы друг на друга нельзя 
    (хотя некоторые называюют деление одной матрицы на другую как умножение одной матрицы на обратную другой матрицы */
    friend Matrix operator+ (const Matrix& matrix1, const Matrix& matrix2); // дружественный оператор (функция) сложения
    friend Matrix operator- (const Matrix& matrix1, const Matrix& matrix2); // Дружественный оператор (функция) вычитания 
    friend Matrix operator* (const Matrix& matrix1, const Matrix& matrix2); // Дружественный оператор (функция) умножения
    friend Matrix operator/ (const Matrix& matrix1, const Matrix& matrix2); // Дружественный оператор (функция) деления
};
Matrix::Matrix(const int row, const int col) {
    if (row <= 0 || col <=0)
        throw MyEsception("Неверно задан размер массива", 1);
    this->row = row;
    this->col = col;
    array = new int* [this->row];
    for (int i = 0; i < row; ++i)
        array[i] = new int[this->col];
}
Matrix::Matrix(const int size) {
    if (size <= 0)
        throw MyEsception("Неверно задан размер массива", 1);
    this->row = size;
    this->col = size;
    array = new int* [this->row];
    for (int i = 0; i < row; ++i)
        array[i] = new int[this->col];
}
Matrix::Matrix(const Matrix& matrix) {
    row = matrix.row;
    col = matrix.col;
    array = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        array[i] = new int[col];
        for (int j = 0; j < col; ++j)
            array[i][j] = matrix.array[i][j];
    }
}
Matrix::~Matrix() {
    for (int i = 0; i < row; ++i)
        delete[] array[i];
    delete[]array;
}
void Matrix::genMatrix() {
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            array[i][j] = rand() % 10 + (rand() % 11 * 0.1); // генератор под целые и дробные числа для будущего шаблона
        }
    }
}
void Matrix::enterMatrix() {
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            // !!!!!! прописать ловушку для поимки неверного типа данных - надо подумать как это сделать с учетом если класс будет шаблонный
            cin >> array[i][j];
    }
}
 int& Matrix::operator() (const int row, const int col) {
     if ((row >= this->row || row < 0) && (col >= this->col || col < 0))
         throw MyEsception("Не верно указан индекс строки и столбца", 6);
     if (row >= this->row || row < 0)
         throw MyEsception("Не верно указан индекс строки", 4);
     if (col >= this->col || col < 0)
         throw MyEsception("Не верно указан индекс столбца", 5);
     return array[row][col];
}
const int& Matrix::operator() (const int row, const int col) const {
    if ((row >= this->row || row < 0) && (col >= this->col || col < 0))
        throw MyEsception("Не верно указан индекс строки и столбца", 6);
    if (row >= this->row || row < 0)
        throw MyEsception("Не верно указан индекс строки", 4);
    if (col >= this->col || col < 0)
        throw MyEsception("Не верно указан индекс столбца", 5);
    return array[row][col];
}
void Matrix::printMatrix() const{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
}
Matrix& Matrix::operator= (const Matrix& matrix) {
    if (this != &matrix)
    {
        if (row != matrix.row || col != matrix.col)
        {
            for (int i = 0; i < row; ++i)
                delete[] array[i];
            delete[]array;
            row = matrix.row;
            col = matrix.col;

            array = new int* [row];
            for (int i = 0; i < row; ++i)
                array[i] = new int[col];
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
Matrix operator+ (const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col)
        throw MyEsception("Нельзя суммировать матрицы разных размеров", 2);
    Matrix matrix{matrix1.row, matrix1.col};
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.col; ++j)
            matrix.array[i][j] = matrix1.array[i][j] + matrix2.array[i][j];
    }
    return matrix;
}
// операция вычитания матриц выполнена по математическим правилам
Matrix operator- (const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col)
        throw MyEsception("Нельзя вычитать одну матрицу из другой если они разного размера", 2);
    Matrix matrix{ matrix1.row, matrix1.col };
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.col; ++j)
            matrix.array[i][j] = matrix1.array[i][j] - matrix2.array[i][j];
    }
    return matrix;
}
// операция умножения матриц выполнена по математическим правилам
Matrix operator* (const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.col != matrix2.row)
        throw MyEsception("умножение матриц невозможно, так как не выполнено условие: количество срок 1 матрицы должно быть равно количеству столбцов 2 матрицы", 3);
    Matrix matrix{ matrix1.row, matrix2.col };
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
Matrix operator/ (const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col)
    {
        throw MyEsception("Нельзя делить матрицы друг на друга разных размеров", 2);
    }
    Matrix matrix{ matrix1.row, matrix1.col };
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



int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    Matrix arr1{ 5, 6 };
    arr1.genMatrix();
    arr1.printMatrix();
    cout << endl;
    Matrix arr2{ 2, 3 };
    arr2.genMatrix();
    arr2.printMatrix();
    cout << endl;
    Matrix arr3{ 2 };
    arr3.enterMatrix(); // надо подумать как реализовать исключение в случае ввода буквы или другого типа данных
    arr3.printMatrix();
    cout << endl;
    Matrix arr4{3};
    arr4.genMatrix();
    arr4.printMatrix();
    cout << endl;
    int size{};
    while (size <= 0)
    {
        try
        {
            cin >> size;
            Matrix arr5{ size };
        }
        catch (MyEsception& ex)
        {
            cout << ex.what() << endl;
            cout << "Код оишбки: " << ex.getDateState() << endl;
        }
    }
    try
    {
        Matrix arr5 = arr1 + arr2; // Отработал отлично
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Код оишбки: " << ex.getDateState() << endl;
    }
    Matrix arr6{ 2 };
    try
    {
        arr6 = arr1 - arr2; // Отработал отлично
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Код оишбки: " << ex.getDateState() << endl;
    }
    try
    {
        arr6 = arr1 / arr2; // Отработал отлично
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Код оишбки: " << ex.getDateState() << endl;
    }
    try
    {
        arr6 = arr1 * arr2; // Отработал отлично
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Код оишбки: " << ex.getDateState() << endl;
    }
    try
    {
        cout << arr3(5, 5); // Отработал отлично
    }
    catch (MyEsception &ex)
    {
        cout << ex.what() << endl;
        cout << "Код оишбки: " << ex.getDateState() << endl;
    }
    try
    {
        cout << arr3(5, 1); // Отработал отлично
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Код оишбки: " << ex.getDateState() << endl;
    }
    try
    {
        cout << arr3(1, 5); // Отработал отлично
    }
    catch (MyEsception& ex)
    {
        cout << ex.what() << endl;
        cout << "Код оишбки: " << ex.getDateState() << endl;
    }


    return 0;
}

