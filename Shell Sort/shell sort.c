#include <stdio.h>
#include <time.h>
#define LEN 100

/*
1）希尔原本的Gap：N/2、N/4、...1(反复除以2)
2）Hibbard的Gap：1、3、7、...、2k-1（k表示第几个gap）
3）Knuth的Gap: 1、4、13、...、(3k - 1) / 2（k表示第几个gap）
4）Sedgewick的Gap: 1、5、19、41、109、...
*/

///*
//原始的希尔增量序列,二分折半
//此增量序列也称为Shell增量序列
//原始希尔排序最坏的时间复杂度为O(n^2)
//*/
//void shell_sort(int *arr)
//{
//	for (int gap = LEN / 2; gap > 0; gap /= 2)//gap逐渐减小，gap=1时就是一个插入排序
//	{
//		for (int i = gap; i < LEN; i++)
//		{
//			for (int j = i; j > gap - 1; j -= gap)
//			{
//				if (arr[j] < arr[j - gap])
//				{
//					int temp = arr[j];
//					arr[j] = arr[j - gap];
//					arr[j - gap] = temp;
//				}
//			}
//		}
//	}
//}

/*
Knuth增量序列
*/
void shell_sort(int *arr)
{
	int h = 1;
	while (h <= LEN / 3)
	{
		h = h * 3 + 1;
	}
	for (int gap = h; gap > 0; gap = (gap - 1) / 3)//gap最后为1时，就是插入排序
	{
		for (int i = gap; i < LEN; i++)
		{
			for (int j = i; j > gap - 1; j -= gap)
			{
				if (arr[j] < arr[j - gap])
				{
					int temp = arr[j];
					arr[j] = arr[j - gap];
					arr[j - gap] = temp;
				}
			}
		}
	}
}

void display(int *arr)
{
	for (int i = 0; i < LEN; i++)
		printf("%3d", arr[i]);
}

void build_arr(int *arr)
{
	time_t t;
	unsigned int data = time;
	srand(&t);

	for (int i = 0; i < LEN; i++)
		arr[i] = rand() % 100;
}
int main()
{
	int arr[LEN] = { 0 };
	build_arr(arr);
	puts("排序前：");
	display(arr);

	shell_sort(arr);
	puts("\n排序后：");
	display(arr);

	return 0;
}