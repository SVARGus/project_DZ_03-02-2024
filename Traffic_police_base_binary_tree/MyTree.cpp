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
void MyTree::Print(string* key1, string* key2) { 
	BaseViolationsCar* node = root;
	if (node != 0 && *key1 <= *key2)
	{
		Print(node->left);
		if (node->carNumber >= *key1 && node ->carNumber <= *key2) // Заменил *node == *key
		{
			node->Print();
			cout << "------------------------------------------------------------" << endl;
		}
		Print(node->right);
	}
}
BaseViolationsCar* MyTree::Search(string* key) {
	return Search(root, key);
}
BaseViolationsCar* MyTree::Search(BaseViolationsCar* node, string* key) { // Заменил *node == *key - в итоге операторы сравнения не надо перегружать для сравнения класса со стрингом, но тогда не смогу шобланизировать, позже можно попробовать
	while (node != nullptr)
	{
		if (node->carNumber == *key) // при нахождении сразу выходим
			return node;
		if (node->carNumber > *key)
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
	if (z != nullptr)
	{
		BaseViolationsCar* y = nullptr;
		BaseViolationsCar* node = nullptr;
		if (z->left == nullptr || z->right == nullptr)
			y = z;
		else
			y = Next(z);

		if (y->left != nullptr)
			node = y->left;
		else
			node = y->right;

		if (node != nullptr)
			node->parent = y->parent;

		if (y->parent == nullptr)
			root = node;
		else if (y == y->parent->left)
			y->parent->left = node;
		else
			y->parent->right = node;

		if (y != z)
			z = y;

		delete y;
	}
	else
	{
		while (root != nullptr)
			Dell(root);
	}
}