#define _CRT_SECURE_NO_WARNINGS 1

#include"QuickSort.h"

void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

void Print(int* array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int partion1(int*array, int left, int right)
{
	//�һ�׼ֵ
	int key = array[right - 1];
	int begin = 0;
	int end = right;
	while (begin < end)
	{
		//���������ұȻ�׼ֵ�����
		while (begin < end && array[begin] < key)
			begin++;
		//���������ұȻ�׼ֵС����
		while (begin < end && array[end - 1] >= key)
			end--;
		if (begin < end)
			Swap(&array[begin], &array[end - 1]);
	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);
	return begin;
}

int partion2(int*array, int left, int right)
{
	//�һ�׼ֵ
	int key = array[right - 1];
	int begin = 0;
	int end = right - 1;
	while (begin < end)
	{
		//���������ұȻ�׼ֵ�����
		while (begin <= end && array[begin] < key)
			begin++;
		if (begin <= end)
		{
			array[end] = array[begin];
			end--;
		}
		//���������ұȻ�׼ֵС����
		while (begin <= end && array[end] > key)
			end--;
		if (begin <= end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;
}

int partion3(int*array, int left, int right)
{
	//�һ�׼ֵ
	int key = array[right - 1];
	int cur = 0;
	int prev = cur - 1;
	while (cur < right)
	{
		while (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);
		cur++;
	}
	if (++prev != right - 1)
		Swap(&array[prev++], &array[right - 1]);
	return prev;
}

int partion_OP(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		while (left < mid)
		{

		}
		if (array[left] < array[mid])
			left++;
		if (array[left] > array[mid])
			Swap(&array[left], &array[mid]);
		else
			;
	}
	else 
	{
		if (array[left] > array[mid])
			left++;
		if (array[left] < array[mid])
			Swap(&array[left], &array[mid]);
		else
			;
	}
	return mid;
}

void QuickSort(int* array, int left, int right)
{
	if (left < right)
	{
		//���ջ�׼ֵ��left��right������仮�ֳ�������
		int boundry = partion_OP(array, left, right);
		//������벿��
		QuickSort(array, left, boundry);
		//�����Ұ벿��
		QuickSort(array, boundry + 1, right);
	}
}
