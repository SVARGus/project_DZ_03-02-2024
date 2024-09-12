#include "MyTree.h"

void MyTree::Print() {
	Print(root);
	cout << endl;
}
void MyTree::Print(BaseViolationsCar* node) { 
	if (node != nullptr)
	{
		Print(node->left);
		node->Print(); 
		cout << "------------------------------------------------------------" << endl;
		Print(node->right);
	}
}
void MyTree::Print(const string* key1, const string* key2) {
	Print(key1, key2, root);
}
void MyTree::Print(const string* key1, const string* key2, BaseViolationsCar* node) {
	if (node != nullptr && *key1 <= *key2)
	{
		Print(key1, key2, node->left);
		if (*node >= *key1 && *node <= *key2) 
		{
			node->Print();
			cout << "------------------------------------------------------------" << endl;
		}
		Print(key1, key2, node->right);
	}
}
BaseViolationsCar* MyTree::Search(const string* key) {
	return Search(root, key);
}
BaseViolationsCar* MyTree::Search(BaseViolationsCar* node, const string* key) {
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
void MyTree::Add(BaseViolationsCar* z) { // Разобрался почему не работал должным образом оператор сравнения, забыл просто разыменовать
	z->left = nullptr;
	z->right = nullptr;
	BaseViolationsCar* y = nullptr;
	BaseViolationsCar* node = root;
	while (node != nullptr)
	{
		y = node;
		if (*z > *node)
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
	else if (*z > *y)
		y->right = z;
	else
		y->left = z;
}
void MyTree::Dell(BaseViolationsCar* z) { // метод реализован из методички, позже был переделан в свой более удобный метод
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
void MyTree::MyDell_sheet(BaseViolationsCar* z) {
	if (z->parent->left == z)
		z->parent->left = nullptr;
	else
		z->parent->right = nullptr;
}
void MyTree::MyDell_onesheet(BaseViolationsCar* z) { // если у удаляемого есть только один лист
	if (z->left)
	{
		z->left->parent = z->parent;
		if (z->parent->left == z)
			z->parent->left = z->left;
		else
			z->parent->right = z->left;
	}
	if (z->right)
	{
		z->right->parent = z->parent;
		if (z->parent->left == z)
			z->parent->left = z->right;
		else
			z->parent->right = z->right;
	}
}
void MyTree::MyDell(BaseViolationsCar* z) {
	if (!z->left && !z->right) // если удаляемый элемент является листом
	{
		MyDell_sheet(z);
		delete z;
		return;
	}
	if (!z->left || !z->right) // если удаляем элемент с одним листом.
	{
		MyDell_onesheet(z);
		delete z;
		return;
	}
	// удаляем вершину, в том числе если это корень, делаем перепривязку адресов для возможности в дальнейшем шаблонизировать
	BaseViolationsCar* min_node = Min(z->right);
	if (min_node->right) 
	{
		min_node->parent->left = min_node->right;
		min_node->right->parent = min_node->parent;
	}
	min_node->right = z->right;
	min_node->left = z->left;
	if (!z->parent) // если удаляемый элемент является корнем
	{
		root = min_node;
		min_node->parent = nullptr;
	}
	else
	{
		min_node->parent = z->parent;
		if (z->parent->right == z)
			z->parent->right == min_node;
		else
			z->parent->left == min_node;
	}
	delete z;
}

void MyTree::ClearTree() {
	ClearTree(root);
	root = nullptr;
}
void MyTree::ClearTree(BaseViolationsCar* node) {
	ClearTree(node->left);
	ClearTree(node->right);
	delete node;
}