#pragma once
#include <iostream>

class maxHeap
{
public:
	int n; // Capacity
	int size = -1; // Size of heap
	int* hArray;

	void init_heap(int A[], int capacity);
	void heapInsert(int x);
	void heapDelete();
	int parent(int i);
	int leftChild(int i);
	int rightChild(int i);
	void swap(int i, int j);
	void bubbleUp(int i);
	void bubbleDown(int i);
	int* heapSort(int A[], int capacity);
	void printArray();
};