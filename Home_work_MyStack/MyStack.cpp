#include "MyStack.h"

void MyStack::Push(char s) {
	if (!IsFull())
	{
		str[++top] = s;
	}
	else
	{
		//сюда можно вставить поимку исключений на переполнение очереди
	}
}
char MyStack::Pop() {
	if (!IsEmpty())
		return str[top--];
	else
		return 0;
}
void MyStack::Clear() {
	top = empty;
}
bool MyStack::IsEmpty() {
	return top == empty;
}
bool MyStack::IsFull() {
	return top == full;
}
int MyStack::GetCount() {
	return top + 1;
}