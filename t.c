#define _CRT_SECURE_NO_WARNINGS 1

#include"t.h"

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

int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[right - 1] < array[mid])
			return right - 1;
		if (array[left] > array[mid])
			return left;
		else
			return mid;
	}
	else
	{
		if (array[right - 1] > array[mid])
			return right - 1;
		if (array[left] < array[mid])
			return left;
		else
			return mid;
	}
}

int partion_OP(int* array, int left, int right)
{
	int key = array[GetMiddleIndex(array, left, right)];
	int begin = 0;
	int end = right;
	while (begin < end)
	{
		//从左向右找比基准值大的数
		while (begin < end && array[begin] < key)
			begin++;
		//从右向左找比基准值小的数
		while (begin < end && array[end - 1] >= key)
			end--;
		if (begin < end)
			Swap(&array[begin], &array[end - 1]);
	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);
	return begin;
}

void QuickSort(int* array, int left, int right)
{
	Stack s;
	StackInit(&s);
	if (left < right)
	{
		StackPush(&s, right);
		StackPush(&s, left);
		while (!StackEmpty(&s))
		{
			int p = StackTop(&s);
			StackPop(&s);
			int q = StackTop(&s);
			StackPop(&s);
			if (p < q)
			{
				int mid = partion_OP(array, p, q);
				if (mid > p)
				{
					StackPush(&s, mid - 1);
					StackPush(&s, p);
				}
				if (q > mid)
				{
					StackPush(&s, q);
					StackPush(&s, mid + 1);
				}
			}
		}
	}
}
