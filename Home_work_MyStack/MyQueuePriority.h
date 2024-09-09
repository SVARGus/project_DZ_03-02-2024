#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::swap;

template<class T>
class MyQueuePriority
{
	T* wait; // в шаблоне это будет объект с пользователем и со всей информацией
	int* priority; // приоритет
	int maxQueueLength;
	int queueLength;
public:
	MyQueuePriority(int maxQueueLength) : maxQueueLength{ maxQueueLength }, queueLength{ 0 } { wait = new T[this->maxQueueLength]; priority = new int[this->maxQueueLength]; }
	~MyQueuePriority() { delete[] wait; delete[] priority; }
	void add(T wai, int pri);
	T extract();
	void clear() { queueLength = 0; }
	bool isEmpty() const { return queueLength == 0; }
	bool isFull() const { return maxQueueLength == queueLength; }
	int getCount() const { return queueLength; }
	void show() const;
};
template<class T>
void MyQueuePriority<T>::add(T wai, int pri) {
	if (!isFull())
	{
		int i{};
		for (i = queueLength-1; (i >= 0 && priority[i] > pri); --i)
		{
			wait[i + 1] = wait[i];
			priority[i + 1] = priority[i];
		}
		wait[i + 1] = wai;
		priority[i + 1] = pri;
		queueLength++;
	}
	else
	{
		throw std::exception("Очередь переполнена");
	}
}
template<class T>
T MyQueuePriority<T>::extract() {
	if (!isEmpty())
	{
		T temp = wait[0];
		for (int i = 1; i < queueLength; i++)
		{
			wait[i - 1] = wait[i];
			priority[i - 1] = priority[i];
		}
		queueLength--;
		return temp;
	}
	else
	{
		throw std::exception("Очередь пуста!!!");
	}
}
template<class T>
void MyQueuePriority<T>::show() const {
	for (int i = 0; i < queueLength; i++)
	{
		cout << wait[i] << endl;
	}
}

