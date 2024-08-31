﻿/*
Задание 1.
Создать программу, обрабатывающую исключения при работе
с вещественными числами с использованием инструкции try,catch, throw.
Проект – консольное приложение.
В задании надо рассчитывать массив f [ x ] = 1 / (x – N) при x =0…k.
Варианты заданий.
N – последняя цифра номера паспорта плюс 5.
Необходимо отслеживать два исключения:
Деление на 0.
Выход за пределы диапазона.
При работе с программой менять k, чтобы получать разные
условия возможного возникновения исключений.
Пример.

Вариант задания: f[x] = 1 / (x-5). N=10
*/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void createArray(double*& array, const int k) {
    if (k == 0 || k < 0)
        throw "Размер массива не может быть отрицательным или нулевым\n";
    if (array != nullptr)
        delete[] array;
    array = new double[k] {};
}
void genIArray(double*& array, const int k, const int i) {
    int N{ 11 };
    if (i >= k || i < 0)
        throw "выход за пределы массива\n";
    if ((i - N) == 0)
        throw 0;
    array[i] = 1.0 / (i - N);
    cout << array[i] << endl;// временно
}
double printArray(const double* array, const int k, const int x) {
    if (x >= k || x < 0)
        throw "выход за пределы массива\n";
    return array[x];
}

int main()
{
    setlocale(LC_ALL, "ru");
    double* array{};
    int k{};
    int x{};
    int menu{};
    do
    {
        cout << "Меню действий:\n";
        cout << "1) Создать массив, указать размер\n";
        cout << "2) задать значение массива, укажите индекс\n";
        cout << "3) Вывод на печать значения из массива\n";
        cout << "0) Выход\n";
        cout << "Выберите вариант меню: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cin >> k;
            try
            {
                createArray(array, k);
            }
            catch (const char* &s) {
                cout << "Error!!! - " << s;
            }
            break;
        case 2:
            cin >> x;
            try {
                genIArray(array, k, x);
            }
            catch (const char* s) {
                cout << "Error!!! - " << s;
            }
            catch (int s) {
                cout << "Error!!! - Делить на 0 нельзя" << endl;
            }
            break;
        case 3:
            cout << "укажите индекс: ";
            cin >> x;
            try {
                cout << "Значение запрашиваемого из массива значения = " << printArray(array, k, x) << endl;
            }
            catch(const char* s) {
                cout << "Error!!! - " << s;
            }
        }
    } while (menu);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
