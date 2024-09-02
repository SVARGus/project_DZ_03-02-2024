// Данный проект создан для создания своего класса Матрица без шаблонов, для тестирования корректности создания. Позже данный класс будет шаблонизирован в отщдельной работе для ДЗ
//

#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;


class Matrix {
    int row{}; // строка
    int col{}; // столбец
    //int size{};
    int** array{ nullptr };
public:
    int getRow() { return row; };
    int getCol() { return col; };
    Matrix(int row, int col); // Базовый конструктор
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
Matrix::Matrix(int row, int col) {
    this->row = row;
    this->col = col;
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
            array[i][j] = rand() % 10 + (rand() % 11 * 0.1);
            //array[i][j] = rand() % 10 + (rand() % 11 * 0.1); // генератор под целые и дробные числа для будущего шаблона
        }
    }
}
void Matrix::enterMatrix() {
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            cin >> array[i][j];
    }
}
 int& Matrix::operator() (const int row, const int col) {
     return array[row][col];
}
const int& Matrix::operator() (const int row, const int col) const {
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
    {
        //прописать ловушку исключений, так как матрицы складывать можно если они одинакового размера
    }
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
    {
        //прописать ловушку исключений, так как матрицы вычитать можно если они одинакового размера
    }
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
    {
        //прописать ловушку исключений, так как умножении матриц число столбцов первой матрицы должно совпадать с числом строк второй матрицы
    }
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
        //прописать ловушку исключений, так как матрицы делить будет только если они равны по размеру
    }
    Matrix matrix{ matrix1.row, matrix1.col };
    for (int i = 0; i < matrix.row; ++i)
    {
        for (int j = 0; j < matrix.col; ++j)
            matrix.array[i][j] = matrix1.array[i][j] / matrix2.array[i][j];
        // прописать ловушку исключений, делить на ноль нельзя
    }
    return matrix;
}



int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    int size1{ 2 };
    int size2{ 3 };
    Matrix arr1{ size1 , size2};
    arr1.genMatrix();
    //arr1.printMatrix();
    cout << endl;
    Matrix arr2{ size1 , size2 };
    arr2.genMatrix();
    arr2.printMatrix();
    cout << endl;
    Matrix arr3 = arr1 + arr2;
    //arr3.printMatrix();
    cout << endl;
    Matrix arr4{ size1 , size2 };
    arr4.genMatrix();
    //arr4.printMatrix();
    cout << endl;
    arr3 = arr2 - arr4;
    //arr3.printMatrix();
    cout << endl;
    Matrix arr5{ 5 , 2 };
    arr5.genMatrix();
    arr5.printMatrix();
    cout << endl;
    arr3 = arr2 * arr5; // 2 на 3 и 3 на 2
    arr3.printMatrix();
    cout << arr3.getRow() << " " << arr3.getCol();

    cout << endl;


    return 0;
}

