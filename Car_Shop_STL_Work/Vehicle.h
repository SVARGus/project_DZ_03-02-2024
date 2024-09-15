#pragma once
#include <iostream>
#include "Product.h" 

using std::cin;
using std::endl;
using std::cout;
using std::string;

class Vehicle : public Product
{
	// Базовые характеристики
	string VehicleTupe{};
	string Brand{};
	string Model{};
	string Color{};
	int NumSeat{};
	int EngineVolume{};
	double Price{};
	int CountProduct{};
	// Дополнительные характеристики
	string BodyType{}; // Тип кухова // Подумать как сделать тип кузова через enum

public:


	string getVehicleTupe() const override { return VehicleTupe; }
	string getBrand() const override { return Brand; }
	string getModel() const override { return Model; }
	string getColor() const override { return Color; }
	int getNumSeat() const override { return NumSeat; }
	int getEngineVolume() const override { return EngineVolume; }
	double getPrice() const override { return Price; }
	int getCountProduct() const override { return CountProduct; }
	string getBodyType() const { return BodyType; }

	void setPrice(const double Pr) override { this->Price = Price; }

	bool operator== (const Product& other) const override; // Продумать как реализовать данный оператор в .срр файле
	bool operator< (const Product& other) const override; // Продумать как реализовать данный оператор в .срр файле
	bool operator+ (const Product& other) override; // Продумать как реализовать данный оператор в .срр файле // может отказаться от данного оператора в пользу метода сложения в классе автосалона??
	void print() const override;
};

