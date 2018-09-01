#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void InitSeqList(PSeqList pSeq)
{
	assert(pSeq != NULL);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(DataType)*MAX);
}

void PushBack(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满！\n");
		return;
	}
	pSeq->data[pSeq->sz] = data;
	pSeq->sz++;
}

void PrintSeqList(PSeqList pSeq)
{
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}

void PopBack(PSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表已空!\n");
	}
	pSeq->sz--;
}

void PushFront(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满!\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = data;
	pSeq->sz++;
}

void PopFront(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表已空!\n");
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

int Find(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
		{
			printf("%d\n", i);
			return;
		}
	}
	return -1;
}

void Insert(PSeqList pSeq, int pos, DataType data)
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	if (pos >= 0 && pos < pSeq->sz)
	{
		if (pSeq->sz == MAX)
		{
			printf("顺序表已满!\n");
			return;
		}
		for (i = 0; i < pSeq->sz; i++)
		{
			if (i == pos)
			{
				for (j = pSeq->sz - 1; j >= pos; j--)
				{
					pSeq->data[j + 1] = pSeq->data[j];
				}
			}
		}
		pSeq->data[pos] = data;
		pSeq->sz++;
	}
}

void Erase(PSeqList pSeq, int pos)
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (i == pos)
		{
			for (j = i; j<pSeq->sz - 1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
		}
	}
	pSeq->sz--;
}

void Remove(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
		{
			for (j = i; j < pSeq->sz - 1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
		}
	}
	pSeq->sz--;
}

void RemoveAll(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	int i = 0;
	int count = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == data)
		{
			;
		}
		else
		{
			pSeq->data[count] = pSeq->data[i];
			count++;
		}
	}
	pSeq->sz = count;
}

int Size(PSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

int Empty(PSeqList pSeq)
{
	return pSeq->sz == 0;
}

void BubbleSort(PSeqList pSeq)
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		for (j = 0; j < pSeq->sz - 1 - i; j++)
		{
			if (pSeq->data[j] < pSeq->data[j + 1])
			{
				tmp = pSeq->data[j];
				pSeq->data[j] = pSeq->data[j + 1];
				pSeq->data[j + 1] = tmp;
			}
		}
	}
}

void SelectSort(PSeqList pSeq)
{
	assert(pSeq != NULL);
	//int max = 0;
	int i = 0;
	int tmp = 0;
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		int maxPos = i;
		int j = 0;
		for (j = i + 1; j < pSeq->sz; j++)
		{
			if (pSeq->data[j]>pSeq->data[maxPos])
			{
				maxPos = j;
			}
		}
		if (pSeq->data[i] < pSeq->data[maxPos])
		{
			tmp = pSeq->data[i];
			pSeq->data[i] = pSeq->data[maxPos];
			pSeq->data[maxPos] = tmp;
		}
	}
}

void swap(int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectSortOP(PSeqList pSeq)
{
	assert(pSeq != NULL);
	int start = 0;
	int end = pSeq->sz - 1;
	while (start < end)
	{
		int maxPos = start;
		int minPos = start;
		int i = 0;
		int j = 0;
		for (i = start + 1; i < end; i++)
		{
			if (pSeq->data[i]>pSeq->data[maxPos])
			{
				maxPos = i;
			}
			if (pSeq->data[i] < pSeq->data[minPos])
			{
				minPos = i;
			}
		}
		if (minPos != start)
		{
			swap(pSeq->data + minPos, pSeq->data + start);
		}
		if (maxPos == start)
		{
			maxPos = minPos;
		}
		if (minPos != end)
		{
			swap(pSeq->data + minPos, pSeq->data + end);
		}
		start++;
		end--;
	}
}

int BinarySearch(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	int start = 0;
	int end = pSeq->sz - 1;
	int mid = (start + end) / 2;
	while (pSeq->data [mid]!=data && start < end)
	{
		if (pSeq->data[mid] < data)
		{
			start = mid + 1;
		}
		else if (pSeq->data[mid] > data)
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	if (pSeq->data[mid] == data)
	{
		return mid;
	}
	return -1;
}

int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d)
{
	assert(pSeq != NULL);
	int mid = 0;
	if (left > right)
		return -1;
	mid = (left + right) / 2;
	if (d == pSeq->data[mid])
		return mid;
	if (d < pSeq->data[mid])
		return BinarySearch_R(pSeq, left, mid - 1, d);
	else
		return BinarySearch_R(pSeq, mid + 1, right, d);
}