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

void mystring::remove() // можно или лучше нужно добавить в приватную часть
{
	if (mString != nullptr)
	{
		delete[] mString;
		size = 0;
	}
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

mystring::mystring operator= (const mystring& name) // проверить!
{
	if (this == &name)
		return *this;
	remove();
	mystring(name);
	return *this;
}

bool mystring::operator== (const mystring& name) const
{
	if (size != name.size)
		return false;
	for (int i = 0; i < size; ++i)
	{
		if (mString[i] != name.mString[i])
			return false;
	}
	return true;
}

char mystring::operator[] (int index) const // только для вывода символа, нельзя его изменить в строке (get)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Вы выпали за строку, программа аварийно завершена" << std::endl;
		abort();
	}
	return mString[i];
}

char& mystring::operator[] (int index) // для внесения изменений в строку по индексу (set)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Вы выпали за строку, программа аварийно завершена" << std::endl;
		abort();
	}
	return mString[i];
}

std::istream& mystring::operator>> (std::istream& input, mystring& name)
{
	// как реализовать запись текста вводимого с клавиатуры в динамическую память если изначально не известно количество вводимых символов
	return input;
}

void mystring::print() const // ОК
{
	std::cout << mString << " " << size << " " << strlen(mString) << " Счетчик = " << count << std::endl;

}