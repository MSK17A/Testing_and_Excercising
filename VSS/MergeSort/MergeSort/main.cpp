#include <iostream>

using namespace std;

void merge(int s[], int low, int mid, int high);
void mergeSort(int s[], int low, int high);
void printArray(int arr[], int size);

int main()
{
	int S[] = { 4,2,6,7,1,3 };

	mergeSort(S,0,5);
	printArray(S, 6);

	return 0;
}

void mergeSort(int s[], int low, int high) /* Low is the first element and high is the last element */
{
	/* merging function will be excuted firstly when merging only two lists with one element in each
	(one element in a list makes it sorted list and can be merged) */
	if (low < high)
	{
		int mid = (low + high) / 2; /* Calculate the middle element */
		mergeSort(s, low, mid); /* Go to left half */
		mergeSort(s, mid + 1, high); /* Go to right half */
		merge(s, low, mid, high); /* Merge the halves */
	}
}

void merge(int s[], int low, int mid, int high)
{
	int i = 0, j = 0, k = 0;


	int n = mid - low + 1; /* Size of the first half */
	int m = high - mid; /* Size of the second half */

	int* buffA = new int[n]; /* A temporary array for first half */
	int* buffB = new int[m]; /* A temporary array for first half */

	/* Copying all the elements in the step to the buffers */
	for (int i = low; i <= mid; i++)
	{
		buffA[k++] = s[i];
	}
	k = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		buffB[k++] = s[i];
	}

	k = low; /* Re-Initialize k for use with s[] array */
	while (i < n && j < m)
	{
		/* Check and merge the buffers into s[], this will swap elements in s[] */
		if (buffA[i] <= buffB[j])
			s[k++] = buffA[i++];
		else
			s[k++] = buffB[j++];
	}

	/* Copy all the remaining elements in the buffers */
	for (; i < n; i++)
		s[k++] = buffA[i];

	for (; j < m; j++)
		s[k++] = buffB[j];

}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
}