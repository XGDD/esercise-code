#include"QueueBy2Stack.h"

void InitQueueBy2Stack(Queue* q)
{
	assert(q);
	StackInit(&q->s1);
	StackInit(&q->s2);
}

void QueueBy2StackPush(Queue* q, SDataType data)
{
	assert(q);
	StackPush(&q->s1, data);
}

void QueueBy2StackPop(Queue* q)
{
	assert(q);
	if (!StackEmpty(&q->s2))
	{
		StackPop(&q->s2);
	}
	else
	{
		while (!StackEmpty(&q->s1))
		{
			StackPush(&q->s2, StackTop(&q->s1));
			StackPop(&q->s1);
		}
		StackPop(&q->s2);
	}
}

SDataType QueueBy2StackTop(Queue* q)
{
	assert(q);
	if (!StackEmpty(&q->s2))
	{
		return StackTop(&q->s2);
	}
	else
	{
		while (!StackEmpty(&q->s1))
		{
			StackPush(&q->s2, StackTop(&q->s1));
			StackPop(&q->s1);
		}
		return StackTop(&q->s2);
	}
}

SDataType QueueBy2StackBack(Queue* q)
{
	assert(q);
	if (!StackEmpty(&q->s1))
	{
		return StackTop(&q->s1);
	}
	else
	{
		while (!StackEmpty(&q->s2))
		{
			StackPush(&q->s1, StackTop(&q->s2));
			StackPop(&q->s2);
		}
		return StackTop(&q->s1);
	}
}

int QueueBy2StackSize(Queue* q)
{
	assert(q);
	return StackSize(&q->s1) + StackSize(&q->s2);
}

int IsQueueBy2StackEmpty(Queue* q)
{
	assert(q);
	return StackEmpty(&q->s1) && StackEmpty(&q->s2);//1---ÊÇ¿Õ
}