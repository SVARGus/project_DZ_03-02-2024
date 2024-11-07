#pragma once
#include <iostream>

/*
Задание 2

Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай». 
С помощью конструктора установить имя каждого животного и его характеристики.
*/
using std::cout;
using std::cin;
using std::endl;
using std::string;

class HomePet
{
protected:
	string name{}; // имя (кличка)
	string color{}; // цвет
	double weight{}; // вес
	int age{}; // возраст
	HomePet(const string& name, string color, double weight, int age) : name{ name }, color{ color }, weight{ weight }, age{ age } {}
public:
	virtual string getName() const { return name; }
	virtual string getColor() const { return color; }
	virtual double getWeight() const { return weight; }
	virtual int getAge() const { return age; }
	virtual void talk() const = 0;
	virtual void does() const = 0;
	virtual void printPet() const = 0;
	virtual ~HomePet() {}
};
class Dog : public HomePet
{
public:
	Dog(const string& name, string color, double weight, int age) : HomePet(name, color, weight, age) {}
	void talk() const override {
		cout << "Собака говорит: Гав-гав-гав" << endl;
	}
	void does() const override {
		cout << "Собака бежит и радостно хвостом виляет" << endl;
	}
	void printPet() const override {
		cout << "Собака по кличке: " << name << ", цвет шерсти: " << color << ", вес: " << weight << ", возраст: " << age << "." << endl;
	}
};
class Cat : public HomePet
{
public:
	Cat(const string& name, string color, double weight, int age) : HomePet(name, color, weight, age) {}
	void talk() const override {
		cout << "Кошка говорит: Мяу-мяу-мяу" << endl;
	}
	void does() const override {
		cout << "Кошка крадется прижав хвост" << endl;
	}
	void printPet() const override {
		cout << "Кошка по имени: " << name << ", цвет шерсти: " << color << ", вес: " << weight << ", возраст: " << age << "." << endl;
	}
};
class Parrot : public HomePet
{
public:
	Parrot(const string& name, string color, double weight, int age) : HomePet(name, color, weight, age) {}
	void talk() const override {
		cout << "Попугай щебечет и свистит" << endl;
	}
	void does() const override {
		cout << "Попугай летает" << endl;
	}
	void printPet() const override {
		cout << "Попугай по имени: " << name << ", цвет перьев: " << color << ", вес: " << weight << ", возраст: " << age << "." << endl;
	}
};

