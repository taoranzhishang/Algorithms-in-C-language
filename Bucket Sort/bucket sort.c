#include <stdio.h>
#include <time.h>
#define N 10
#define M 100

void main()
{
	/*
	ȡʱ�䴴�������
	*/
	time_t t;
	unsigned int data = time;//ȡʱ����Ϊ�����
	srand(&t);//�������������

	/*
	����һ������Ϊ10���������
	*/
	puts("����ǰ��");
	int arr[N] = { 0 };//��������arr��ȫ��Ԫ�س�ʼ��Ϊ0
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;//����Ԫ��ΪС��100������
		printf("%3d", arr[i]);//���ԭʼ�����ÿһ��Ԫ��
	}

	int bucket[M] = { 0 };//����һ������bucket��ȫ��Ԫ�س�ʼ��Ϊ0

	/*
	��arrԪ�ص�ֵ��Ϊbucket������
	�����ݸ�������bucket��Ԫ��ֵ�����޸ģ�arr����Ԫ��ֵ����һ�Σ�bucket�����Ӧ����Ԫ�ص�ֵ����һ��
	*/
	for (int i = 0; i < N; i++)
	{
		int index = arr[i];
		bucket[index]++;
	}

	/*
	����bucket��ȫ��Ԫ�أ�ÿһ��Ԫ��ֵ����arrԪ�س��ֵĴ�����δ����Ϊ0������һ��Ϊ1������
	���ݴ��������Ӧ������bucket����������arr����Ԫ��ֵ
	*/
	puts("\n�����");
	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j <= bucket[i]; j++)
		{
			printf("%3d", i);
		}
	}
}