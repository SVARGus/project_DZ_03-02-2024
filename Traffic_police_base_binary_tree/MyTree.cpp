#include "MyTree.h"

void MyTree::Print() {
	Print(root);
	cout << endl;
}
void MyTree::Print(BaseViolationsCar* node) { // вывод всего дерева, но при условии если передан сам корень, а не с конкретного узла
	if (node != 0)
	{
		Print(node->left);
		node->Print(); 
		cout << "------------------------------------------------------------" << endl;
		Print(node->right);
	}
}
void MyTree::Print(BaseViolationsCar* node1, BaseViolationsCar* node2) { // Нужно перепроверить корректность работы если node1 в левой ветке, а node2 в правой ветке
	if (node1 == nullptr || node1 == nullptr) // если хпервый нод нулевой - значит дерево пустое, если второй нод пустой - значит не верно переданы данные и не будет произведен вывод
		return;
	if (node1 > node2)
		return;
	if (node1 <= node2)
	{
		Print(node1->left, node2);
		node1->Print(); 
		cout << "------------------------------------------------------------" << endl;
		Print(node1->right, node2);
	}
}
BaseViolationsCar* MyTree::Search(string* key) {
	return Search(root, key);
}
BaseViolationsCar* MyTree::Search(BaseViolationsCar* node, string* key) {
	while (node != nullptr)
	{
		if (*node == *key) // при нахождении сразу выходим
			return node;
		if (*node > *key)
			return Search(node->left, key);
		else
			return Search(node->right, key);
	}
	return nullptr;
}
BaseViolationsCar* MyTree::Min() {
	return Min(root);
}
BaseViolationsCar* MyTree::Min(BaseViolationsCar* node) {
	if (node != nullptr)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
	}
	return node;
}
BaseViolationsCar* MyTree::Max() {
	return Max(root);
}
BaseViolationsCar* MyTree::Max(BaseViolationsCar* node) {
	if (node != nullptr)
	{
		while (node->right != nullptr)
		{
			node = node->right;
		}
	}
	return node;
}
BaseViolationsCar* MyTree::Next(BaseViolationsCar* node) {
	BaseViolationsCar* y = nullptr;
	if (node != nullptr)
	{
		if (node->right != nullptr)
			return Min(node->right);
		y = node->parent;
		while (y != nullptr && node == y->right)
		{
			node = y;
			y = y->parent;
		}
	}
	return y;
}
BaseViolationsCar* MyTree::Previous(BaseViolationsCar* node) {
	BaseViolationsCar* y = nullptr;
	if (node != nullptr)
	{
		if (node->left !=nullptr)
		{
			return Max(node->left);
		}
		y = node->parent;
		while (y != nullptr && node == y->left)
		{
			node = y;
			y = y->parent;
		}
	}
	return y;
}
void MyTree::Add(BaseViolationsCar* z) {
	z->left = nullptr;
	z->right = nullptr;
	BaseViolationsCar* y = nullptr;
	BaseViolationsCar* node = root;
	while (node != nullptr)
	{
		y = node;
		if (z > node)
		{
			node = node->right;
		}
		else
		{
			node = node->left;
		}
	}
	z->parent = y;
	if (y == nullptr)
		root = z;
	else if (z > y)
		y->right = z;
	else
		y->left = z;
}
void MyTree::Dell(BaseViolationsCar* z) {
	if (z == 0)
	{

	}
	else
	{

	}
}