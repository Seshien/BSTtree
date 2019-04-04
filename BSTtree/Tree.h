#pragma once
#include "pch.h"


class Tree
{
public:


	Tree();
	Tree(const std::vector<int> & arr, bool avl = false);

	Node * findMax();
	Node * findValue(int value);

	void deleteNode(int value);
	void deleteManyNodes(int n, const std::vector<int> & values);

	//
	void inOrder();
	void preOrder();
	void postOrderDelete();

	void showSubTree();
	//

	void balance();

private:

	void createNonAVL(const std::vector<int> & arr);

	std::vector<std::unique_ptr<Node>> _nodes;
	int height;
};