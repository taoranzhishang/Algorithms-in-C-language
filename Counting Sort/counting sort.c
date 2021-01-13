#include <stdio.h>
#include <time.h>
#define LEN 10
#define SIZE 100

void display(int *arr)
{
	for (int i = 0; i < LEN; printf("%3d", arr[i++]));
	/*for (int i = 0; i < LEN; i++)
	{
		printf("%3d", arr[i]);
	}*/
}

void counting_sort(int *arr)
{
	int sorted_arr[LEN] = { 0 };
	int temp[SIZE] = { 0 };
	for (int i = 0; i < LEN; temp[arr[i++]]++);//桶
	/*for (int i = 0; i < LEN; i++)
	{
		int index = arr[i];
		temp[index]++;
	}*/
	//for (int i = 0, j = 0; i < SIZE; i++)while (temp[i]-- > 0)sorted_arr[j++] = i;//不稳定的写法
	for (int i = 1; i < SIZE; i++)
	{
		temp[i] = temp[i] + temp[i - 1];//相邻次数累加，用作排序数组的索引
	}

	/*
	从后往前，arr的元素值倒着赋值给排序数组，排序数组的索引自减，temp[]的索引由arr[i]确定
	arr[]的值由i确定，sorted_arr[]由temp[]确定
	arr[i]赋值给sorted[]时，sorted的下标位置是由arr的值决定的temp[]确定，以此排序
	*/
	for (int i = LEN - 1; i >= 0; i--)
	{
		sorted_arr[--temp[arr[i]]] = arr[i];
	}

	display(sorted_arr);
}

void build_arr(int *arr)
{
	time_t t;
	unsigned int data = time;
	srand(&t);
	for (int i = 0; i < LEN; arr[i++] = rand() % 100);
}

int main()
{
	int arr[LEN] = { 0 };
	build_arr(arr);
	puts("排序前：");
	display(arr);
	
	puts("\n排序后：");
	counting_sort(arr);
	return 0;
}