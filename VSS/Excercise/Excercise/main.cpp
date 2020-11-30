#include<iostream>
#include"Excercise.h"


int main()
{
	Node* head;
	head = createNode(0);
	head->next = createNode(1);
	head->next->next = createNode(2);

	insertList(head->next, 10);
	printList(head); std::cout << "\n";
	deleteList(head->next);
	printList(head); std::cout << "\n";

	reverseDirection(head);
	printList(head);

	return 0;
}
