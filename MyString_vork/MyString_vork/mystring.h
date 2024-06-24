﻿#pragma once
class mystring
{
	static int count; // временная статическая переменная для проверки

	int size{};
	char* mString{ nullptr };

	//проектирование своего класса на подобии библиотеки string

	/*
	1) Создать конструктор по умолчанию (ok), конструктор копирования (ok)
	2) Надо сделать операторы перегрузки: + (ок), != (проверить), == (проверить), = (проверить), >=, <=, <, >, >>, <<, [],  (также сделать + к чарам)
	3) Методы поиски строки в подстроке, также метод поиска символа
	4) Создать деструктор с удалением динамической памяти (ok)
	5) Нужны ли еще прочие методы, например высчитывание размера строки или использовать из iostream по умолчанию.
	6) добавить getline свой и как его реализовать?
	7) Добавить метод реверса
	8) добавить метод замены на заглавные слов после точки
	9) Добавить метод замены символов
	*/
public:
	static int gerStaticCount() { return count; } // временный вывод. ПРОВЕРИЛ - работает
	static void setStaticCount() { ++count; } // увеличение статического счетчика для дружественных операторов и методов

	mystring();
	mystring(char* name); // ПРОВЕРИЛ - работает
	~mystring(); // Деструктор, ПРОВЕРИЛ - работает
	mystring(const mystring& name); // метод глубокого копирования. ПРОВЕРИЛ - работает
	
	void setmString(char* name); // ПРОВЕРИЛ - работает
	void remove(); // можно или лучше нужно добавить в приватную часть

	friend mystring operator+ (const mystring& name1, const mystring& name2);
	mystring operator= (const mystring& name);
	bool operator== (const mystring& name) const;
	bool operator!= (const mystring& name) const {	return !(*this == name); } // оператор не равно, зависит от оператора равно
	char operator[] (int index) const;
	char& operator[] (int index);
	friend std::istream& operator>> (std::istream& input, mystring& name);

	void print() const; // вывод на печать для проверки
};

