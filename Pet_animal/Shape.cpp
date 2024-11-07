#include "Shape.h"

void SaveShapes(const vector<Shape*>* arrShape, const string& filename)
{
	ofstream outFile(filename);
	if (outFile.is_open())
	{
		for (const auto* shapes : *arrShape)
		{
			shapes->Save(outFile);
		}
		outFile.close();
	}
	else
	{
		cout << "Ошибка при открытии файла для записи!!!" << endl;
	}
}
void LoadShapes(vector<Shape*>* arrShape, const string& filename)
{
	ifstream inFile(filename);
	if (inFile.is_open())
	{
		string shapeTipe{};
		while (inFile >> shapeTipe)
		{
			if (shapeTipe == "Square")
			{
				Shape* square = new Square(0, 0, 0);
				square->Load(inFile);
				arrShape->push_back(square);
			}
			else if (shapeTipe == "Rectangle")
			{
				Shape* rectangle = new Rectangle(0, 0, 0, 0);
				rectangle->Load(inFile);
				arrShape->push_back(rectangle);
			}
			else if (shapeTipe == "Circle")
			{
				Shape* circle = new Circle(0, 0, 0);
				circle->Load(inFile);
				arrShape->push_back(circle);
			}
			else if (shapeTipe == "Ellipse")
			{
				Shape* ellipse = new Ellipse(0, 0, 0, 0);
				ellipse->Load(inFile);
				arrShape->push_back(ellipse);
			}
		}
		inFile.close();
	}
	else
	{
		cout << "Ошибка открытия файла для чтения!!!" << endl;
	}
}