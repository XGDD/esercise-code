#define _CRT_SECURE_NO_WARNINGS 1

#include"MergeSort.h"

void Print(int* array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	if (begin1 > end1)
	{
		while (begin2 <= right)
			temp[index++] = array[begin2++];
	}
	else
	{
		while (begin1 <= mid)
			temp[index++] = array[begin1++];
	}
}

void _MergeSort(int* array, int left, int right, int* temp)
{
	if (right > left)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid + 1, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, (right - left + 1) * sizeof(int));
	}
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(size * sizeof(int));
	if (NULL == temp)
	{
		printf("¿ª±Ù¿Õ¼äÊ§°Ü\n");
		return;
	}
	_MergeSort(array, 0, size - 1, temp);
	free(temp);
}

