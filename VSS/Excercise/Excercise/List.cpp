#include "List.h"

void printList(Node* head)
{
	std::cout << '[';
	while (head != NULL) // Check if the head reaches the end.
	{
		std::cout << head->data << ',';
		head = head->next; // Pointing the head to the next node.
		if (head == NULL)
			std::cout << ']';
	}
}

Node* createNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->next = NULL;

	return node;
}

Node* searchList(Node* head, int data)
{
	if (head == NULL)
		return nullptr;

	if (head->data == data)
		return head;
	else
		return searchList(head->next, data);
}

void insertList(Node*& head, int data)
{
	Node* P = new Node(); // Creating Temporary pointer
	P->data = data;
	P->next = head;
	head = P; // Copying P to head (Notice that the address of head is changed but it is stored in Node* head)
}

void deleteList(Node*& head)
{
	Node* p = head; // Temporary pointer that holds the address of the head of the list.
	head = head->next; // Change the address of the head to the next node.
	delete p; // delete the node.

	// The address of the Node* argument is stayed the same, we just changed the value inside it.
}

void ListTesting()
{/*
	// Creating Node pointers
	Node* head = NULL;
	Node* one = NULL;
	Node* two = NULL;
	Node* three = NULL;

	// Alllocate nodes on the heap
	one = new Node();
	two = new Node();
	three = new Node();

	// Link the nodes
	one->next = two;
	two->next = three;
	three->next = NULL;

	// Assign data to each node
	one->data = 1;
	two->data = 2;
	three->data = 3;

	// Assign head to the first node
	head = one;
	*/

	Node* head;
	head = createNode(0);
	head->next = createNode(1);
	head->next->next = createNode(2);

	insertList(head->next, 10);
	printList(head); std::cout << "\n";
	deleteList(head->next);

	printList(head);
}