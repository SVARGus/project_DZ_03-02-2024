#pragma once
#include <iostream>

/*
������� 2

������� ������� ����� ��������� �������� � ����������� ������ �������, ������, ��������. 
� ������� ������������ ���������� ��� ������� ��������� � ��� ��������������.
*/
using std::cout;
using std::cin;
using std::endl;
using std::string;

class HomePet
{
protected:
	string name{}; // ��� (������)
	string color{}; // ����
	double weight{}; // ���
	int age{}; // �������
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
		cout << "������ �������: ���-���-���" << endl;
	}
	void does() const override {
		cout << "������ ����� � �������� ������� ������" << endl;
	}
	void printPet() const override {
		cout << "������ �� ������: " << name << ", ���� ������: " << color << ", ���: " << weight << ", �������: " << age << "." << endl;
	}
};
class Cat : public HomePet
{
public:
	Cat(const string& name, string color, double weight, int age) : HomePet(name, color, weight, age) {}
	void talk() const override {
		cout << "����� �������: ���-���-���" << endl;
	}
	void does() const override {
		cout << "����� �������� ������ �����" << endl;
	}
	void printPet() const override {
		cout << "����� �� �����: " << name << ", ���� ������: " << color << ", ���: " << weight << ", �������: " << age << "." << endl;
	}
};
class Parrot : public HomePet
{
public:
	Parrot(const string& name, string color, double weight, int age) : HomePet(name, color, weight, age) {}
	void talk() const override {
		cout << "������� ������� � �������" << endl;
	}
	void does() const override {
		cout << "������� ������" << endl;
	}
	void printPet() const override {
		cout << "������� �� �����: " << name << ", ���� ������: " << color << ", ���: " << weight << ", �������: " << age << "." << endl;
	}
};

