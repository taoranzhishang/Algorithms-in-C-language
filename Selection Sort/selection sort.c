#include <stdio.h>
#include <time.h>
#define N 10

/*
ʹ��ѡ�����򷨶�һ��������ɳ���Ϊ10�����������������
*/
void main()
{
	/*
	ȡʱ�䴴�������
	*/
	time_t t;
	unsigned int data = time;//ȡNʱ����Ϊ�����
	srand(&t);//�������������

	/*
	����һ������Ϊ10������
	*/
	int arr[N] = { 0 };
	puts("����ǰ��");
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;//����Ԫ��ΪС��100������
		printf(" %d", arr[i]);
	}

	/*
	���±�0��Ԫ�ؿ�ʼ�Ժ�������Ԫ�ؽ��бȽϣ���ǰ�ߴ��ں�����ֵ����
	*/
	for (int i = 0; i < N - 1; i++)//N-1��ʾ����1��Ԫ��ʱ����Ҫ����
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
	�������������
	*/
	puts("\n�����");
	for (int i = 0; i < N; i++)
	{
		printf(" %d", arr[i]);
	}
}