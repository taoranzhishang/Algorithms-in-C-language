#include <stdio.h>
#include <time.h>
#define N 10
#define M 100

void main()
{
	/*
	取时间创建随机数
	*/
	time_t t;
	unsigned int data = time;//取时间作为随机数
	srand(&t);//创建随机数种子

	/*
	生成一个长度为10的随机数组
	*/
	puts("排序前：");
	int arr[N] = { 0 };//定义数组arr，全部元素初始化为0
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;//数组元素为小于100的整数
		printf("%3d", arr[i]);//输出原始数组的每一个元素
	}

	int bucket[M] = { 0 };//定义一个数组bucket，全部元素初始化为0

	/*
	将arr元素的值作为bucket的索引
	并根据该索引对bucket的元素值进行修改，arr数组元素值出现一次，bucket数组对应索引元素的值自增一次
	*/
	for (int i = 0; i < N; i++)
	{
		int index = arr[i];
		bucket[index]++;
	}

	/*
	遍历bucket的全部元素，每一个元素值代表arr元素出现的次数，未出现为0，出现一次为1，……
	根据次数输出对应次数的bucket的索引，即arr数组元素值
	*/
	puts("\n排序后：");
	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j <= bucket[i]; j++)
		{
			printf("%3d", i);
		}
	}
}