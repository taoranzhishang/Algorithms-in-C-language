#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define LEN 10
	
void merge(int *arr, int startIndex, int midIndex, int endIndex)
{
	int *tempArry =(int *)malloc((endIndex - startIndex + 1) * sizeof(int));
	int i = startIndex;
	int j = midIndex + 1;
	int k = 0;
	while (i <= midIndex && j <= endIndex) tempArry[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	while (i <= midIndex) tempArry[k++] = arr[i++];
	while (j <= endIndex) tempArry[k++] = arr[j++];
	for (int i = 0; i < k; arr[startIndex + i] = tempArry[i++]);
	free(tempArry);
}

void sort(int *arr, int startIndex, int endIndex)
{
	if (startIndex != endIndex)
	{
		int midIndex = startIndex + (endIndex - startIndex) / 2;//防止越界
		sort(arr, startIndex, midIndex);
		sort(arr, midIndex + 1, endIndex);
		merge(arr, startIndex, midIndex, endIndex);	
	}
	else
	{
		return;
	}
}

void display(int *arr)
{
	for (int i = 0; i < LEN; printf("%3d", arr[i++]));
}

void build_arr(int *arr)
{
	time_t t;
	int data = time;
	srand(&t);
	for (int i = 0; i < LEN; arr[i++] = rand() % 100);
}

int main()
{
	int arr[] = { 0 };
	build_arr(arr);
	puts("排序前：");
	display(arr);

	sort(arr, 0, LEN - 1);
	puts("\n排序后：");
	display(arr);

	return 0;
}