#pragma once

/*
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
5. Для копирования объектов; В связи с использованием библиотеки String (в нем уже реализован метод копирования), а остальные переменные не используют динамическую память и не требуется прегрузка оператора=
6. Остальные методы на усмотрение разработчика (методы set и get).

Написать интерфейс для работы с классом.
Реализовать динамический массив объектов класса с возможностью добавления, удаления объектов из массива.
Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функциичлены (например, для отображения данных о водоёме и т.д.).

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Reservoir
{
	string nameReservoir{};
	int width{};
	int length{};
	int maxDepth{};
	string typeReservoir{}; // тип водоема

public:
	void setNameReservoir(string nameReservoir) { this->nameReservoir = nameReservoir; }
	void setWidth(int width) { this->width = width; }
	void setLength(int length) { this->length = length; }
	void serMaxDepth(int maxDepth) { this->maxDepth = maxDepth; }

	string getNameReservoir() const { return nameReservoir; }
	int getWidth() const { return width; }
	int getLength() const { return length; }
	int gerMaxDepth() const { return maxDepth; }

	void volumeReservoir(); // объем водоема
	void areaReservoir(); // площадь водема
	void definitTypeReservoir(); // определение типа водоема
	void printReservoir(); // вывод на печать


};

