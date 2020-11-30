#pragma once
#include<iostream>

class Node
{
public:
	int data;
	Node* next;
};

void printList(Node* head); // Print the nodes as a list starting from the head
Node* createNode(int data);
Node* searchList(Node* head, int data);
void insertList(Node*& head, int data);
void deleteList(Node*& head);
void ListTesting();