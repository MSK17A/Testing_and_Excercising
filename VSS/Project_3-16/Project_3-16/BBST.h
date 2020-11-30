#pragma once
#include <iostream>

class BBST // An AVL self balancing tree
{
public:
	std::string data;
	BBST* left, * right;
	int height;
	int steps;

	BBST* search(BBST* Tree, std::string data);
	int Height(BBST* Node);
	int balanceFactor(BBST* Tree);
	int max(int a, int b);
	void insert(BBST*& Tree, std::string data);
	void insertBalance(BBST*& Tree, std::string data);
	void leftRotate(BBST*& x);
	void rightRotate(BBST*& x);
	int searchInstances(BBST* Tree, std::string data);
};

