#include "MyTree.h"

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
BaseViolationsCar* MyTree::Search(BaseViolationsCar* node, string* key) {
	while (node != nullptr)
	{
		if (*node == *key) // при нахождении сразу выходим
		{
			return node;
		}

		Search(node->left, key);
		Search(node->right, key);
	}
	return nullptr;
}