#include "MyStack.h"

void MyStack::Push(char s) {
	if (!IsFull())
	{
		str[++top] = s;
	}
	else
	{
		throw std::exception("Стэк переполнен");
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
bool MyStack::IsEmpty() const {
	return top == empty;
}
bool MyStack::IsFull() const {
	return top == full;
}
int MyStack::GetCount() const {
	return top + 1;
}