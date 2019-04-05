#pragma once
#include "pch.h"

class  Node
{
public:
	Node()
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
		value = 0;
	}

	Node * parent;
	Node * left;
	Node * right;
	int value;
};