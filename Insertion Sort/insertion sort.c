#include <stdio.h>
#include <time.h>
#define LEN 10

/*
从数组arr[1]开始向后比较，后者大于前者，则互换
完成一次互换后向前比较，向前逐个比较调整
*/
void insertion_sort(int arr[])
{
	for (int i = 1; i < LEN; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
/*
输出数组
*/
void display(int arr[])
{
	for (int i = 0; i < LEN; i++)
	{
		printf("%3d",arr[i]);
	}
}
/*
创建随机数组
*/
void build_arr(int arr[])
{
	time_t t;
	unsigned int data = time;
	srand(&t);
	for (int i = 0; i < LEN; i++)
	{
		arr[i] = rand() % 100;
	}
}

int main()
{
	int arr[LEN] = { 0 };
	build_arr(arr);
	puts("排序前：");
	display(arr);

	insertion_sort(arr);
	puts("\n排序后：");
	display(arr);
	return 0;
}