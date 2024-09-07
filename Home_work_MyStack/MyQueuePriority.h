#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class MyQueuePriority
{
	int* wait;
	int* priority;
	int maxQueueLength;
	int queueLength;
public:
	MyQueuePriority(int maxQueueLength) : maxQueueLength{ maxQueueLength }, queueLength{ 0 } { wait = new int[this->maxQueueLength]; priority = new int[this->maxQueueLength]; }
	~MyQueuePriority() { delete[] wait; delete[] priority; }
	void add(int wai, int pri);
	int extract();
	void clear() { queueLength = 0; }
	bool isEmpty() { return queueLength == 0; }
	bool isFull() { return maxQueueLength == queueLength; }
	int getCount() { return queueLength; }
	void show() const;
};
void MyQueuePriority::add(int wai, int pri) {
	if (!isFull)// необходимо переделать очередь с приоритетным включением, сейчас отсутствует приоритет
	{
		wait[queueLength] = wai;
		priority[queueLength] = pri;
		queueLength++;
	}
	else
	{
		//сюда можно добавить исключение если очередь переполнена
	}
}
int MyQueuePriority::extract() {
	if (!isEmpty) // реализовать выход из очереди после пределки в очередь с приоритетом включения
	{

	}
}
void MyQueuePriority::show() const {
	// Реализовать печать, а в передаваймом классе попробовать перегрузить метод вывода что очередь могла их тоже печатать
}

