#include "BinarySearchTrees.h"
#include<iostream>


tree* searchTree(tree* Tree, int data)
{
	if (Tree == NULL)
	{
		std::cout << "Empty tree\n";
		return NULL;
	}
	
	if (Tree->data == data) return Tree; // Return the tree that has the right data
	else if (data >= Tree->data) return searchTree(Tree->right, data); // Compare the data and search in the appropiate child
	else return searchTree(Tree->left, data);
}

tree* minTree(tree* Tree)
{
	if (Tree->left != NULL)
	{
		minTree(Tree->left);
	}
	else
		return Tree;


}

tree* maxTree(tree* Tree)
{
	if (Tree->right != NULL)
	{
		maxTree(Tree->right);
	}
	else
		return Tree;
}

void traversal(tree* Tree)
{
	if (Tree != NULL)
	{
		traversal(Tree->left); // Go to left tree (this will not end until the left child is null).
		std::cout << Tree->data << ","; // print the data in console.
		traversal(Tree->right); // Go to right child (this will repeat the history).
	}

}

void insertTree(tree*& Tree, int data, tree* parent)
{
	tree* p; // Temporary pointer

	if (Tree == NULL)
	{
		p = new tree(); // Allocate memory.
		p->data = data; // Put the data in its place.
		p->left = p->right= NULL; // It is only one key so left and right childs are set to NULL.
		p->parent = parent; // Link to parent.
		
		Tree = p; // Replace the NULL Tree to p Tree.
		return; // End the function.
	}

	if (data < Tree->data) // Check if key is smaller than the key in the tree.
		insertTree(Tree->left, data, parent); // Go to left child and repeat the story.
	else
		insertTree(Tree->right, data, parent); // Go to right child and repeat the story.
}

void deleteTree(tree*& Tree)
{
	tree* p;

	if ((Tree->left == NULL) && (Tree->right == NULL))
	{
		delete Tree;
	}
	else if ((Tree->right != NULL) ^ (Tree->left != NULL))
		if (Tree->left != NULL)
		{
			p = Tree;
			Tree = Tree->left;
			delete p;
		}
		else
		{
			p = Tree;
			Tree = Tree->right;
			delete p;
		}
	else
	{
		p = minTree(Tree->right);
		Tree->data = p->data;
		deleteTree(p);
	}
}

void printOrder(tree* Tree)
{
	std::cout << "[";
	traversal(Tree);
	std::cout << "\b]";
}

void TreeTesting()
{
	tree* Tree = new tree();
	tree* Tree2 = new tree();
	tree* Tree3 = new tree();

	Tree->data = 1; Tree2->data = 2; Tree3->data = 3;

	Tree->right = Tree3;
	Tree3->left = Tree2;

	insertTree(Tree, 4, Tree->parent);
	insertTree(Tree, 10, Tree->parent);
	insertTree(Tree, 7, Tree->parent);

	printOrder(Tree); std::cout << "\n";
	tree* search = new tree();
	
	search = searchTree(Tree, 1);
	deleteTree(search);
	printOrder(Tree);
}
