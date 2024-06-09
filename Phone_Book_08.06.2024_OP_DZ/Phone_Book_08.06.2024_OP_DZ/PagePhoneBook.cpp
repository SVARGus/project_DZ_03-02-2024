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