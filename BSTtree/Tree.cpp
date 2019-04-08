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
	Node * n = this->findValue(value);
	if (n == nullptr)
		return;

	if (n->right == nullptr && n->left == nullptr)
	{
		if (n != _root)
		{
			if (n->parent->right == n)
				n->parent->right = nullptr;
			else
				n->parent->left = nullptr;
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
			if (n->parent->right == n)
				n->parent->right = n->right;
			else
				n->parent->left = n->right;
		}
		else
		{
			_root = n->right;
		}

		n->right->parent = n->parent;
	}
	else if (n->right == nullptr && n->left != nullptr)
	{
		if (n != _root)
		{
			if (n->parent->right == n)
				n->parent->right = n->left;
			else
				n->parent->left = n->left;
		}
		else
		{
			_root = n->left;
		}

		n->left->parent = n->parent;
	}
	else
	{
		auto nnode = n->right;
		while (nnode->left != nullptr)
			nnode = nnode->left;

		if (n != _root)
		{
			if (n->parent->right == n)
				n->parent->right = nnode;
			else
				n->parent->left = nnode;
		}
		else
		{
			_root = nnode;
		}
		if (nnode->parent->right == nnode)
			nnode->parent->right = nullptr;
		else
			nnode->parent->left = nullptr;

		nnode->parent = n->parent;

		nnode->left = n->left;
		n->left->parent = nnode;

		auto nodeAuted = nnode->right;

		if (n->right != nnode)
		{
			nnode->right = n->right;
			n->right->parent = nnode;
		}
			
		if (nodeAuted != nullptr)
		{
			nnode->right->parent = nullptr;
			this->addNodeToNode(nnode->right, nnode);
		}
			
	}

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

void Tree::postOrderDelete()
{
	this->_postOrder(_root);
	this->_nodes.clear();
}

void Tree::_preOrder(Node* node)
{
	std::cout << node->value << std::endl;
	if (node->left != nullptr)
		_preOrder(node->left);
	if (node->right != nullptr)
		_preOrder(node->right);
}

void Tree::_postOrder(Node * node)
{
	if (node->left != nullptr)
		_postOrder(node->left);
	if (node->right != nullptr)
		_postOrder(node->right);

	std::cout <<"Usuwam: "<< node->value << std::endl;

	if (node != _root)
	{
		if (node->parent->right == node)
			node->parent->right = nullptr;
		else
			node->parent->left = nullptr;
	}
	else
	{
		_root = nullptr;
	}

}

void Tree::showSubTree(int value)
{
	Node * subroot = this->findValue(value);
	if (subroot == nullptr)
		return;
	this->_inOrder(subroot);
}

Node * Tree::findValue(int value)
{
	Node * result = nullptr;
	std::cout << "Starting search" << std::endl;
	if (_root == nullptr)
		std::cout << "Tree doesn't exist." << std::endl;
	else
	{
		result = this->_findValue(_root, value);
		if (result == nullptr)
			std::cout << "Wartoœæ nieznaleziona." << std::endl;
		else
			return result;
	}
	return nullptr;
}

Node * Tree::_findValue(Node* node, int value)
{
	Node * result = nullptr;
	if (node->value == value)  return node;
	if (node->left != nullptr)
		if ((result = _findValue(node->left, value)) != nullptr)
			return result;
	if (node->right != nullptr)
		if ((result = _findValue(node->right, value)) != nullptr)
			return result;
	return result;

}