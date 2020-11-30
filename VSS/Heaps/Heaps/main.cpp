#include<iostream>
#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}


int main()
{
	maxHeap h;

	int A[90000];



	//Create a for loop to iterate 100 times

	for (int i = 1; i <= 90000; i++)

	{

		/*Generate a random number between "1" and "1000" using rand() function*/

		A[i] = (rand() % 1000) + 1;
		//cout << A[i] << ",";
	}

	//int A[] = { 4,5,1,3,8,7,9,2,1,4,3,4,8,7,5,4,3,2,1,4,7,9,5,4,6,2,4,5,8,66 };
	
	/*h.heapDelete();
	h.printArray();
	h.heapDelete();
	h.printArray();
	h.heapDelete();
	h.printArray();
	h.heapDelete();
	h.printArray();
	h.heapDelete();
	h.printArray();
	h.heapDelete();
	h.printArray();*/
	cout << "Push key";
	cin.get();
	int* B = h.heapSort(A, sizeof(A) / sizeof(int));
	/*for (int i = 0; i < sizeof(A) / sizeof(int); i++)
	{
		cout << B[i]<<",";
	}*/
	cout << endl;

	cout << "Push key";
	cin.get();

	qsort(A, 7, sizeof(int), cmpfunc);
	/*for (int i = 0; i < sizeof(A) / sizeof(int); i++)
	{
		cout << A[i] << ",";
	}*/

	cout << "Push key";
	cin.get();

	return 0;
}