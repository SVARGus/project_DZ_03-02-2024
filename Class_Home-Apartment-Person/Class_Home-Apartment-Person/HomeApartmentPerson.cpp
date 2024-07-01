#include "HomeApartmentPerson.h"

// Методы Персоны

Person::Person(char* firstname, char* lastname, signed int age)
{
	fsize = strlen(firstname);
	this->firstname = new char[fsize + 1];
	for (int i = 0; i <= fsize; i++)
		this->firstname[i] = firstname[i];
	lsize = strlen(lastname);
	this->lastname = new char[lsize + 1];
	for (int i = 0; i <= fsize; i++)
		this->lastname[i] = lastname[i];
	this->age = age;
}
char Person::getFirstName()
{
	return firstname;
}
char Person::getLastName()
{
	return lastname;
}
int Person::getAge()
{
	return age;
}
Person Person::operator= (char* firstname, char* lastname, signed int age)
{
	fsize = strlen(firstname);
	this->firstname = new char[fsize + 1];
	for (int i = 0; i <= fsize; i++)
		this->firstname[i] = firstname[i];
	lsize = strlen(lastname);
	this->lastname = new char[lsize + 1];
	for (int i = 0; i <= fsize; i++)
		this->lastname[i] = lastname[i];
	this->age = age;
}


// Методы Квартиры



// Методы Дома