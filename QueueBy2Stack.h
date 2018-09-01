#ifndef __QUEUEBY2STACK_H__
#define __QUEUEBY2STACK_H__

#include<stdio.h>
#include<assert.h>
#include"Stack.h"

#define MaxSize 10

typedef struct Queue
{
	Stack s1;
	Stack s2;
}Queue;

void QueueBy2StackPush(Queue* q, SDataType data);
void QueueBy2StackPop(Queue* q);
SDataType QueueBy2StackTop(Queue* q);
SDataType QueueBy2StackBack(Queue* q);
int QueueBy2StackSize(Queue* q);
int IsQueueBy2StackEmpty(Queue* q);

#endif //__QUEUEBY2STACK_H__