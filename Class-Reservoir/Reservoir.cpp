#include "Reservoir.h"

void Reservoir::printVolumeReservoir() const
{
	cout << "Объем водоема = " << volumeReservoir() << " km3." << endl;
}
void Reservoir::printAreaReservoir() const
{
	cout << "Площадь водоема = " << areaReservoir() << " km2." << endl;
}

void Reservoir::definitTypeReservoir()
{
	double volumeReservoir = this->volumeReservoir();
	double areaReservoir = this->areaReservoir();
	if (maxDepth > 5000 && areaReservoir > 10000000)
		typeReservoir = 5;
	else if (maxDepth > 500 && areaReservoir > 10000)
		typeReservoir = 4;
	else if (maxDepth > 10 && areaReservoir > 1)
		typeReservoir = 3;
	else if (maxDepth <= 10 && areaReservoir > 0.00002)
		typeReservoir = 2;
	else if (maxDepth < 1 && areaReservoir <= 0.00002)
		typeReservoir = 1;
}

void Reservoir::printTypeReservoir() const
{
	switch (typeReservoir)
	{
	case Reservoir::PUDDLE:
		cout << "Лужа" << endl;
		break;
	case Reservoir::POND:
		cout << "Пруд" << endl;
		break;
	case Reservoir::LAKE:
		cout << "Озеро" << endl;
		break;
	case Reservoir::SEA:
		cout << "Море" << endl;
		break;
	case Reservoir::OCEAN:
		cout << "Океан" << endl;
		break;
	default:
		cout << "Тип водоема еще не определен!!!" << endl;
		break;
	}
}

void Reservoir::printReservoir() const
{
	cout << "Название водоема: " << nameReservoir << endl;
	cout << "Тип водоема: "; this->printTypeReservoir();
	cout << "Ширина водоема: " << width << " km" << endl;
	cout << "Длина водоема: " << length << " km" << endl;
	cout << "Максимальная глубина: " << maxDepth << endl;
	printAreaReservoir();
	printVolumeReservoir();
}

Reservoir& Reservoir::operator= (const Reservoir& reservoir)
{
	if (this != &reservoir)
	{
		nameReservoir = reservoir.nameReservoir;
		width = reservoir.width;
		length = reservoir.length;
		maxDepth = reservoir.maxDepth;
		typeReservoir = reservoir.typeReservoir;
	}
	return *this;
}