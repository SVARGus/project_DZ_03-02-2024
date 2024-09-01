// Данный проект создан для создания своего класса Матрица без шаблонов, для тестирования корректности создания. Позже данный класс будет шаблонизирован в отщдельной работе для ДЗ
//

#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;


class Matrix {
    int size{};
    int** array{ nullptr };
public:
    Matrix(int size); // Базовый конструктор
    Matrix(const Matrix& matrix); // конструктор копирования
    ~Matrix(); // деструктор
    void genMatrix(); //генератор случайных чисел
    void enterMatrix(); // ввод всей матрицы с клавиатуры
    int& operator() (const int row, const int col); // оператор () для внесения изменений по индексу
    const int& operator() (const int row, const int col) const; // оператор () для вывода значения по индексу
    void printMatrix() const; // вывод на экран всей матрицы
    Matrix& operator= (const Matrix& matrix); // оператор копирующиго присваивания

};
Matrix::Matrix(int size) {
    this->size = size;
    array = new int* [this->size];
    for (int i = 0; i < size; ++i)
        array[i] = new int[this->size];
}
Matrix::Matrix(const Matrix& matrix) {
    size = matrix.size;
    array = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = new int[size];
        for (int j = 0; j < size; ++j)
            array[i][j] = matrix.array[i][j];
    }
}
Matrix::~Matrix() {
    for (int i = 0; i < size; i++)
        delete[] array[i];
    delete[]array;
}
void Matrix::genMatrix() {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = rand() % 10 + (rand() % 11 * 0.1);
            //array[i][j] = rand() % 10 + (rand() % 11 * 0.1); // генератор под целые и дробные числа для будущего шаблона
        }
    }
}
void Matrix::enterMatrix() {
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
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
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
}
Matrix& Matrix::operator= (const Matrix& matrix) {
    if (this != &matrix)
    {
        if (size != matrix.size)
        {
            for (int i = 0; i < size; i++)
                delete[] array[i];
            delete[]array;
            size = matrix.size;
            array = new int* [size];
            for (int i = 0; i < size; ++i)
                array[i] = new int[size];
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
                array[i][j] = matrix.array[i][j];
        }
    }
    return *this;
}





int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    int size1{ 2 };
    int size2{ 3 };
    Matrix arr1{ size1 };
    arr1.genMatrix();
    arr1.printMatrix();
    cout << endl;
    Matrix arr2{ size2 };
    arr2.genMatrix();
    arr2.printMatrix();
    cout << endl;
    Matrix arr3{ arr1 };
    arr3.printMatrix();
    cout << endl;
    Matrix arr4 = arr2;
    arr4.printMatrix();
    cout << endl;
    Matrix arr5{ size1 };
    arr5.enterMatrix();
    arr5.printMatrix();
    cout << endl;
    arr5(1, 1) = 10;
    cout << arr5(1, 1);
    cout << endl;
    arr5.printMatrix();
    cout << endl;

    return 0;
}

