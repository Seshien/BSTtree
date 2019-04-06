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

	void addNode(int value);

	void createNonAVL(const std::vector<int> & arr);
	void createAVL(const std::vector<int> & arr);

	//
	void inOrder();

	void preOrder();

	void postOrderDelete();

	void showSubTree();
	//

	void balance();

private:



	void addNodeToNode(Node* node, Node * root);
	void _inOrder(Node* node);
	void _preOrder(Node* node);
	std::vector<std::unique_ptr<Node>> _nodes;
	Node * _root = nullptr;
	bool _AVL = false;
};