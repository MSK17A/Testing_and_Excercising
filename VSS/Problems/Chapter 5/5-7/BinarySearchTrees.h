#pragma once
class tree
{
public:
	int data; // data
	tree* parent; // pointer to parent
	tree* left; // pointer to left child
	tree* right; // pointer to right child
};

tree* searchTree(tree* Tree, int data);
tree* minTree(tree* Tree);
tree* maxTree(tree* Tree);
void traversal(tree* Tree);
void insertTree(tree*& Tree, int data, tree* parent);
void deleteTree(tree*& Tree);
void TreeTesting();
void printOrder(tree* Tree);