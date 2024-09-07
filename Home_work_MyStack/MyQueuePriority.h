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
	bool isEmpty() { return queueLength == 0; }
	bool isFull() { return maxQueueLength == queueLength; }
	int getCount() { return queueLength; }
	void show() const;
};
template<class T>
void MyQueuePriority<T>::add(T wai, int pri) {
	T waiTemp = wai;
	int priTemp = pri;
	if (isEmpty())
	{
		wait[queueLength] = wai;
		priority[queueLength] = pri;
		queueLength++;
	}
	else if (!isFull())
	{
		for (int i = 0; i <= queueLength; i++)
		{
			if (pri < priority[i]) // проверить правильность приоритета если 0 имеет больший приоритет чем 1, а 1 более чем 2 и так далее
			{
				//ТУТ ОШИБКА, нужно заменить swap на другой способ замены!!!
				swap(waiTemp, wait[i]);
				swap(priTemp, priority[i]);
			}
		}
		queueLength++;
	}
	else
	{
		//сюда можно добавить исключение если очередь переполнена
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
		//добавить поимку исключений
	}
}
template<class T>
void MyQueuePriority<T>::show() const {
	for (int i = 0; i < queueLength; i++)
	{
		cout << wait[i] << endl;
	}
}

