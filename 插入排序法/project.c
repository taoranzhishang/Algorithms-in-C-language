#include <stdio.h>
#include <time.h>
#define N 10

/*
�ӵ�һ������ʼ����ÿһ�������Ƚ�һ��
*/
void main()
{
	/*
	����һ���������
	*/
	time_t t;
	unsigned int data = time;//ȡNʱ����Ϊ�����
	srand(&t);//�������������
	int str[N] = { 0 };
	puts("����ǰ��");
	for (int i = 0; i < N; i++)
	{
		str[i] = rand() % 100;
		printf(" %d", str[i]);
	}

	for (int i = 0; i < N - 1; i++)//N-1��ʾ����1��Ԫ��ʱ����Ҫ����
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
	puts("\n�����");
	for (int i = 0; i < N; i++)
	{
		printf(" %d", str[i]);
	}
	printf("\nmax=%d\nmin=%d", str[N - 1], str[0]);
}