#include <stdio.h>
#include <time.h>
#define LEN 10

/*
����ֵ����
*/
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

/*
���µ����ѣ�ʹ���Ϊ��ȫ������
*/
void heapify(int *heap, int length, int parent_node_temp)
{
	int left_node = 2 * parent_node_temp + 1;
	int right_node = 2 * parent_node_temp + 2;
	int max_node = parent_node_temp;

	if (left_node<length && heap[left_node]>heap[max_node])
	{
		max_node = left_node;
	}
	if (right_node<length && heap[right_node]>heap[max_node])
	{
		max_node = right_node;
	}
	if (max_node != parent_node_temp)
	{
		swap(heap, max_node, parent_node_temp);//�ӽڵ��븸�ڵ㻥��
		/*
		�ݹ飬��������²���������ʹ����Ϊһ����ȫ������,nax_node���ӽڵ�ĸ����ֵ
		�����ݹ鱣֤ÿ���ӽڵ�С�ڸ��ڵ�
		*/
		heapify(heap, length, max_node);
	}
}
/*
��������ɵ��������Ϊ�󶥶�
*/
void build_heap(int *heap, int length)
{
	int last_node = length - 1;
	int parent_node = (last_node - 1) / 2;
	for (int i = parent_node; i >= 0; i--)//ʹ��ѭ�����¶���������Ϊ�󶥶ѣ������丸�ڵ㶼�����ӽڵ�
	{
		heapify(heap, length, i);
	}
}

void heap_sort(int *arr, int length)
{
	build_heap(arr, length);//�����󶥶�
	/*
	��ʼ����
	*/
	for (int i = length - 1; i >= 0; i--)//�Զ�����
	{
		swap(arr, i, 0);//���ڵ�����ڵ㽻��
		heapify(arr, i, 0);//�Խ�����Ķ������µ�����ʹ���ٴγ�Ϊ��ȫ��������swapһ�Σ����µ���һ�Σ����ִ󶥶�
	}
}

/*
�������
*/
void display(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d", arr[i]);
	}
}

/*
�������������ֵ������tree��Ԫ��
*/
void build_tree(int *arr,int length)
{
	time_t t;
	unsigned int data = time;
	srand(&t);
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
	}
}

int main()
{
	int tree[LEN] = { 0 };//����һ������tree������Ԫ�س�ʼ��Ϊ0
	build_tree(tree,LEN);
	puts("����ǰ��");
	display(tree, LEN);

	heap_sort(tree, LEN);
	puts("\n�����");
	display(tree, LEN);

	return 0;
}