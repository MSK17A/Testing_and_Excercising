#include "BBST.h"

BBST* BBST::search(BBST* Tree, std::string data)
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

int BBST::Height(BBST* Node)
{
	if(Node == NULL)
		return 0;
	return Node->height;
}

int BBST::balanceFactor(BBST* Tree)
{
	if (Tree == NULL)
		return 0;
	return Height(Tree->left) - Height(Tree->right);
}

int BBST::max(int a, int b)
{
	return (a > b) ? a : b; // if a>b return a or else return b
}

void BBST::insert(BBST*& Tree, std::string data)
{
	BBST* p; // Temporary pointer

	if (Tree == NULL)
	{
		p = new BBST(); // Allocate memory.
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

	Tree->height = 1 + max(Height(Tree->left), Height(Tree->right));

	int BF = balanceFactor(Tree);

	if (BF > 0)
	{
		if (data < Tree->left->data)
			rightRotate(Tree);
		else if (data > Tree->left->data)
		{
			leftRotate(Tree->left);
			rightRotate(Tree);
		}
	}

	if (BF < -1)
	{
		if (data > Tree->right->data)
			leftRotate(Tree);
		else if (data < Tree->right->data)
		{
			rightRotate(Tree->right);
			leftRotate(Tree);
		}
	}
}

void BBST::leftRotate(BBST*& x)
{
	BBST* y = x->right;
	BBST* beta = y->left;

	y->left= x;
	x->right = beta;

	x->height = max(Height(x->left), Height(x->right)) + 1;
	y->height = max(Height(y->left), Height(y->right)) + 1;

	x = y;
}

void BBST::rightRotate(BBST*& y)
{
	BBST* x = y->left;
	BBST* beta = x->right;

	x->right = y;
	y->left = beta;

	y->height = max(Height(y->left), Height(y->right)) + 1;
	x->height = max(Height(x->left), Height(x->right)) + 1;

	y = x;

}

int BBST::searchInstances(BBST* Tree, std::string data)
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
