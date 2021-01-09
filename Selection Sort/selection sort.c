#include <stdio.h>
#include <time.h>
#define N 10

/*
使用选择排序法对一个随机生成长度为10的数组进行升序排序
*/
void main()
{
	/*
	取时间创建随机数
	*/
	time_t t;
	unsigned int data = time;//取时间作为随机数
	srand(&t);//创建随机数种子

	/*
	生成一个长度为10的数组
	*/
	int arr[N] = { 0 };
	puts("排序前：");
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;//数组元素为小于100的整数
		printf(" %d", arr[i]);
	}

	/*
	从下标0的元素开始对后面所有元素进行比较，若前者大于后者则值交换
	从左开始每个元素都与其它元素比较一次
	*/
	for (int i = 0; i < N - 1; i++)//N-1表示当有1个元素时不需要排序
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	/*
	输出排序后的数组
	*/
	puts("\n排序后：");
	for (int i = 0; i < N; i++)
	{
		printf(" %d", arr[i]);
	}
}
