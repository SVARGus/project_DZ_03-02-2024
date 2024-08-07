﻿/*
Домашнее задание про водоемы
*/

/*
Тема: Константная функция-член, explicit конструктор.
Задание.
Разработать класс Reservoir(водоем). Класс должен обязательно иметь поле «название». 
Класс должен содержать: конструктор по умолчанию, конструктор с параметрами,
при необходимости реализовать деструктор и конструктор копирования.

Добавить методы для:
1. Определения приблизительного объема (ширина*длина*максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (методы set и get).

Написать интерфейс для работы с классом. 
Реализовать динамический массив объектов класса с возможностью добавления, удаления объектов из массива.
Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функциичлены (например, для отображения данных о водоёме и т.д.).

*/

#include <iostream>
#include"Reservoir.h"

using std::cout;
using std::cin;
using std::string;

int main()
{
    std::cout << "Hello World!\n";
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
