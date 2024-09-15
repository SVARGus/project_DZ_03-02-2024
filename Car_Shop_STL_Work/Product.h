#pragma once
#include <iostream>

using std::cin;
using std::endl;
using std::cout;
using std::string;

// Виртуальный класс Продукт для других подкласов как Машина, Мотоцикл, Грузовик и прочие

class Product
{
public:
	// Геттеры для вывода информации о транспортном средстве
	virtual string getVehicleTupe() const = 0; // Тип транспортного средства: Автомобиль, мотоцикл, грузовик
	virtual string getBrand() const = 0; // Бренд ТС
	virtual string getModel() const = 0; // Модель ТС
	virtual string getColor() const = 0; // Цвет ТС
	virtual int getNumSeat() const = 0; // Количество мест в ТС
	virtual int getEngineVolume() const = 0; // Объем двигателя ТС
	virtual double getPrice() const = 0; // Вывод цены ТС
	virtual int getCountProduct() const = 0; // Количество ТС в наличии

	// Сеттеры для изменения переменных
	virtual void setPrice(const double Price) = 0; // Для изменения цены товара (например в случае скидки или после покупки ТС для последующей перепродажи)

	// Булевские операторы сравнения
	virtual bool operator== (const Product& other) const = 0; // оператор перегружен для сортировки
	virtual bool operator< (const Product& other) const = 0; // оператор перегружен для сортировки
	virtual bool operator+ (const Product& other) = 0; // оператор сложения, будет по факту увеличивать количество ТС в автосалоне, но при условии если данное ТС уже есть в базе автосалона. Если ТС нету, то будет произведено добавление в базу

	// Методы вывода
	virtual void print() const = 0; // Вывод на печать

	// Виртуальный деструктор
	virtual ~Product() = default;
};

