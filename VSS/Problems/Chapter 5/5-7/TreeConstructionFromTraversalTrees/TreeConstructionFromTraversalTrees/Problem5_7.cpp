#include "Problem5_7.h"
#include <iostream>

int i = 0, j = 0;
bool discovered[6] = { 0,0,0,0,0,0 };

void Traverse_To_Tree(tree*& Tree, int pre[], int in[], int start, int end)
{
	tree* p = new tree();
	p->data = pre[i];
	p->left = NULL; p->right = NULL;
	Tree = p;

	for (j = start; j < end; j++)
	{
		if (pre[i] == in[j])
		{
			Traverse_To_Tree(Tree->left, pre, in, 0, j);
		}
	}
	i++;
}
