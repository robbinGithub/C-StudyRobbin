#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

//
// Created by Administrator on 2019/10/26 0026.
//
template <typename Key, typename Value>
class BST
{
private:
	struct Node {
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}

		Node(Node *node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};
	Node *root;
	int count = 0;
public:
	BST() {
		root = NULL;
		count = 0;
	}
	~BST() {
		// TODO: ~BST()
	}

	void preOrder() {

	}

	void inOrder() {
		inOrder(root);
	}
	void posOrder() {
	}
	Value* search(Key key)
	{
		return search(root, key);
	}
	bool contain(Key key) {
		return false;
	}
	void insert(Key key, Value value)
	{
		root = insert(root, key, value);
	}
	// 从二叉树中删除最小值所在节点
	void removeMin() {
		if (root)
			root = removeMin(root);
	}

	// 从二叉树中删除键值为key的节点
	void remove(Key key) {
		root = remove(root, key);
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}
private:
	Node * maximum(Node *node)
	{
		if (node->right == NULL)
		{
			return node;
		}

		return minimum(node->right);
	}
	Node * minimum(Node *node)
	{
		if (node->left == NULL)
		{
			return node;
		}

		return minimum(node->left);
	}

	// 删除掉以node为根的二分搜索树中的最大节点
	// 返回删除节点后新的二分搜索树的根
	Node* removeMax(Node* node) {
		if (node->right == NULL)
		{
			delete node;
			count--;
		}

		node->right = removeMax(node->right);
		return node;
	}

	Node* removeMin(Node* node) {
		if (node->left == NULL)
		{
			delete node;
			count--;
			return node->right;
		}

		node->left = removeMin(node->left);
		return node;
	}
	Node * remove(Node *node, Key key) {
		if (node == NULL)
		{
			return NULL;
		}

		if (key < node->key) {
			node->left = remove(node->left, key);
			return node;
		}
		else if (key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}
		else if (node->key == key) {
			Node *rightNode = node->right;
			if (node->left == NULL) {
				delete node;
				count--;
				return rightNode;
			}

			if (node->right == NULL)
			{
				delete node;
				count--;
				return node->left;
			}

			// 查找Node的后继结点为successor
			Node *successor = new Node(minimum(node->right));;
			count++;

			successor->left = node->left;
			successor->right = removeMin(node->right);

			delete node;
			count--;

			return successor;
		}
	}

	Node *insert(Node *node, Key key, Value value) {
		if (node == NULL) {
			count++;
			return new Node(key, value);
		}
		if (node->key == key) {
			node->value = value;
		}
		else if (node->key > key) {
			node->left = insert(node->left, key, value);
		}
		else if (node->key < key) {
			node->right = insert(node->right, key, value);
		}

		return node;

	}

	Value *search(Node *node, Key key) {
		if (node == NULL) {
			return NULL;
		}
		if (node->key == key) {
			return &node->value;
		}
		else if (node->key < key) {
			return search(node->right, key);
		}
		else if (node->key > key) {
			return search(node->left, key);
		}
	}

	void inOrder(Node *node) {
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->value;
			inOrder(node->right);
		}
	}
};

