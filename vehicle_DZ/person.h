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
	void addGarage(vehicle* Vehicle) { // добавление 
		garage.push_back(Vehicle);
	}
};

