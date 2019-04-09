#pragma once
#include "pch.h"

class  Node
{
public:
	Node()
	{
		left = nullptr;
		right = nullptr;
		value = 0;
	}

	Node * left;
	Node * right;
	int value;
};