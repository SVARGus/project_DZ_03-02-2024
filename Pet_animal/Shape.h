#pragma once
#include <iostream>
#include <fstream>
#include <vector>

/*
Задание 3

Создайте абстрактный класс Shape для рисования плоских фигур.

Определите виртуальные методы:
Show() — вывод на экран информации о фигуре,
Save() — сохранение фигуры в файл,
Load() — считывание фигуры из файла.

Определите производные классы:
Square — квадрат, который характеризуется координатами левого верхнего угла и длиной стороны;
Rectangle— прямоугольник с заданными координатами верхнего левого угла и размерами;
Circle — окружность с заданными координатами центра и радиусом;
Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него прямоугольника со сторонами, 
параллельными осям координат, и размерами этого прямоугольника.

Создайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о фигурах.
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
	int x{}, y{}; // Координаты верхнего левого угла
	int sideLength{}; // Длина стороны
public:
	Square(int x, int y, int sideLength) : x{ x }, y{ y }, sideLength{ sideLength } {}
	void Show() const override {
		cout << "Квадрат с координатами верхнего левого угла: (" << x << ", " << y << ") и длиной стороны: " << sideLength << endl;
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
	int x{}, y{}; // Координаты верхнего левого угла
	int width{}, heigth{}; // Ширина и высота
public:
	Rectangle(int x, int y, int width, int heigth) : x{ x }, y{ y }, width{ width }, heigth{ heigth } {}
	void Show() const override {
		cout << "Прямоугольник с координатами верхнего левого угла: (" << x << ", " << y << "),  ширина: " << width << ", высота: " << heigth << endl;
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
	int x{}, y{}; // Координаты центар круга
	int radius{}; // Радиус
public:
	Circle(int x, int y, int radius) : x{ x }, y{ y }, radius{ radius } {}
	void Show() const override {
		cout << "Круг с координатами центра окружности: (" << x << ", " << y << "),  радиус: " << radius << endl;
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
	int x{}, y{}; // Координаты верхнего левого угла описанного прямоугольника
	int width{}, heigth{}; // Ширина и высота описанного прямоугольника
public:
	Ellipse(int x, int y, int width, int heigth) : x{ x }, y{ y }, width{ width }, heigth{ heigth } {}
	void Show() const override {
		cout << "Элипс с координатами верхнего левого угла: (" << x << ", " << y << "),  ширина: " << width << ", высота: " << heigth << endl;
	}
	void Save(ofstream& outFile) const override {
		outFile << "Ellipse " << x << " " << y << " " << width << " " << heigth << endl;
	}
	void Load(ifstream& InFile) override {
		InFile >> x >> y >> width >> heigth;
	}
};

// вынести в cpp файл реализацию
// Отдедьные функции сохранения из вектора и загрузки в вектор
void SaveShapes(const vector<Shape*>* arrShape, const string& filename);
void LoadShapes(vector<Shape*>* arrShape, const string& filename);