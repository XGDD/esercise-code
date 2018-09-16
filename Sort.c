#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void InsretSort(int arr[], int size)
{
	int i = 1;
	for (i = 1; i < size; i++)
	{
		int key = arr[i];
		int end = i - 1;
		//�Ҳ���λ��
		while (end >= 0 && key < arr[end])
		{
			//��������
			arr[end + 1] = arr[end];
			end--;
		}
		//����Ԫ��
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
			//�Ҳ���λ��
			while (end >= 0 && key < arr[end])
			{
				//��������
				arr[end + gap] = arr[end];
				end -= gap;
			}
			//����Ԫ��
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
		//���������СԪ�ص�λ��
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
	//Ĭ���������������������Ԫ��
	int child = (root << 1) + 1;
	while (child < size)
	{
		//�ҳ����Һ����������Ǹ�
		if (child + 1 < size && arr[child] < arr[child + 1])
			child += 1;
		//�ҳ����Ԫ�أ����ڶѶ�
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
	//����----����---�������
	int end = size - 1;
	int root = (end - 1) >> 1;
	for (; root >= 0; --root)
		HeapAdjust(arr, size, root);

	//����----ɾ��
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