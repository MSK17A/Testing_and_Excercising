#include "LinkedList.h"

LinkedList* LinkedList::search(LinkedList* head, std::string data)
{
	if (head == NULL)
		return NULL;

	if (head->data == data)
		return head;
	else
		return search(head->next, data);
}

int LinkedList::searchInstances(LinkedList* head, std::string data)
{
	int pCount = 0;
	
	if (head == NULL) return NULL;
	while (head != NULL)
	{
		if (head->data == data)
		{
			pCount++;
		}
		head = head->next;
		steps++;
	}
	return pCount;
}

void LinkedList::insert(LinkedList*& head, std::string data)
{
	LinkedList* P = new LinkedList();
	P->data = data;
	P->next = head;
	head = P;

}

void LinkedList::append(LinkedList*& head, std::string data)
{
	LinkedList* P = new LinkedList();
	if (head == NULL)
	{
		P->data = data;
		P->next = NULL;
		head = P;
	}
	else
		append(head->next, data);
}

void LinkedList::printList(LinkedList* head)
{
	
	std::cout << '[';
	while (head != NULL) // Check if the head reaches the end.
	{
		std::cout << head->data << " ";
		head = head->next; // Pointing the head to the next node.
		if (head == NULL)
			std::cout << ']';
	}
	
}
