#pragma once
#include <iostream>
#include <vector>
#include "vehicle.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// подумать над созданием гаража как отдельного класса для использования в Персоне
class person
{
	vector<vehicle*> garage{};
public:
	int getSizeGarage() { return garage.size(); } // вывод информации и рразмере гаража
	//vector<vehicle*> garage{};
	void addGarage(vehicle* Vehicle) { // добавление 
		garage.push_back(Vehicle);
	}
	void eraseGarage(int index) // удаление из гаража по индексу
	{
		if (index >= 0 && index < garage.size())
		{
			delete garage[index];
			garage.erase(garage.begin() + index);
		}
		else
			cout << "Индекс вне диапазона!!!" << endl;
	}
	void DisplaySpecificationsGarage(int index)
	{
		if (index >= 0 && index < garage.size())
			garage[index]->DisplaySpecifications();
		else
			cout << "некорректный индекс!!!" << endl;
	}
	void UseVehicleGarage(int index)
	{
		if (index >= 0 && index < garage.size())
			garage[index]->UseVehicle();
		else
			cout << "некорректный индекс!!!" << endl;
	}
	void ServiceVehicleGarage(int index)
	{
		if (index >= 0 && index < garage.size())
			garage[index]->ServiceVehicle();
		else
			cout << "некорректный индекс!!!" << endl;
	}
	~person()
	{
		for (auto v : garage)
		{
			delete v;
		}
		garage.clear();
	}
};

