#include<iostream>
#include<fstream>
#include"LinkedList.h"
#include"BST.h"
#include"BBST.h"

using namespace std;



int main()
{
	// Variable declaration and initialization.
	ifstream f;
	f.open("sample.txt");
	string word;

	LinkedList* list = NULL;
	BST* Tree = new BST(); Tree = NULL;
	BBST* BTree = new BBST(); BTree = NULL;
	
	// Put all the text into the data structure
	while (f >> word)
	{
		list->append(list, word);
		Tree->insert(Tree, word);
		BTree->insert(BTree, word);
		
	}
	// Results
	string searchWord = "AM";
	cout << "Found instances = " << list->searchInstances(list, searchWord) << endl;
	cout << "Found instances = " << Tree->searchInstances(Tree, searchWord) << endl;
	cout << "Found instances = " << BTree->searchInstances(BTree, searchWord) << endl;

	// Report
	cout << "........Report........\n";
	if (list != NULL)
		cout << "Linked list steps = " << list->steps << endl;
	if (Tree != NULL)
		cout << "Binary search tree steps = " << Tree->steps << endl;
	if (Tree != NULL)
		cout << "Balanced Binary search tree steps = " << BTree->steps << " With Balance Factor = " << BTree->balanceFactor(BTree) << endl;

	// Freeing memory
	f.close();

	cin.get();

	return 0;
}