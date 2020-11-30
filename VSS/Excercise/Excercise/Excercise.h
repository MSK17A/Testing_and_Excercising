#pragma once
#include <string>
#include "List.h"

bool checkParentheses(std::string s); // 3-1
void reverseDirection(Node*& head); // 3-2
 
// 3-16
class LinkedList {
public:
	std::string data;
	LinkedList* next;

	LinkedList* search(std::string data);
};

class BST {

};

class BBST {

};