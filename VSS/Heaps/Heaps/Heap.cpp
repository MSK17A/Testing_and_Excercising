#include "Heap.h"

/*.............More details in the notes...............*/

void maxHeap::init_heap(int A[], int capacity)
{
	n = capacity;
	hArray = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		heapInsert(A[i]);
	}
}

void maxHeap::heapInsert(int x)
{
	if (size+1 >= n)
	{
		std::cout << "Heap Overflow";
		return;
	}

	size++; // Increment heap size. ( Not capacity )
	hArray[size] = x; // Insert into last empty space.
	
	bubbleUp(size); // Needed to re-maintain the correct structure of the heap. (Starting form the last element in the heap)
}

void maxHeap::heapDelete()
{
	int temp = hArray[0];
	hArray[0] = hArray[size]; /* Put the last element into the top */
	size--; /* Since we deleted an element, decrease the size of the heap. */
	bubbleDown(0); /* Needed to re-maintain the correct structure of the heap. (Starting from the top) */
	hArray[size+1] = temp; /* Put the deleted element into the empty slot */
}

int maxHeap::parent(int i)
{
	if (i == 0)
		return -1;
	else return (i / 2);
}

int maxHeap::leftChild(int i)
{
	if (i == 0)
		return (i + 1);
	else
		return (2 * i);
}

int maxHeap::rightChild(int i)
{
	if (i == 0)
		return (i + 2);
	else
	return (2 * i + 1);
}

void maxHeap::swap(int i, int j)
{
	int temp = hArray[i];
	hArray[i] = hArray[j];
	hArray[j] = temp;
}

void maxHeap::bubbleUp(int i)
{
	if (parent(i) == -1) return; // root has no parent

	if (hArray[parent(i)] < hArray[i]) // If the parent is smaller than its child
	{
		swap(parent(i), i); // Swap the values.
		bubbleUp(parent(i)); // Go to parent, and recheck the parents along the height of the tree O(log(n)).
	}
}

void maxHeap::bubbleDown(int i)
{
	/*for (int i = 0; i <= size; i++)
	{
		std::cout << hArray[i] << ",";
	}
	std::cout << std::endl;*/
	if (2*i >= size) /* Since we put the deleted elements into the empty space, the size is reduced and
					we also want to make sure it does not go to the deleted elements because the deleted elements
					is not his child. (i is the parent and 2*i is the child) */
		return;

	if(hArray[leftChild(i)] > hArray[rightChild(i)]) /* Check if the left child is bigger than the the right side */
	{
		if (hArray[i] < hArray[leftChild(i)]) /* Check if the left child is bigger than the parent */
		{
			swap(i, leftChild(i));
			bubbleDown(leftChild(i)); /* Go to the left child and repeat */
		}
	}
	else /* Same as before but now with the right child */
	{
		if (hArray[i] < hArray[rightChild(i)])
		{
			swap(i, rightChild(i));
			bubbleDown(rightChild(i));
		}
	}
}

int* maxHeap::heapSort(int A[], int capacity)
{	/* Two steps, first construct the heap and the delete the maximum (top) element */
	init_heap(A, capacity);
	
	for (int i = 0; i < n; i++)
	{
		heapDelete();
	}

	return hArray;
}

void maxHeap::printArray()
{
	for (int i = 0; i <= n - 1; i++)
	{
		std::cout << hArray[i] << ",";
	}
	std::cout << std::endl;
}

