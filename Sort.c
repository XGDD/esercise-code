#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void InsretSort(int arr[], int size)
{
	int i = 1;
	for (i = 1; i < size; i++)
	{
		int key = arr[i];
		int end = i - 1;
		//找插入位置
		while (end >= 0 && key < arr[end])
		{
			//搬移数据
			arr[end + 1] = arr[end];
			end--;
		}
		//插入元素
		arr[end + 1] = key;
	}
}

void Print(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void ShellSort(int arr[], int size)
{
	int i = 0;
	int gap = 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			int key = arr[i];
			int end = i - gap;
			//找插入位置
			while (end >= 0 && key < arr[end])
			{
				//搬移数据
				arr[end + gap] = arr[end];
				end -= gap;
			}
			//插入元素
			arr[end + gap] = key;
		}
		gap--;
	}	
}

void Swap(int* left, int* right)
{
	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}

void SelectSort(int arr[], int size)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++)
	{
		int maxPos = 0;
		for (j = 1; j < size - i; j++)
		{
			if (arr[j] > arr[maxPos])
				maxPos = j;
		}
		if (maxPos != size - i - 1)
			Swap(&arr[size - i - 1], &arr[maxPos]);
	}
}

void SelectSort_OP(int arr[], int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int maxPos = begin;
		int minPos = begin;
		//找最大与最小元素的位置
		int i = begin + 1;
		while (i <= end)
		{
			if (arr[i] > arr[maxPos])
				maxPos = i;
			else if (arr[i] < arr[minPos])
				minPos = i;
			i++;
		}
		if (maxPos != end)
			Swap(&arr[maxPos], &arr[end]);

		if (minPos == end)
			minPos = maxPos;
		Swap(&arr[minPos], &arr[begin]);

		begin++;
		end--;
	}
}

void HeapAdjust(int arr[], int size, int root)
{
	//默认左孩子是两个孩子中最大元素
	int child = (root << 1) + 1;
	while (child < size)
	{
		//找出左右孩子中最大的那个
		if (child + 1 < size && arr[child] < arr[child + 1])
			child += 1;
		//找出最大元素，放在堆顶
		if (arr[child] > arr[root])
		{
			Swap(&arr[child], &arr[root]);
			root = child;
			child = (root << 1) + 1;
		}
		else
			return;
	}
}

void HeapSort(int arr[], int size)
{
	//建堆----升序---建立大堆
	int end = size - 1;
	int root = (end - 1) >> 1;
	for (; root >= 0; --root)
		HeapAdjust(arr, size, root);

	//排序----删除
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		HeapAdjust(arr, end, 0);
		end--;
	}
}

void BubbleSort(int arr[], int size)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
		}
	}
}