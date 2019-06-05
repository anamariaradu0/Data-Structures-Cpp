#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

#include "BinaryTree.h"

template <typename T>
bool checkSameLevelLeaves(BinaryTree<T> bt) {
	// TODO
	return true;
}

template <typename T>
bool isBalanced(BinaryTree<T> bt) {
	// TODO
	return true;
}

template <typename T>
bool checkChildrenSum(BinaryTree<T> bt) {
	// TODO
	BinaryTreeNode<T> *root = bt.getRoot();
	if (root->getData() == bt.getSumChildren(root)) {
		return true;
	}
	return false;
}

template <typename T>
int computeTreeHeight(BinaryTree<T> bt) {
	// TODO
	return 0;
}

int main() {
	// Create empty binary tree
	BinaryTree<int> bt;
	/*
	// Insert data
	for (int i = 0; i < 10; ++i) {
		bt.insert(i);
	}

	// Print Ex2
	freopen("Out/Lab8/traversal.out", "w", stdout);
	std::vector<int> traversal = bt.traversal();
	for (auto node : traversal) {
		std::cout << node << " ";
	}

	// Check Ex3:sameLevelLeaves
	freopen("Out/Lab8/leaves.out", "w", stdout);
	bool sameLevel = checkSameLevelLeaves(bt);
	std::cout << sameLevel << '\n';
	for (int i = 10; i < 15; ++i) {
		bt.insert(i);
	}
	sameLevel = checkSameLevelLeaves(bt);
	std::cout << sameLevel << '\n';

	// Check Ex3:isBalanced
	freopen("Out/Lab8/balanced.out", "w", stdout);
	bool balanced = isBalanced(bt);
	std::cout << balanced << '\n';
	bt.insert(0);
	std::cout << balanced << '\n';

	// Check Ex3:computeTreeHeight
	freopen("Out/Lab8/height.out", "w", stdout);
	int height = computeTreeHeight(bt);
	std::cout << height << '\n';
	for (int i = 0; i < 10; ++i) {
		bt.insert(i);
	}
	height = computeTreeHeight(bt);
	std::cout << height << '\n';

	// Check Ex3:checkChildrenSum
	freopen("Out/Lab8/childrensum.out", "w", stdout);
	bool check = checkChildrenSum(bt);
	std::cout << check << '\n';
	
	BinaryTree<int> bt1;
	bt1.insert(10);
	bt1.insert(5);
	bt1.insert(5);
	/*for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < pow(2, i); ++j) {
			bt1.insert(pow(2, 10 - i));
		}
	}

	check = checkChildrenSum(bt1);
	std::cout << check << '\n';
	*/
	return 0;
}