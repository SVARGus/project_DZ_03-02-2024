#include "mystring.h"
#include <iostream>

//mystring::mystring(){}

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

void mystring::remove() // можно или лучше нужно добавить в приватную часть
{
	if (mString != nullptr)
	{
		delete[] mString;
		size = 0;
	}
}

mystring operator+ (const mystring& name1, const mystring& name2) // OK
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
	//mystring::setStaticCount();
	return name3;
}

mystring operator+ (const mystring& name1, const char* name2) // OK
{
	mystring name3;
	name3.size = name1.size + strlen(name2);
	name3.mString = new char[name3.size + 1];
	for (int i = 0, j = 0; i <= name3.size; ++i)
	{
		if (i < name1.size)
			name3.mString[i] = name1.mString[i];
		else
		{
			name3.mString[i] = name2[j];
			++j;
		}
	}
	return name3;
}

mystring operator+ (const char* name1, const mystring& name2) // OK
{
	mystring name3;
	name3.size = strlen(name1) + name2.size;
	name3.mString = new char[name3.size + 1];
	for (int i = 0, j = 0; i <= name3.size; ++i)
	{
		if (i < strlen(name1))
			name3.mString[i] = name1[i];
		else
		{
			name3.mString[i] = name2.mString[j];
			++j;
		}
	}
	return name3;
}

mystring mystring::operator= (const mystring& name) // OK
{
	if (this == &name)
		return *this;
	remove();
	size = name.size;
	mString = new char[size + 1];
	for (int i = 0; i <= size; ++i)
		mString[i] = name.mString[i];
	//mystring(name);
	return *this;
}

mystring mystring::operator= (const char* name) // OK
{
	remove();
	size = strlen(name);
	mString = new char[size + 1];
	for (int i = 0; i <= size; ++i)
		mString[i] = name[i];
	return *this;
}

bool mystring::operator== (const mystring& name) const // ОК 
{
	if (strlen(mString) != strlen(name.mString))
		return false;
	for (int i = 0; i < size; ++i)
	{
		if (mString[i] != name.mString[i])
			return false;
	}
	return true;
}

char mystring::operator[] (int index) const // только для вывода символа, нельзя его изменить в строке (get) // OK
{
	if (index < 0 || index >= size)
	{
		std::cout << "Вы выпали за строку, программа аварийно завершена" << std::endl;
		abort();
	}
	return mString[index];
}

char& mystring::operator[] (int index) // для внесения изменений в строку по индексу // OK
{
	if (index < 0 || index >= size)
	{
		std::cout << "Вы выпали за строку, программа аварийно завершена" << std::endl;
		abort();
	}
	return mString[index];
}

std::istream& operator>> (std::istream& input, mystring& name) // нужно проверить!!!
{
	/*name.remove();
	const int bSize = 101;
	char buffer[bSize];
	input >> buffer;
	name.size = strlen(buffer);
	name.mString = new char[name.size + 1];
	name.mString = buffer;*/
	name.remove();
	name.size = 100;
	name.mString = new char[name.size + 1];
	char mName[101];
	std::cin >> mName;
	name = mName;
	return input;
}

void mystring::print() const // ОК
{
	std::cout << mString << " " << size << " " << strlen(mString) << " Счетчик = " << count << std::endl;

}