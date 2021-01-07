#include <stdio.h>
#include <time.h>
#define N 10

/*
从第一个数开始往后，每一个数都比较一次
*/
void main()
{
	/*
	生成一个随机数组
	*/
	time_t t;
	unsigned int data = time;//取N时间作为随机数
	srand(&t);//创建随机数种子
	int str[N] = { 0 };
	puts("排序前：");
	for (int i = 0; i < N; i++)
	{
		str[i] = rand() % 100;
		printf(" %d", str[i]);
	}

	for (int i = 0; i < N - 1; i++)//N-1表示当有1个元素时不需要排序
	{
		for (int j = i + 1; j < N; j++)
		{
			if (str[i] > str[j])
			{
				int temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	puts("\n排序后：");
	for (int i = 0; i < N; i++)
	{
		printf(" %d", str[i]);
	}
	printf("\nmax=%d\nmin=%d", str[N - 1], str[0]);
}