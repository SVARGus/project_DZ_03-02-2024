#pragma once
#include <iostream>
#include <fstream>
#include <vector>

/*
������� 3

�������� ����������� ����� Shape ��� ��������� ������� �����.

���������� ����������� ������:
Show() � ����� �� ����� ���������� � ������,
Save() � ���������� ������ � ����,
Load() � ���������� ������ �� �����.

���������� ����������� ������:
Square � �������, ������� ��������������� ������������ ������ �������� ���� � ������ �������;
Rectangle� ������������� � ��������� ������������ �������� ������ ���� � ���������;
Circle � ���������� � ��������� ������������ ������ � ��������;
Ellipse � ������ � ��������� ������������ �������� ���� ���������� ������ ���� �������������� �� ���������, 
������������� ���� ���������, � ��������� ����� ��������������.

�������� ������ �����, ��������� ������ � ����, ��������� � ������ ������ � ���������� ���������� � �������.
*/
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;

class Shape
{
public:
	virtual ~Shape() {}
	virtual void Show() const = 0;
	virtual void Save(ofstream& outFile) const = 0;
	virtual void Load(ifstream& inFile) = 0;
};
class Square : public Shape
{
	int x{}, y{}; // ���������� �������� ������ ����
	int sideLength{}; // ����� �������
public:
	Square(int x, int y, int sideLength) : x{ x }, y{ y }, sideLength{ sideLength } {}
	void Show() const override {
		cout << "������� � ������������ �������� ������ ����: (" << x << ", " << y << ") � ������ �������: " << sideLength << endl;
	}
	void Save(ofstream& outFile) const override {
		outFile << "Square " << x << " " << y << " " << sideLength << endl;
	}
	void Load(ifstream& InFile) override {
		InFile >> x >> y >> sideLength;
	}
};

class Rectangle : public Shape
{
	int x{}, y{}; // ���������� �������� ������ ����
	int width{}, heigth{}; // ������ � ������
public:
	Rectangle(int x, int y, int width, int heigth) : x{ x }, y{ y }, width{ width }, heigth{ heigth } {}
	void Show() const override {
		cout << "������������� � ������������ �������� ������ ����: (" << x << ", " << y << "),  ������: " << width << ", ������: " << heigth << endl;
	}
	void Save(ofstream& outFile) const override {
		outFile << "Rectangle " << x << " " << y << " " << width << " " << heigth << endl;
	}
	void Load(ifstream& InFile) override {
		InFile >> x >> y >> width >> heigth;
	}
};

class Circle : public Shape
{
	int x{}, y{}; // ���������� ������ �����
	int radius{}; // ������
public:
	Circle(int x, int y, int radius) : x{ x }, y{ y }, radius{ radius } {}
	void Show() const override {
		cout << "���� � ������������ ������ ����������: (" << x << ", " << y << "),  ������: " << radius << endl;
	}
	void Save(ofstream& outFile) const override {
		outFile << "Circle " << x << " " << y << " " << radius << endl;
	}
	void Load(ifstream& InFile) override {
		InFile >> x >> y >> radius;
	}
};

class Ellipse : public Shape
{
	int x{}, y{}; // ���������� �������� ������ ���� ���������� ��������������
	int width{}, heigth{}; // ������ � ������ ���������� ��������������
public:
	Ellipse(int x, int y, int width, int heigth) : x{ x }, y{ y }, width{ width }, heigth{ heigth } {}
	void Show() const override {
		cout << "����� � ������������ �������� ������ ����: (" << x << ", " << y << "),  ������: " << width << ", ������: " << heigth << endl;
	}
	void Save(ofstream& outFile) const override {
		outFile << "Ellipse " << x << " " << y << " " << width << " " << heigth << endl;
	}
	void Load(ifstream& InFile) override {
		InFile >> x >> y >> width >> heigth;
	}
};

// ������� � cpp ���� ����������
// ��������� ������� ���������� �� ������� � �������� � ������
void SaveShapes(const vector<Shape*>* arrShape, const string& filename);
void LoadShapes(vector<Shape*>* arrShape, const string& filename);