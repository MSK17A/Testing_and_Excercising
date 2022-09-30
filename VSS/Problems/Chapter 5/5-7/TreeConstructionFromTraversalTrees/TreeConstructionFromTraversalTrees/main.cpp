#include<iostream>
#include"BinarySearchTrees.h"
#include"Problem5_7.h"

using namespace std;

int main()
{
	tree* head = new tree();
	int pre[] = { 0,1,3,4,5,2 };
	int in[] = { 4,3,5,1,0,2 };

	Traverse_To_Tree(head, pre, in);

	return 0;
}