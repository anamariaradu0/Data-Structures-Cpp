#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
private:
	T data;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;

public:
	BinaryTreeNode(T data) {
		// TODO 1
		this->data = data;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}

	~BinaryTreeNode() {
		// TODO 2
	}

	void setData(T data) {
		// TODO 3
		this->data = data;
	}

	T getData() {
		// TODO 4
		return this->data;
	}

	void setLeftChild(BinaryTreeNode<T> *node) {
		// TODO 5
		this->leftChild = node;
	}

	BinaryTreeNode* getLeftChild() {
		// TODO 6
		return this->leftChild;
	}

	void setRightChild(BinaryTreeNode<T> *node) {
		// TODO 7
		this->rightChild = node;
	}

	BinaryTreeNode* getRightChild() {
		// TODO 8
		return this->rightChild;
	}
};

template <typename T>
class BinaryTree {
private:
	int size;
	BinaryTreeNode<T> *root;
public:
	BinaryTree() {
		// TODO 9
		this->size = 0;
		this->root = nullptr;
		this->root->setRightChild(nullptr);
		this->root->setLeftChild(nullptr);
	}

	~BinaryTree() {
		// TODO 10
		deleteBinaryTree(root);
	}

	void deleteBinaryTree(BinaryTreeNode<T> *node) {
		BinaryTreeNode<T> *leftNode = node->getLeftChild();
		BinaryTreeNode<T> *rightNode = node->getRightChild();
		if (leftNode != nullptr) {
			deleteBinaryTree(leftNode);
		}
		if (rightNode != nullptr) {
			deleteBinaryTree(rightNode);
		}
		delete node;
	}

	void insert(T data) {
		// TODO 11: Insert node at the first empty position
		size++;
		BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
		BinaryTreeNode<T> *tempNode;
		BinaryTreeNode<T> *leftNode;
		BinaryTreeNode<T> *rightNode;
		std::queue < BinaryTreeNode<T>* > parseNodes;
		parseNodes.push(root);
		if (root == nullptr) {
			root = newNode;
			root->setData(data);
		} else {
			while(!parseNodes.empty()) {
				tempNode = parseNodes.front();
				parseNodes.pop();
				leftNode = tempNode->getLeftChild();
				rightNode = tempNode->getRightChild();
				if (leftNode == nullptr) {
					tempNode->setLeftChild(newNode);
					return;
				} else {
					parseNodes.push(leftNode);
				}
				if (rightNode == nullptr) {
					tempNode->setRightChild(newNode);
					return;
				} else {
					parseNodes.push(rightNode);
				}
			}
		}
	}

	std::vector<T> traversal() {
		// TODO 12
		std::vector<T> parseData;
		std::queue < BinaryTreeNode<T>* > parseNodes;
		BinaryTreeNode<T> *tempNode = root;
		BinaryTreeNode<T> *leftNode;
		BinaryTreeNode<T> *rightNode;
		if (tempNode != nullptr) {
			parseNodes.push(tempNode);
			while (!parseNodes.empty()) {
				tempNode = parseNodes.front();
				parseNodes.pop();
				parseData.push_back(tempNode->getData());
				leftNode = tempNode->getLeftChild();
				rightNode = tempNode->getRightChild();
				if (leftNode != nullptr) {
					parseNodes.push(leftNode);
				}
				if (rightNode != nullptr) {
					parseNodes.push(rightNode);
				}
			}
		}
		return parseData;
	}

	BinaryTreeNode<T>* getRoot() {
		return this->root;
	}

	T getSumChildren(BinaryTreeNode<T> *node) {
		return getSumChildren(node->getRightChild()) + getSumChildren(node->getLeftChild());
	}
};

#endif // __BINARYTREE_H__