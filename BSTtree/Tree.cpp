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

Node * Tree::findMax()
{
	if (_root == nullptr)
		return nullptr;
	Node * n = _root;
	while (n->right != nullptr)
	{
		std::cout << "Jestem w wierzcholku o wartosci: " << n->value << std::endl;
		n = n->right;
	}	
	return n;
}

void Tree::deleteNode(int value)
{
	auto a = this->findValue(value);
	Node * n = a.second;
	Node * parent = a.first;
	bool right = false;
	if (n == nullptr)
		return;

	if (n == parent->right)
		right = true;

	if (n->right == nullptr && n->left == nullptr)
	{
		if (n != _root)
		{
			if (right)
				parent->right = nullptr;
			else
				parent->left = nullptr;
		}
		else
		{
			_root = nullptr;
		}
	}
	else if (n->right != nullptr && n->left == nullptr)
	{
		if (n != _root)
		{
			if (parent->right == n)
				parent->right = n->right;
			else
				parent->left = n->right;
		}
		else
		{
			_root = n->right;
		}

	}
	else if (n->right == nullptr && n->left != nullptr)
	{
		if (n != _root)
		{
			if (parent->right == n)
				parent->right = n->left;
			else
				parent->left = n->left;
		}
		else
		{
			_root = n->left;
		}
	}
	else
	{
		auto nnode = n->right;
		auto nnodeParent = n;
		while (nnode->left != nullptr)
		{
			nnodeParent = nnode;
			nnode = nnode->left;
		}
		if (n != _root)
		{
			if (parent->right == n)
				parent->right = nnode;
			else
				parent->left = nnode;
		}
		else
		{
			_root = nnode;
		}
		if (nnodeParent->right == nnode)
			nnodeParent->right = nullptr;
		else
			nnodeParent->left = nullptr;

		nnode->left = n->left;

		auto nodeAuted = nnode->right;

		if (n->right != nnode)
			nnode->right = n->right;
			
		if (nodeAuted != nullptr)
			this->addNodeToNode(nnode->right, nnode);			
	}

	delete n;
}

void Tree::deleteManyNodes(const std::vector<int>& values)
{
	for (size_t i = 0; i < values.size(); i++)
	{
		this->deleteNode(values[i]);
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
	this->avlNext(arr.cbegin(), arr.cend()-1);
}

void Tree::addNodeToNode(Node * node, Node * root)
{
	if (node->value > root->value)
	{
		if (root->right == nullptr)
		{
			root->right = node;
		}
		else
			this->addNodeToNode(node, root->right);
	}
	else
	{
		if (root->left == nullptr)
		{
			root->left = node;
		}
		else
			this->addNodeToNode(node, root->left);
	}
}

void Tree::avlNext(const std::vector<int>::const_iterator & beg, const std::vector<int>::const_iterator & end)
{
	if (beg == end)
		this->addNode(*beg);
	else if (beg + 1 == end)
	{
		this->addNode(*beg);
		this->addNode(*end);
	}
	else
	{
		auto piv = (beg + (end - beg) / 2);
		this->addNode(*piv);
		this->avlNext(beg, piv - 1);
		this->avlNext(piv + 1, end);
	}
}

void Tree::addNode(int value)
{
	Node * n = new Node;
	n->value = value;

	if (_root == nullptr)
		_root = n;
	else
		this->addNodeToNode(n, _root);
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

void Tree::postOrderDelete()
{
	this->_postOrder(nullptr, _root);
}

void Tree::_preOrder(Node* node)
{
	std::cout << node->value << std::endl;
	if (node->left != nullptr)
		_preOrder(node->left);
	if (node->right != nullptr)
		_preOrder(node->right);
}

void Tree::_postOrder(Node* parent, Node * node)
{
	if (node->left != nullptr)
		_postOrder(node, node->left);
	if (node->right != nullptr)
		_postOrder(node, node->right);

	std::cout <<"Usuwam: "<< node->value << std::endl;

	if (node != _root)
	{
		if (parent->right == node)
			parent->right = nullptr;
		else
			parent->left = nullptr;
	}
	else
	{
		_root = nullptr;
	}
	delete node;
}

void Tree::showSubTree(int value)
{
	Node * subroot = this->findValue(value).second;
	if (subroot == nullptr)
		return;
	this->_inOrder(subroot);
}

std::pair<Node*, Node*> Tree::findValue(int value)
{
	std::pair<Node*, Node*> result = std::make_pair<Node*, Node*>(nullptr, nullptr);
	std::cout << "Starting search" << std::endl;
	if (_root == nullptr)
		std::cout << "Tree doesn't exist." << std::endl;
	else
	{
		result = this->_findValue(std::make_pair(nullptr, _root), value);
		if (result.second == nullptr)
			std::cout << "Wartoœæ nieznaleziona." << std::endl;
		else
			return result;
	}
	return std::make_pair<Node*,Node*>(nullptr, nullptr);
}


std::pair<Node*, Node*> Tree::_findValue(std::pair<Node *, Node*> nodes, int value)
{
	if (nodes.second->value == value)  return nodes;
	if (nodes.second->left != nullptr)
		return _findValue(std::make_pair(nodes.second, nodes.second->left), value);
	if (nodes.second->right != nullptr)
		return _findValue(std::make_pair(nodes.second, nodes.second->right), value);

	return std::make_pair<Node*,Node*>(nullptr, nullptr);

}