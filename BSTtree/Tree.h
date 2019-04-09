#pragma once
#include "pch.h"


class Tree
{
public:

	Tree();

	~Tree() { this->postOrderDelete(); }
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
	bool existTree();
	void showSubTree(int value);
	std::pair<Node*, Node*> findValue(int value);
	//

	void balance();


private:

	void addNodeToNode(Node* node, Node * root);
	void avlNext(const std::vector<int>::const_iterator & beg, const std::vector<int>::const_iterator & end);

	void _inOrder(Node* node);
	void _preOrder(Node* node);
	void _postOrder(Node* parent, Node* node);

	void RRotation(Node *parent);
	void LRotation(Node * parent);

	std::pair<Node*, Node*> _findValue(std::pair<Node *, Node*>, int value);

	Node * _root = nullptr;
	bool _AVL = false;
};