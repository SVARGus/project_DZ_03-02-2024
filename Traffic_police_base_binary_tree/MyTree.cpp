#include "MyTree.h"

void MyTree::Print(BaseViolationsCar* node) {
	if (node != 0)
	{
		Print(node->left);
		node->Print(); // пока не реализова данный метод
		cout << "------------------------------------------------------------" << endl;
		Print(node->right);
	}
}
void MyTree::Print(BaseViolationsCar* node1, BaseViolationsCar* node2) {
	if (node1 == nullptr)
		return;
	if (node1 > node2)
		return;
	if (node1 <= node2)
	{
		Print(node1->left, node2);
		node1->Print(); // пока не реализова данный метод
		cout << "------------------------------------------------------------" << endl;
		Print(node1->right, node2);
	}
}
BaseViolationsCar* MyTree::Search(BaseViolationsCar* node, string* key) {
	while (node != nullptr && *node != *key)
	{

	}
}