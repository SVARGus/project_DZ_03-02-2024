#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Надо шаблонизировать очередь чтоб мог принимать различнве объекты (например объект пассажир с временем когда встал в очередь и когда покинул очередь)
template<class T>
class MyQueue
{
	T* wait;
	int maxQueueLength;
	int queueLength;
public:
	MyQueue(int maxQueueLength) : maxQueueLength{ maxQueueLength }, queueLength{0} { wait = new T[this->maxQueueLength]; }
	~MyQueue() { delete[]wait; }
	void Add(T x);
	int Extract();
	void Clear() { queueLength = 0; }
	bool IsEmpty() { return queueLength == 0; }
	bool IsFull() { return queueLength == maxQueueLength; }
	int GetCount() { return queueLength; }
	void Show() const;
};
template<class T>
void MyQueue<T>::Add(T x) {
	if (!IsFull())
		wait[queueLength++] = x;
	else
	{
		// добавить ловушку исключений на случай переполнения
	}
}
template<class T>
int MyQueue<T>::Extract() {
	if (!IsEmpty())
	{
		T temp = wait[0];
		for (int i = 1; i < queueLength; i++)
			wait[i - 1] = wait[i];
		queueLength--;
		return temp;
	}
	else
		return -1;
}
template<class T>
void MyQueue<T>::Show() const {
	cout << "\n------------------------\n";
	for (int i = 0; i < queueLength; ++i)
	{
		cout << wait[i] << " ";
	}
	cout << "\n------------------------\n";
}

