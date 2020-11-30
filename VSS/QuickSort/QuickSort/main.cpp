#include <iostream>

using namespace std;

int partioning(int arr[],int low,int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);

int main()
{
	int arr[6] = { 6,4,9,2,8,3 };

	quickSort(arr, 0, 5);

	printArray(arr, 6);
	return 0;
}

int partioning(int arr[], int low, int high)
{
	int i = low;
	int j = high;
	int pivot = low;

	while (i < j)
	{
		while (arr[i] <= arr[pivot]) /* Keep moving until arr[i] is bigger than the pivot */
		{
			i++;
		}
		while (arr[j] > arr[pivot]) /* Keep moving until arr[j] is smaller than the pivot */
		{
			j--;
		}

		if(i < j) /* To prevent swapping when (i > j) */
			swap(arr[i], arr[j]); /* Swap the values between indices i and j */
	}
	swap(arr[j], arr[pivot]);
	return j;
}

void quickSort(int arr[], int low, int high)
{
	if (high > low)
	{
		int partitionIndex = partioning(arr, low, high);
		quickSort(arr, low, partitionIndex -1);
		quickSort(arr, partitionIndex + 1, high);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ",";
}