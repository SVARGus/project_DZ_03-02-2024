#include "HomeApartmentPerson.h"

// ћетоды ѕерсоны

Person::Person(std::string fio, int age) : fio{ fio }, age {age} {}

std::string Person::getFIO () const
{
	return fio;
}
int Person::getAge() const
{
	return age;
}
//Person Person::operator= (char* fio, signed int age) // переделать на приравнивание класса к классу
//{
//	fiosize = strlen(fio);
//	this->fio = new char[fiosize + 1];
//	for (int i = 0; i <= fiosize; i++)
//		this->fio[i] = fio[i];
//	this->age = age;
//}


// ћетоды  вартиры

Apartment::Apartment(int room) : appartNumber{count}, room {room}
{
	switch (room)
	{
	case 1:
		person = new Person[3];
		break;
	case 2:
		person = new Person[4];
		break;
	case 3:
		person = new Person[6];
		break;
	default: // надо продумать блок на случай если пользователь укажет более 3 комнат в квартире!
		break;
	}
	++count;
}



// ћетоды ƒома

Home::Home(std::string street, int numberHous, int floor, int numbeOfApartmenOnFloor, int* numRoomApartFloor) : street{ street }, numberHous { numberHous }, floor{ floor }, numbeOfApartmenOnFloor{ numbeOfApartmenOnFloor }
{
	Apartment::count = 1; // обнул€ем количество квартир в доме и при создании каждой квартиры записываем как номер квартиры начина€ с 1
	apartment = new Apartment*[this->floor];
	for (int i = 0; i < this->floor; ++i)
	{
		apartment[i] = new Apartment[this->numbeOfApartmenOnFloor];
		for (int j = 0; j < numbeOfApartmenOnFloor; ++j)
		{
			apartment[i][j] = Apartment(numRoomApartFloor[j]);
		}
	}
}
