#pragma once
#include "pch.h"


class Tree
{
public:

	Tree();
	Tree(const std::vector<int> & arr, bool avl = false);

	Node * findMax();

	void deleteNode(int value);
	void deleteManyNodes(const std::vector<int> & values);

	void addNode(int value);

	void createNonAVL(const std::vector<int> & arr);
	void createAVL(const std::vector<int> & arr);

	//
	void inOrder();

	void preOrder();

	void postOrderDelete();

	void showSubTree(int value);
	Node * findValue(int value);
	//

	void balance();


private:

	void addNodeToNode(Node* node, Node * root);
	void avlNext(const std::vector<int>::const_iterator & beg, const std::vector<int>::const_iterator & end);

	void _inOrder(Node* node);
	void _preOrder(Node* node);
	void _postOrder(Node* node);

	Node * _findValue(Node* node, int value);

	std::vector<std::unique_ptr<Node>> _nodes;
	Node * _root = nullptr;
	bool _AVL = false;
};