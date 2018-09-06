#define _CRT_SECURE_NO_WARNINGS 1

#include"PriorityQueue.h"

int main()
{
	PriorityQueue q;
	InitPriorityQueue(&q);
	PushPriorityQueue(&q, 4, (&q)->hp._compare);
	HPDataType ret = SizePriorityQueue(&q);
	PopPriorityQueue(&q);
	ret = SizePriorityQueue(&q);
	return 0;
}