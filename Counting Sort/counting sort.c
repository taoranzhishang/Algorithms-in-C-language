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
	for (int i = 0; i < LEN; temp[arr[i++]]++);//Ͱ
	/*for (int i = 0; i < LEN; i++)
	{
		int index = arr[i];
		temp[index]++;
	}*/
	//for (int i = 0, j = 0; i < SIZE; i++)while (temp[i]-- > 0)sorted_arr[j++] = i;//���ȶ���д��
	for (int i = 1; i < SIZE; i++)
	{
		temp[i] = temp[i] + temp[i - 1];//���ڴ����ۼӣ������������������
	}

	/*
	�Ӻ���ǰ��arr��Ԫ��ֵ���Ÿ�ֵ���������飬��������������Լ���temp[]��������arr[i]ȷ��
	arr[]��ֵ��iȷ����sorted_arr[]��temp[]ȷ��
	arr[i]��ֵ��sorted[]ʱ��sorted���±�λ������arr��ֵ������temp[]ȷ�����Դ�����
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
	puts("����ǰ��");
	display(arr);
	
	puts("\n�����");
	counting_sort(arr);
	return 0;
}