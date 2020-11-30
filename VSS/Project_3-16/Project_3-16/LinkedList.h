#pragma once
#include <iostream>
#include <string>

class LinkedList {
public:
	std::string data;
	LinkedList* next;
	int steps;

	LinkedList() : data(""), next(NULL), steps(0) {};
	LinkedList* search(LinkedList* head, std::string data);
	int searchInstances(LinkedList* head, std::string data);
	void insert(LinkedList*& head, std::string data);
	void append(LinkedList*& head, std::string data);
	void printList(LinkedList* head);
};

