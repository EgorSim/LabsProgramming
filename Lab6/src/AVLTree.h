#pragma once 

#include <cassert>


class AVLTree {
private:
	struct Node
	{
		int key;
		int height;
		Node* left;
		Node* right;
		Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
	};

	Node* root;

	int height(const Node* obj) const {
		return (obj ? obj->height : 0);
	}

	int balanceFactor(const Node& obj) const {
		return (height(obj.right) - height(obj.left));
	}

	void fixHeight(Node& obj) const {
		int h1 = height(obj.left);
		int h2 = height(obj.right);
		obj.height = (h1 > h2 ? h1 : h2) + 1;
	}

	Node* rotateRight(Node& obj) {
		Node* ptr = obj.left;
		obj.left = ptr->right;
		ptr->right = &obj;
		fixHeight(obj);
		fixHeight(*ptr);
		return ptr;
	}

	Node* rotateLeft(Node& obj) {
		Node* ptr = obj.right;
		obj.right = ptr->left;
		ptr->left = &obj;
		fixHeight(obj);
		fixHeight(*ptr);
		return ptr;
	}

	Node* balance(Node* obj) {
		fixHeight(*obj);
		if (balanceFactor(*obj) == 2) {
			if (balanceFactor(*obj->right) < 0) obj->right = rotateRight(*obj->right);
			return rotateLeft(*obj);
		}
		else if (balanceFactor(*obj) == -2) {
			if (balanceFactor(*obj->left) > 0) obj->left = rotateLeft(*obj->left);
			return rotateRight(*obj);
		}
		return obj;
	}

	Node* _insert(Node* obj, int k) {
		if (!obj) return new Node(k);
		if (k < obj->key) obj->left = _insert(obj->left, k);
		else obj->right = _insert(obj->right, k);
		return balance(obj);
	}

	void _checkAllNodesBF(const Node* obj) {
		if (!obj) return;
		_checkAllNodesBF(obj->left);
		int b = balanceFactor(*obj);
		assert(b < 2 && b > -2);
		_checkAllNodesBF(obj->right);
	}

	void _printTree(Node* n, int x) {
		if (n) {
			_printTree(n->left, x + 1);
			for (size_t i = 0; i < x; ++i) std::cout << " ";
			std::cout << n->key << std::endl;
			_printTree(n->right, x + 1);
		}
	}
public:
	AVLTree() : root(nullptr) {}


	void insert(int k) {
		root = _insert(root, k);
	}

	void checkAllNodesBF() {
		_checkAllNodesBF(root);
	}

	void prinfTree() {
		_printTree(root, 0);
	}

};