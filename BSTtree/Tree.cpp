#include "pch.h"

Tree::Tree()
{
}

Tree::Tree(const std::vector<int>& arr, bool avl)
{
	if (avl == false)
	{
		this->createNonAVL(arr);
		_AVL = false;
	}
	else
	{
		this->createAVL(arr);
		_AVL = true;
	}
}

void Tree::createNonAVL(const std::vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		this->addNode(arr[i]);
	}
}

void Tree::createAVL(const std::vector<int>& arr)
{
}

void Tree::addNodeToNode(Node * node, Node * root)
{
	if (node->value > root->value)
	{
		if (root->right == nullptr)
			root->right = node;
		else
			this->addNodeToNode(node, root->right);
	}
	else
	{
		if (root->left == nullptr)
			root->left = node;
		else
			this->addNodeToNode(node, root->left);
	}
}

void Tree::addNode(int value)
{
	std::unique_ptr<Node> node;
	auto n = node.get();
	n->value = value;

	if (_root == nullptr)
		_root = n;
	else
		this->addNodeToNode(n, _root);

	_nodes.push_back(std::move(node));
}
