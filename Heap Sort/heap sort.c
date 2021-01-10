#include <stdio.h>
#include <time.h>
#define LEN 10

/*
数组值互换
*/
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

/*
向下调整堆，使其成为完全二叉树
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
		swap(heap, max_node, parent_node_temp);//子节点与父节点互换
		/*
		递归，交换后对下层做调整，使数组为一个完全二叉树,nax_node是子节点的赋予的值
		连续递归保证每层子节点小于父节点
		*/
		heapify(heap, length, max_node);
	}
}
/*
将随机生成的数组调整为大顶堆
*/
void build_heap(int *heap, int length)
{
	int last_node = length - 1;
	int parent_node = (last_node - 1) / 2;
	for (int i = parent_node; i >= 0; i--)//使用循环自下而上逐层调整为大顶堆，两级间父节点都大于子节点
	{
		heapify(heap, length, i);
	}
}

void heap_sort(int *arr, int length)
{
	build_heap(arr, length);//创建大顶堆
	/*
	开始排序
	*/
	for (int i = length - 1; i >= 0; i--)//自顶向下
	{
		swap(arr, i, 0);//最后节点与根节点交换
		heapify(arr, i, 0);//对交换后的堆做向下调整，使堆再次成为完全二叉树，swap一次，重新调整一次，保持大顶堆
	}
}

/*
输出数组
*/
void display(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d", arr[i]);
	}
}

/*
生成随机数，赋值给数组tree的元素
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
	int tree[LEN] = { 0 };//定义一个数组tree，所有元素初始化为0
	build_tree(tree,LEN);
	puts("排序前：");
	display(tree, LEN);

	heap_sort(tree, LEN);
	puts("\n排序后：");
	display(tree, LEN);

	return 0;
}