#include <stdio.h>
#include <time.h>
#define SIZE 10

void display(int *arr)
{
	for (int i = 0; i < SIZE; printf("%3d", arr[i++]));
}

void build_arr(int *arr)
{
	time_t t;
	unsigned int data = time;
	srand(&t);
	for (int i = 0; i < SIZE; arr[i++] = rand() % 100);
}

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quick_sort(int *arr, int lIndex, int rIndex)
{
	if (lIndex < rIndex)
	{
		int pivot = arr[rIndex];
		int leftIndex = lIndex;
		int rightIndex = rIndex - 1;
		while (leftIndex <= rightIndex)
		{
			while (leftIndex <= rightIndex && arr[leftIndex] <= pivot)leftIndex++;
			while (leftIndex <= rightIndex && arr[rightIndex] > pivot)rightIndex--;
			if (leftIndex < rightIndex)swap(arr, leftIndex, rightIndex);
		}
		swap(arr, leftIndex, rIndex);
		int midIndex = leftIndex;
		quick_sort(arr, lIndex, midIndex - 1);
		quick_sort(arr, midIndex + 1, rIndex);
	}
}

int main()
{
	int arr[SIZE] = { 0 };
	build_arr(arr);
	puts("ÅÅÐòÇ°£º");
	display(arr);

	quick_sort(arr, 0, SIZE - 1);
	puts("\nÅÅÐòºó£º");
	display(arr);

	return 0;
}