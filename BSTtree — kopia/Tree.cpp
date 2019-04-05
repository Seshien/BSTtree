#include "pch.h"

Tree::Tree()
{
	height = 0;
}

Tree::Tree(const std::vector<int>& arr, bool avl)
{
	if (avl == false)
	{
		this->createNonAVL(arr);
	}
	else
	{
		// to do
	}

}

void Tree::createNonAVL(const std::vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		_nodes.push_back(std::make_unique<Node>(arr[i]));
		if()
	}
}
