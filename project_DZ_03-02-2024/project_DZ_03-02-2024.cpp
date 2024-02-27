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

template<typename T>
void GenArray(T Mass, int line, int column);
template<typename T> 
T Sum_Line_Array(T Mass, int num_line, int column);
void GenArray(char Mass, int line, int column);
template<typename T>
void PrintArray(T Mass, int line, int column);
template<typename T>
T Max_Element_Array(T Mass, int line, int column);
template<typename T>
T Min_Element_Array(T Mass, int line, int column);
template<typename T>
T Average_Element_Array(T Mass, int line, int column);
template<typename T>
void Line_Search_Array(T Mass, int line, int column, T searc_key);
template<typename T>
T Sum_Column_Array(T Mass, int line, int num_column);
template<typename T>
T Sum_Array(T Mass, int line, int column);
char Average_Element_Array(char Mass, int line, int column);
char Sum_Line_Array(char Mass, int num_line, int column);
char Sum_Column_Array(char Mass, int line, int num_column);
char Sum_Array(char Mass[5][10], int line, int column);

template<typename T>
void GenArray(T Mass[5][10], int line, int column) //Шаблон для генерации массива, для типа данных char будет отдельная функция через перегрузку функции
{
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

char Average_Element_Array(char Mass[5][10], int line, int column)
{
    std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
    return 0;
}

template<typename T> 
T Average_Element_Array(T Mass[5][10], int line, int column) // Поиск среднего арифметического
{   
    return (T)Sum_Array(Mass[5][10], line, column) / (line * column);
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
                std::cout << "[" << i << "][" << j << "]" << std::endl;
                ++x;
            }
        }
    }
    if (x == 0)
        std::cout << "Отсутствует" << std::endl;
}

char Sum_Line_Array(char Mass[5][10], int num_line, int column)
{
    std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
}

template<typename T> 
T Sum_Line_Array(T Mass[5][10], int num_line, int column) //Сумма элементов строки
{
    T Sum{};
    for (int i = 0; i < column; i++)
        Sum += Mass[num_line][i];
    return Sum;
}

char Sum_Column_Array(char Mass[5][10], int line, int num_column)
{
    std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
}

template<typename T>
T Sum_Column_Array(T Mass[5][10], int line, int num_column) //Сумма элементов столбца
{
    T Sum{};
    for (int i = 0; i < line; i++)
        Sum += Mass[i][num_column];
    return Sum;
}

char Sum_Array(char Mass[5][10], int line, int column)
{
    std::cout << "переменные типа char (символы) не вычисляются!!!" << std::endl;
}

template<typename T>
T Sum_Array(T Mass[5][10], int line, int column) //Сумма элементов всего массива
{
    T Sum{};
    for (int i = 0; i < line; i++)
        Sum += Sum_Line_Array(Mass[5][10], i, column);
    return Sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int Menu{}; //Главное меню
    int Menu_Type_Date{}; //Меню выбора типа данных
    int Menu_Activ{}; //Меню выбора действия
    int Line{ 5 };
    int Column{ 10 };
    int Mass[5][10]{};
    int Searc_Key{};
    
    do
    {
        std::cout << "Главное меню" << std::endl;
        std::cout << "1.	Выбрать тип данных" << std::endl;
        std::cout << "2.	Действия" << std::endl;
        std::cout << "3.	Выход" << std::endl;
        std::cin >> Menu;
        switch (Menu)
        {
        case 1:
            do
            {
                std::cout << "Выберите тип данных" << std::endl;
                std::cout << "1.	Long" << std::endl;
                std::cout << "2.	Int" << std::endl;
                std::cout << "3.	Double" << std::endl;
                std::cout << "4.	Char" << std::endl;
                std::cout << "5.	Short" << std::endl;
                std::cin >> Menu_Type_Date;
                switch (Menu_Type_Date)
                {
                case 1:
                    long Mass[5][10]{};
                    break;
                case 2:
                    int Mass[5][10]{};
                    break;
                case 3:
                    double Mass[5][10]{};
                    break;
                case 4:
                    char Mass[5][10]{};
                    break;
                case 5:
                    short Mass[5][10]{};
                    break;
                default:
                    std::cout << "Вы не выбрали тип данных! Повторите выбор ";
                    std::cin >> Menu_Type_Date;
                    break;
                }
            } while (Menu_Type_Date > 5 || Menu_Type_Date < 1);
            break;
        case 2:
            do
            {
                std::cout << "Выберите тип действия" << std::endl;
                std::cout << "1.	Заполнения массива случайными данными" << std::endl;
                std::cout << "2.	Вывод массива на экран" << std::endl;
                std::cout << "3.	Поиск максимального элемента" << std::endl;
                std::cout << "4.	Поиск минимального элемента" << std::endl;
                std::cout << "5.	Поиск среднего арифметического" << std::endl;
                std::cout << "6.	Линейный поиск элемента" << std::endl;
                std::cout << "7.	Вывод на экран суммы элементов каждой строки" << std::endl;
                std::cout << "8.	Вывод на экран суммы элементов каждого столбца" << std::endl;
                std::cout << "9.	Вывод на экран суммы элементов всего массива" << std::endl;
                std::cout << "10.	Главное меню" << std::endl;
                std::cin >> Menu_Activ;
                switch (Menu_Activ)
                {
                case 1:
                    GenArray(Mass[5][10], Line, Column);
                    break;
                case 2:
                    PrintArray(Mass[5][10], Line, Column);
                    break;
                case 3:
                    Max_Element_Array(Mass[5][10], Line, Column);
                    break;
                case 4:
                    Min_Element_Array(Mass[5][10], Line, Column);
                    break;
                case 5:
                    Average_Element_Array(Mass[5][10], Line, Column);
                    break;
                case 6:
                    std::cout << "Введите искомый элемент в массиве: ";
                    std::cin >> Searc_Key;
                    std::cout << "Искомый элемент  массива ";
                    Line_Search_Array(Mass[5][10], Line, Column, Searc_Key);
                    break;
                case 7:
                    for (int i = 0; i < Line; ++i)
                    {

                    }
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    break;
                default:
                    break;
                }
            } while (Menu_Activ != 10);
            break;
        default:
            std::cout << "Не корректный выбор! Повторите ввод варианта меню! ";
            std::cin >> Menu;
            break;
        }
    } while (Menu != 3);

    return 0;
}