#include "Excercise.h"

bool checkParentheses(std::string s)
{
	int pCount = 0; // to count the open parantheses
	for (int i = 0; i < s.size(); i++)
	{
		if (pCount >= 0 && s[i] == '(')
		{
			pCount++;
		}
		else if (pCount <= 0 && s[i] == ')')
		{
			return false;
		}
		else if (pCount > 0 && s[i] == ')')
		{
			pCount--;
		}
	}

	if (pCount) // like if pCount is true (pCount != 0)
		return false;
	else
		return true;
}

void reverseDirection(Node*& head)
{
	Node* prev = new Node(); // Needed to save the previous node
	Node* next = new Node(); // Needed to save the next node before updating the current node
	
	prev = NULL; // This will help to make the first node points to it (points to the NULL)
	next = NULL;

	while (head != NULL)
	{
		next = head->next; // Save the next node
		head->next = prev; // Flip the pointer to the previous node
		prev = head; // Update the address of the previous node to the current node
		head = next; // Update the head to the next node and start over
	}

	head = prev; // The previous node is now the original node but flipped

}

LinkedList* LinkedList::search(std::string data)
{
	LinkedList* list = this;
	while (list != NULL)
	{
		if (list->data == data)
			return list;
		else
			list = list->next;
	}
	return NULL;
}
