#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class vehicle // чисто вирутальный базовый класс (обстрактный)
{
public:
	virtual ~vehicle(){}
	
	virtual void DisplaySpecifications() const = 0; // Отображение характеристик транспорта
	virtual void UseVehicle() const = 0; // Использования транспорта
	virtual void ServiceVehicle() const = 0; // Обслуживание траспорта

};
// Подкласс Велосипед с подкласами различных видов
class bicycle : public vehicle
{
protected:
	string nameBicycle{};
	int seatCount{};
	int speedCount{};
public:
	bicycle(string name, int seat, int speed) : nameBicycle{name}, seatCount(seat), speedCount{speed}{}
	void ServiceVehicle() const override
	{
		cout << "Обслуживание: смазка цепи, регулировка сиденья, проверка давления в шинах." << endl;
	}
};
class sport_bicycle : public bicycle
{

public:
	sport_bicycle(string name) : bicycle(name, 1, 18) {};
	void DisplaySpecifications() const override
	{
		cout << "Спортивый велосипед. Характеристики: " << endl;
		cout << "\t Название: " << nameBicycle << endl;
		cout << "\t Количество сидушек: " << seatCount << endl;
		cout << "\t Количество скоростей: " << speedCount << endl;
	}
	void UseVehicle() const override
	{
		cout << "Использовать спортивный велоспид марки " << nameBicycle << " для скоростных заездов на шоссе" << endl;
	}
};
class classic_bicycle : public bicycle
{

public:
	classic_bicycle(string name, int speed) : bicycle(name, 1, speed) {};
	void DisplaySpecifications() const override
	{
		cout << "Классический велосипед. Характеристики: " << endl;
		cout << "\t Название: " << nameBicycle << endl;
		cout << "\t Количество сидушек: " << seatCount << endl;
		cout << "\t Количество скоростей: " << speedCount << endl;
	}
	void UseVehicle() const override
	{
		cout << "Использовать велоспид марки " << nameBicycle << " для вело прогулки по городу или парку" << endl;
	}
};
class children_bicycle : public bicycle
{

public:
	children_bicycle(string name) : bicycle(name, 1, 1) {};
	void DisplaySpecifications() const override
	{
		cout << "Детский велосипед. Характеристики: " << endl;
		cout << "\t Название: " << nameBicycle << endl;
		cout << "\t Количество сидушек: " << seatCount << endl;
		cout << "\t Количество скоростей: " << speedCount << endl;
	}
	void UseVehicle() const override
	{
		cout << "Использовать велоспид марки " << nameBicycle << " для обучения и катания своего ребенка" << endl;
	}
};
// Подклас автосредство с подклассами различных видов
class automobile : public vehicle
{
protected:
	string nameBrand{};
	int seatCount{};
	int maxSpeed{};
	string colorAutomobile{};
public:
	automobile(string name, int seat, int maxspeed, string color) : nameBrand{name}, seatCount{seat}, maxSpeed{maxspeed}, colorAutomobile{color} {}
	void ServiceVehicle() const override
	{
		cout << "Обслуживание: проверка давления в шинах, проверка уровня масла, внешняя проверка на наличие неисправнгостей." << endl;
	}
};
class automobile_car : public automobile
{

public:
	automobile_car(string name, int seat, int maxspeed, string color) : automobile(name, seat, maxspeed, color){}
	void DisplaySpecifications() const override
	{
		cout << "Легковой автомобиль. Характеристики: " << endl;
		cout << "\t Бренд: " << nameBrand << endl;
		cout << "\t Количество пассажирских мест: " << seatCount << endl;
		cout << "\t Максимальная скоростей: " << maxSpeed << endl;
		cout << "\t Цвет кузова: " << colorAutomobile << endl;
	}
	void UseVehicle() const override
	{
		cout << "Использовать легковой автомобиль марки " << nameBrand << " для езды на по городу" << endl;
	}
};
class automobile_bus : public automobile
{

public:
	automobile_bus(string name, int seat, int maxspeed, string color) : automobile(name, seat, maxspeed, color) {}
	void DisplaySpecifications() const override
	{
		cout << "Автобус. Характеристики: " << endl;
		cout << "\t Бренд: " << nameBrand << endl;
		cout << "\t Количество пассажирских мест: " << seatCount << endl;
		cout << "\t Максимальная скоростей: " << maxSpeed << endl;
		cout << "\t Цвет кузова: " << colorAutomobile << endl;
	}
	void UseVehicle() const override
	{
		cout << "На автобусе " << nameBrand << " развозить людей по городу" << endl;
	}
};
class automobile_truck : public automobile
{
	
public:
	automobile_truck(string name, int seat, int maxspeed, string color) : automobile(name, seat, maxspeed, color) {}
	void DisplaySpecifications() const override
	{
		cout << "Грузовик. Характеристики: " << endl;
		cout << "\t Бренд: " << nameBrand << endl;
		cout << "\t Количество пассажирских мест: " << seatCount << endl;
		cout << "\t Максимальная скоростей: " << maxSpeed << endl;
		cout << "\t Цвет кузова: " << colorAutomobile << endl;
	}
	void UseVehicle() const override
	{
		cout << "Использовать грузовик марки " << nameBrand << " для перевоза вещей" << endl;
	}
};