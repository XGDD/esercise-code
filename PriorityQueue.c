#define _CRT_SECURE_NO_WARNINGS 1

#include"PriorityQueue.h"

void InitPriorityQueue(PriorityQueue* q)
{
	assert(q);
	InitHeap(q);
}

void PushPriorityQueue(PriorityQueue* q, HPDataType data)
{
	assert(q);
	InsertHeap(&(q->hp), data, q->hp._compare);
}

void PopPriorityQueue(PriorityQueue* q)
{
	assert(q);
	RemoveHeap(&(q->hp), q->hp ._compare);
}

HPDataType TopPriorityQueue(PriorityQueue* q)
{
	assert(q);
	return q->hp._hp[0];
}

int SizePriorityQueue(PriorityQueue* q)
{
	assert(q);
	return q->hp._size;
}

int EmptyPriorityQueue(PriorityQueue* q)
{
	return q->hp._size;
}