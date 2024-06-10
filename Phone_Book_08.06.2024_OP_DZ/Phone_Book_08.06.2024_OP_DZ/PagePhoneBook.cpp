#include "PagePhoneBook.h"

void PagePhoneBook::setFirstName(char* name) {
	int Size = strlen(name) + 1;
	FirstName = new char[Size];
	strcpy(FirstName, name);
}
void PagePhoneBook::setMiddleName(char* name) {
	int Size = strlen(name) + 1;
	MiddleName = new char[Size];
	strcpy(MiddleName, name);
}
void PagePhoneBook::setLastName(char* name) {
	int Size = strlen(name) + 1;
	LastName = new char[Size];
	strcpy(LastName, name);
}
void PagePhoneBook::setHomePhone(char* phone) {
	int Size = strlen(phone) + 1;
	HomePhone = new char[Size];
	strcpy(HomePhone, phone);
}
void PagePhoneBook::setWorkPhone(char* phone) {
	int Size = strlen(phone) + 1;
	WorkPhone = new char[Size];
	strcpy(WorkPhone, phone);
}
void PagePhoneBook::setCellPhone(char* phone) {
	int Size = strlen(phone) + 1;
	CellPhone = new char[Size];
	strcpy(CellPhone, phone);
}
void PagePhoneBook::setEmail(char* email) {
	int Size = strlen(email) + 1;
	Email = new char[Size];
	strcpy(Email, email);
}
void PagePhoneBook::setBirth(unsigned short& day, unsigned short& mounth, unsigned short& year) {
	BirthDay = day;
	BirthMounth = mounth;
	BirthYear = year;
}
void PagePhoneBook::setAddress(char* address) {
	int Size = strlen(address) + 1;
	Address = new char[Size];
	strcpy(Address, address);
}
void PagePhoneBook::setComment(char* comment) {
	int Size = strlen(comment) + 1;
	Comment = new char[Size];
	strcpy(Comment, comment);
}

PagePhoneBook::PagePhoneBook(){
}