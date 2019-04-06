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
		{
			root->right = node;
			node->parent = root;
		}
		else
			this->addNodeToNode(node, root->right);
	}
	else
	{
		if (root->left == nullptr)
		{
			root->left = node;
			node->parent = root;
		}
		else
			this->addNodeToNode(node, root->left);
	}
}

void Tree::addNode(int value)
{
	std::unique_ptr<Node> node = std::make_unique<Node>();
	auto n = node.get();
	n->value = value;

	if (_root == nullptr)
		_root = n;
	else
		this->addNodeToNode(n, _root);

	_nodes.push_back(std::move(node));
}

void Tree::inOrder()
{
	std::cout << "Starting inOrder" << std::endl;
	if (_root == nullptr)
		std::cout << "Tree doesn't exist." << std::endl;
	else
		this->_inOrder(_root);
}


void Tree::_inOrder(Node* node)
{
	if (node->left != nullptr)
		_inOrder(node->left);
	std::cout << node->value << std::endl;
	if (node->right != nullptr)
		_inOrder(node->right);
}
void Tree::preOrder()
{
	std::cout << "Starting preOrder" << std::endl;
	if (_root == nullptr)
		std::cout << "Tree doesn't exist." << std::endl;
	else
		this->_preOrder(_root);
}

void Tree::_preOrder(Node* node)
{
	std::cout << node->value << std::endl;
	if (node->left != nullptr)
		_preOrder(node->left);
	if (node->right != nullptr)
		_preOrder(node->right);
}