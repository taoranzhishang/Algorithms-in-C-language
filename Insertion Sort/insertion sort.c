#include <stdio.h>
#include <time.h>
#define LEN 10

/*
������arr[1]��ʼ���Ƚϣ����ߴ���ǰ�ߣ��򻥻�
���һ�λ�������ǰ�Ƚϣ���ǰ����Ƚϵ���
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
�������
*/
void display(int arr[])
{
	for (int i = 0; i < LEN; i++)
	{
		printf("%3d",arr[i]);
	}
}
/*
�����������
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
	puts("����ǰ��");
	display(arr);

	insertion_sort(arr);
	puts("\n�����");
	display(arr);
	return 0;
}