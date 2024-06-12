#include "PagePhoneBook.h"

#pragma warning(disable:4996)
void PagePhoneBook::setFirstName(char* name) {
	if (FirstName != nullptr)
		delete[] FirstName;
	int Size = strlen(name) + 1;
	FirstName = new char[Size];
	strcpy(FirstName, name);
}
void PagePhoneBook::setMiddleName(char* name) {
	if (MiddleName != nullptr)
		delete[] MiddleName;
	int Size = strlen(name) + 1;
	MiddleName = new char[Size];
	strcpy(MiddleName, name);
}
void PagePhoneBook::setLastName(char* name) {
	if (LastName != nullptr)
		delete[] LastName;
	int Size = strlen(name) + 1;
	LastName = new char[Size];
	strcpy(LastName, name);
}
void PagePhoneBook::setHomePhone(char* phone) {
	if (HomePhone != nullptr)
		delete[] HomePhone;
	int Size = strlen(phone) + 1;
	HomePhone = new char[Size];
	strcpy(HomePhone, phone);
}
void PagePhoneBook::setWorkPhone(char* phone) {
	if (WorkPhone != nullptr)
		delete[] WorkPhone;
	int Size = strlen(phone) + 1;
	WorkPhone = new char[Size];
	strcpy(WorkPhone, phone);
}
void PagePhoneBook::setCellPhone(char* phone) {
	if (CellPhone != nullptr)
		delete[] CellPhone;
	int Size = strlen(phone) + 1;
	CellPhone = new char[Size];
	strcpy(CellPhone, phone);
}
void PagePhoneBook::setEmail(char* email) {
	if (Email != nullptr)
		delete[] Email;
	int Size = strlen(email) + 1;
	Email = new char[Size];
	strcpy(Email, email);
}
void PagePhoneBook::setBirth(unsigned short& day, unsigned short& mounth, unsigned short& year) {
	if (day > 0 && day <= 31)
		BirthDay = day;
	else
		BirthDay = 0;
	if (mounth > 0 && mounth <=  12)
		BirthMounth = mounth;
	else
		BirthMounth = 0;
	if (year > 0)
		BirthYear = year;
	else
		BirthYear = 0;
}
void PagePhoneBook::setAddress(char* address) {
	if (Address != nullptr)
		delete[] Address;
	int Size = strlen(address) + 1;
	Address = new char[Size];
	strcpy(Address, address);
}
void PagePhoneBook::setComment(char* comment) {
	if (Comment != nullptr)
		delete[] Comment;
	int Size = strlen(comment) + 1;
	Comment = new char[Size];
	strcpy(Comment, comment);
}
#pragma warning(default:4996)

PagePhoneBook::PagePhoneBook() : FirstName{ nullptr }, LastName{ nullptr }, MiddleName{ nullptr }, CellPhone{ nullptr }, WorkPhone{ nullptr }, HomePhone{ nullptr }, Email{ nullptr }, BirthDay{ 0 }, BirthMounth{ 0 }, BirthYear{ 0 }, Address{ nullptr }, Comment{ nullptr } {
	std::cout << "Констуктор по умолчанию" << std::endl;
}

PagePhoneBook::PagePhoneBook(char* firstname, char* cellphone) 
	: PagePhoneBook() {
	setFirstName(firstname);
	setCellPhone(cellphone);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* cellphone) 
	: PagePhoneBook(firstname, cellphone) {
	setLastName(lastname);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone) 
	: PagePhoneBook(firstname, lastname, cellphone) {
	setMiddleName(middlename);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email) 
	: PagePhoneBook(firstname, lastname, middlename, cellphone) {
	setEmail(email);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year) 
	: PagePhoneBook(firstname, lastname, middlename, cellphone, email) {
	setBirth(day, mounth, year);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress) 
	: PagePhoneBook(firstname, lastname, middlename, cellphone, email, day, mounth, year) {
	setAddress(adress);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress) 
	: PagePhoneBook(firstname, lastname, middlename, cellphone, email, day, mounth, year, adress) {
	setWorkPhone(workphone);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress) 
	: PagePhoneBook(firstname, lastname, middlename, cellphone, workphone, email, day, mounth, year, adress) {
	setHomePhone(homephone);
}

PagePhoneBook::PagePhoneBook(char* firstname, char* lastname, char* middlename, char* cellphone, char* workphone, char* homephone, char* email, unsigned short day, unsigned short mounth, unsigned short year, char* adress, char* comment) 
	: PagePhoneBook(firstname, lastname, middlename, cellphone, workphone, homephone, email, day, mounth, year, adress) {
	setComment(comment);
}




PagePhoneBook::~PagePhoneBook() {
	delete[] FirstName;
	delete[] MiddleName;
	delete[] LastName;
	delete[] HomePhone;
	delete[] WorkPhone;
	delete[] CellPhone;
	delete[] Email;
	delete[] Address;
	delete[] Comment;
	std::cout << "Маркер деструктора" << std::endl;
	// позже дописать запись телефонной книги в отдельный файл
}