// project_DZ_03-02-2024.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Домашнее задание по С++ от 03.02.2024
*/

/*
Реализовать следующий функционал для работы с двумерным массивом (размер массива определите сами):
1 . Заполнения массива случайными данными
2. Вывод массива на экран
3. Поиск максимального элемента
4. Поиск минимального элемента
5. Поиск среднего арифметического
6. Линейный поиск элемента
7. Вывод на экран суммы элементов каждой строки
8. Вывод на экран суммы элементов каждого столбца
9. Вывод на экран суммы элементов всего массива
Программу реализовать с системой пользовательских меню, позволяющих осуществлять выбор типа данных массива и действия над ними.
Например:
Меню 1
1.	Выбрать тип данных
2.	Действия
3.	Выход
Меню 2
Выберите тип данных
1.	Long
2.	Int
3.	Double
4.	Char
5.	Short
Меню 2
Выберите действие
1 . Заполнения массива случайными данными
2. Вывод массива на экран
3. Поиск максимального элемента
4. Поиск минимального элемента
5. Поиск среднего арифметического
6. Линейный поиск элемента
7. Вывод на экран суммы элементов каждой строки
8. Вывод на экран суммы элементов каждого столбца
9. Вывод на экран суммы элементов всего массива
10. Главное меню
Программа должна быть реализована с использованием шаблонов. В программе должно быть минимум повторяющегося кода.   Продумайте архитектуру вашей программы, функций и их вызовов, механизмы взаимодействия между данными и действиями над ними. Используйте все знания, имеющиеся у вас на сегодняшний день.

*/

// За основу взят размер массива 5 на 10

#include <iostream>

template <typename T>
void GenArray(T Mass[5][10], int line, int column);
template<typename T> 
T Sum_Line_Array(T Mass[5][10], int num_line, int column);
void GenArray(char Mass[5][10], int line, int column);
template <typename T>
void PrintArray(T Mass[5][10], int line, int column);
template<typename T>
T Max_Element_Array(T Mass[5][10], int line, int column);
template<typename T>
T Min_Element_Array(T Mass[5][10], int line, int column);
template<typename T>
T Average_Element_Array(T Mass[5][10], int line, int column);
template<typename T>
void Line_Search_Array(T Mass[5][10], int line, int column, T searc_key);
template<typename T>
T Sum_Column_Array(T Mass[5][10], int line, int num_column);
template<typename T>
T Sum_Array(T Mass[5][10], int line, int column);

template <typename T> 
void GenArray(T Mass[5][10], int line, int column) //Шаблон для генерации массива, для типа данных char будет отдельная функция через перегрузку функции
{
    srand(time(NULL));
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            Mass[i][j] = rand() % 101 + (rand() % 10) / 10;
        }
    }
}

void GenArray(char Mass[5][10], int line, int column) //Шаблон для генерации массива типа char в диапазоне символов от 65 (A) до 122 (z)
{
    srand(time(NULL));
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            Mass[i][j] = rand() % 58 + 65;
        }
    }
}

template <typename T> 
void PrintArray(T Mass[5][10], int line, int column) //Шаблон вывода массива
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << Mass[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T> 
T Max_Element_Array(T Mass[5][10], int line, int column) // Поиск максимального элемента
{
    T Max = Mass[0][0];
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (Max < Mass[i][j])
                Max = Mass[i][j];
        }
    }
    //std::cout << "Максимальный элемент массива = " << Max << std::endl;
    return Max;
}


template<typename T> 
T Min_Element_Array(T Mass[5][10], int line, int column) // Поиск минимального элемента
{
    T Min = Mass[0][0];
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (Min > Mass[i][j])
                Min = Mass[i][j];
        }
    }
    //std::cout << "Минимальный элемент массива = " << Min << std::endl;
    return Min;
}

/*
char Average_Element_Array(char Mass[5][10], int line, int column)
{
    std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
    return;
}
*/

template<typename T> 
T Average_Element_Array(T Mass[5][10], int line, int column) // Поиск среднего арифметического
{
    if (T == char) // Можно было сделать отдельную функцию посредством перегрузки, но как мне кажется так лучше. Пример функции выше.
    {
        std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
        return;
    }
       
    return Sum_Array(Mass[5][10], int line, int column) / (line * column);
}

template<typename T> 
void Line_Search_Array(T Mass[5][10], int line, int column, T searc_key) // Линейный поиск элемента
{
    int x{};
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (Mass[i][j] == searc_key)
            {
                std::cout << "[" << i << "][" << j "]" << std::endl;
                ++x;
            }
        }
    }
    if (x == 0)
        std::cout << "Отсутствует" << std::endl;
}

template<typename T> 
T Sum_Line_Array(T Mass[5][10], int num_line, int column) //Сумма элементов строки
{
    if (T == char)
    {
        std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
        return;
    }
    T Sum{};
    for (int i = 0; i < column; i++)
        Sum += Muss[num_line][i];
    return Sum;
}

template<typename T>
T Sum_Column_Array(T Mass[5][10], int line, int num_column) //Сумма элементов столбца
{
    if (T == char)
    {
        std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
        return;
    }
    T Sum{};
    for (int i = 0; i < line; i++)
        Sum += Muss[i][num_column];
    return Sum;
}

template<typename T>
T Sum_Array(T Mass[5][10], int line, int column) //Сумма элементов всего массива
{
    if (T == char)
    {
        std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
        return;
    }
    T Sum{};
    for (int i = 0; i < line; i++)
        Sum += Sum_Line_Array(Mass[5][10], int i, int column);
    return Sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Тест по Гиту" << std::endl;
    std::cout << "Попытка синхронизировать проект с десктопной версией с флешки" << std::endl;

    return 0;
}