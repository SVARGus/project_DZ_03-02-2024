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
5. Для копирования объектов; В связи с использованием библиотеки String (в нем уже реализован метод копирования), 
   а остальные переменные не используют динамическую память и не требуется прегрузка оператора=, то метод глубокого копирования не требуется реализовывать.
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
	string nameReservoir{}; // имя водоема
	int width{}; // ширина в метрах
	int length{}; // длина в метрах
	int maxDepth{}; // максимальная глубина в метрах
	int typeReservoir{}; // тип водоема
	enum TYPETESERVOIR{PUDDLE = 1, POND, LAKE, SEA, OCEAN};


public:
	Reservoir() {};
	Reservoir(string nameReservoir, int width, int length, int maxDepth, int typeReservoir = 0) : // если передать водоем с нестандарнтым оахмером, но тип уже задан - то указать конкретный тип typeReservoir
		nameReservoir{ nameReservoir }, width{ width }, length{ length }, maxDepth{ maxDepth }, typeReservoir{ typeReservoir } {if (typeReservoir == 0){this->definitTypeReservoir();}};
	Reservoir(const Reservoir& reservoir) :
		nameReservoir{ reservoir.nameReservoir }, width{ reservoir.width }, length{ reservoir.length }, maxDepth{ reservoir.maxDepth }, typeReservoir{ reservoir.typeReservoir } {};
	Reservoir& operator= (const Reservoir& reservoir);
	~Reservoir() {};

	// возможно сеттеры стоит убрать
	void setNameReservoir(string nameReservoir) { this->nameReservoir = nameReservoir; }
	void setWidth(int width) { this->width = width; }
	void setLength(int length) { this->length = length; }
	void setMaxDepth(int maxDepth) { this->maxDepth = maxDepth; }
	void setTypeReservoit(int typeReservoir) { this->typeReservoir = typeReservoir; }

	string getNameReservoir() const { return nameReservoir; }
	int getWidth() const { return width; }
	int getLength() const { return length; }
	int getMaxDepth() const { return maxDepth; }
	int getTypeReservoir() const { return typeReservoir; }

	// добавить отдельные методы площади и объема в метрах для малых объемов посредством перегрузки или нового метода
	int areaReservoir() const { return length * width; }; // площади водема в км2
	int volumeReservoir() const { return areaReservoir() * (maxDepth / 1000.0); }; // объема водоема в км3

	void definitTypeReservoir(); // определение типа водоема
	bool compareTypeReservoir(Reservoir reservoir) const { return this->typeReservoir == reservoir.typeReservoir; }; // сравнение типов водоема
	bool compareAreaReservoir(Reservoir reservoir) const { return this->areaReservoir() > reservoir.areaReservoir(); }; // сравнение площади водоемов одного типа?????


	void printVolumeReservoir() const; // печать объема водоема
	void printAreaReservoir() const; // печать площади водема
	void printTypeReservoir() const; // вывод на печать типа водоема
	void printReservoir() const; // вывод на печать

	

};

