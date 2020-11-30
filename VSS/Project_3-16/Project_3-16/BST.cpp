#include "BST.h"

BST* BST::search(BST* Tree, std::string data)
{
	if (Tree == NULL)
	{
		std::cout << "Empty tree\n";
		return NULL;
	}

	if (Tree->data == data) return Tree; // Return the tree that has the right data
	else if (data >= Tree->data) return search(Tree->right, data); // Compare the data and search in the appropiate child
	else return search(Tree->left, data);
}

void BST::insert(BST*& Tree, std::string data)
{
	BST* p; // Temporary pointer

	if (Tree == NULL)
	{
		p = new BST(); // Allocate memory.
		p->data = data; // Put the data in its place.
		p->left = p->right = NULL; // It is only one key so left and right childs are set to NULL.
		//p->parent = parent; // Link to parent.

		Tree = p; // Replace the NULL Tree to p Tree.
		return; // End the function.
	}

	if (data < Tree->data) // Check if key is smaller than the key in the tree.
		insert(Tree->left, data); // Go to left child and repeat the story.
	else
		insert(Tree->right, data); // Go to right child and repeat the story.
}

int BST::searchInstances(BST* Tree, std::string data)
{
	int pCount = 0;
	steps = 0;
	if (Tree == NULL) return NULL;

	while (Tree != NULL)
	{
		if (Tree->data == data)
		{
			pCount++;
			Tree = Tree->right;
		}
		else if (data >= Tree->data) Tree = Tree->right; // Compare the data and search in the appropiate child
		else Tree = Tree->left;
		steps++;
	}

	return pCount;
}
