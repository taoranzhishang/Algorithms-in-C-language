#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define T_SIZE 100

void display(int *arr)
{
	for (int i = 0; i < SIZE; printf("%3d", arr[i++]));
}

void fill_arr(int *arr)
{
	time_t t;
	unsigned int data = time;
	srand(&t);
	for (int i = 0; i < SIZE; arr[i++] = rand() % 100);
}

void radix_sort(int *arr)
{
	int max = arr[0];
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	int division = 1;
	int *sortedArr = (int *)malloc(sizeof(int)*SIZE);
	while (max / division > 0)
	{
		int bucket[T_SIZE] = { 0 };
		for (int i = 0; i < SIZE; i++)
		{
			bucket[arr[i] / division % 10]++;
		}
		for (int i = 1; i < 100; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (int i = SIZE - 1; i >= 0; i--)
		{
			sortedArr[--bucket[arr[i] / division % 10]] = arr[i];
		}
		division *= 10;
	}
	display(sortedArr);
	free(sortedArr);
}

int main()
{
	int arr[SIZE] = { 0 };
	fill_arr(arr);
	puts("≈≈–Ú«∞£∫");
	display(arr);
	puts("\n≈≈–Ú∫Û£∫");
	radix_sort(arr);

	return 0;
}