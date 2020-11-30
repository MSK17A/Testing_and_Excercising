#pragma once
#include <iostream>

class BST
{
public:
	std::string data;
	BST* parent;
	BST* left, * right;
	int steps;

	BST* search(BST* Tree, std::string data);
	void insert(BST*& Tree, std::string data);
	int searchInstances(BST* Tree, std::string data);
};

