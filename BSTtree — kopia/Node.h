#pragma once
#include "pch.h"

class Node
{
public:

	Node(int value);

	Node(Node * parent, int value);


private:

	Node * _parent;
	Node * _left;
	Node * _right;
	int _value;

};