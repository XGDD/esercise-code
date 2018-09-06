#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include"Heap.h"

typedef struct PriorityQueue
{
	Heap hp;
}PriorityQueue;

void InitPriorityQueue(PriorityQueue* q);
void PushPriorityQueue(PriorityQueue* q, HPDataType data);
void PopPriorityQueue(PriorityQueue* q);
HPDataType TopPriorityQueue(PriorityQueue* q);
int SizePriorityQueue(PriorityQueue* q);
int EmptyPriorityQueue(PriorityQueue* q);

#endif //__PRIORITYQUEUE_H__