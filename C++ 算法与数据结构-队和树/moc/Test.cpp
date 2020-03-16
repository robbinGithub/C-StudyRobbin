#include <iostream>
#include <string>
#include "BST.cpp"

using namespace std;

int main_test() {
	std::cout << "Hello, World!" << std::endl;
	BST<string, int>*  bst = new BST<string, int>();

	bst->insert("robbin1", 1);
	bst->insert("robbin2", 2);
	bst->insert("robbin3", 3);
	bst->insert("robbin4", 4);
	bst->insert("robbin5", 5);

	std::cout << "robbbin2:" << bst->size() << endl;

	int *value = bst->search("robbin2");
	std::cout << "robbbin2:" << *value << endl;
	std::cout << "robbbin2:" << bst->size() << endl;

	bst->inOrder();
	bst->remove("robbin4");
	bst->inOrder();

	system("pause");

	return 0;

}