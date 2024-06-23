#include "mystring.h"
#include <iostream>

mystring::mystring(){}

mystring::mystring(char* name) // ОК
{
	size = strlen(name);
	mString = new char[size + 1];
	for (int i = 0; i <= size; i++)
		mString[i] = name[i];
	++count;
}

mystring::mystring(const mystring& name) : size{ name.size }, mString{ new char[size + 1] {} } // OK
{
	for (int i = 0; i <= size; ++i)
		this->mString[i] = name.mString[i];
	++count;
}

mystring::~mystring() // ОК
{
	delete[] mString;
	--count;
	std::cout << "Строка удалена, счетчик = " << count << std::endl;
}

void mystring::setmString(char* name) // OK
{
	size = strlen(name);
	mString = new char[size + 1];
	for (int i = 0; i <= size; ++i)
		mString[i] = name[i];
}

mystring operator+ (const mystring& name1, const mystring& name2)
{
	mystring name3;
	name3.size = name1.size + name2.size;
	name3.mString = new char[name3.size + 1];
	for (int i = 0, j = 0; i <= name3.size; ++i)
	{
		if (i < name1.size)
			name3.mString[i] = name1.mString[i];
		else
		{
			name3.mString[i] = name2.mString[j];
			++j;
		}
	}
	mystring::setStaticCount();
	return name3;
}

void mystring::print() const // ОК
{
	std::cout << mString << " " << size << " " << strlen(mString) << " Счетчик = " << count << std::endl;

}