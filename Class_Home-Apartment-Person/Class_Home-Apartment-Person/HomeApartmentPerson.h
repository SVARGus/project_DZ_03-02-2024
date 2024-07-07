#pragma once
#include <iostream>
#include <string>


/*
Тема: Указатель this. Побитовое копирование. Конст-руктор копирования.

Задание.

Создайте программу, имитирующую многоквартирный дом. Необходимо иметь классы “Человек”, “Квартира”, “Дом” . 
Класс “Квартира” содержит динамический массив объектов класса “Человек” . Класс “Дом” содержит массив объектов класса “Квартира” .

Каждый из классов содержит переменные-члены и функ-ции-члены, которые необходимы для предметной области класса. 
Обращаем ваше внимание, что память под стро-ковые значения выделяется динамически. Например, для ФИО в классе “Человек” . 
Не забывайте обеспечить классы различными конструкторами (конструктор копирования обязателен), деструкторами. В main протестировать ра-боту полученного набора классов.
*/

/*
Для теста будет сделан дом из 3 этажей, 5 квартир на каждом этаже (2 однушки, 2 двушки и 1 трешка). 

Попробовать реализовать ограничения по количеству персон в квартире
В однушке может проживат до 2 взрослых от 18 лет и один ребенок до 20 лет.
В двушке может жить до 2 взрослых от 18 лет и 2 ребенка до 20 лет.
в трешке может жить до 3 взрослых и до 4 детей, но неболее 6 человек в сумме.
*/

class Person
{
	std::string fio{};
	
	int age{};
	friend class Home;
	friend class Apartment;
	Person() {};

public:

	Person(std::string fio, int age); // OK
	std::string getFIO() const; // OK
	int getAge() const; // OK
	void print() const; // OK
	friend std::istream& operator>> (std::istream& input, Person& person); // OK
	Person& operator= (const Person& person);

	//Person operator= (char* fio, int age);
};

class Apartment
{
	static int count;
	int appartNumber{};/*номер квартиры будет уникальный для каждой квартиры - надо подумать как реализовать присваивание уникального номера каждой квартире
	например зависимость от статической переменной которая обнуляется при инициализации дома*/
	int room{}; // количество комнат
	int sizePerson{}; // сколько может быть прописано в квартиру
	Person* person{};

	friend class Home;
	Apartment() {};

public:
	explicit Apartment(int room);
	void print() const;
	void freeRegistrPerson(Person& person);
	//Person& operator[] (int appartNumber); // надо подумать как перегрузить данный оператор чтобы в квадратных скобках указывать  номер квартиры
	
};

class Home
{
	std::string street{}; // улица
	int numberHous{}; // номер дома
	int floor{}; // количество этажей
	int numbeOfApartmenOnFloor{}; // количество квартир на этаже
	Apartment** apartment{};

public:
	Home(std::string street, int numberHous, int floor, int numbeOfApartmenOnFloor, int* numRoomApartFloor); // конструктор создания дома, после создания и инициализации номеров квартиры, обнулить счетчик квартир = 1
};