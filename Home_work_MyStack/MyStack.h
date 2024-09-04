#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class MyStack
{
	int empty{ -1 };
	int full{ 20 };
	int top{ empty };
	char* str{};
public:
	MyStack() { str = new char[full + 1]; };
	MyStack(int full) : full{ full } { str = new char[this->full + 1]; };
	~MyStack() { delete[] str; str = nullptr; };
	void Push(char s);
	char Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
};