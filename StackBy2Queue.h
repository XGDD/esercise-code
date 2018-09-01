#ifndef __STACKBY2QUEUE_H__
#define __STACKBY2QUEUE_H__

#include"Queue.h"

typedef struct StackBy2Queue
{
	Queue q1;
	Queue q2;
}StackBy2Queue;

void StackBy2QueueInit(StackBy2Queue* q);
void StackBy2QueuePush(StackBy2Queue* q, QDataType data);
void StackBy2QueuePop(StackBy2Queue* q);
QDataType StackBy2QueueTop(StackBy2Queue* q);
int StackBy2QueueSize(StackBy2Queue* q);
int StackBy2QueueEmpty(StackBy2Queue* q);


#endif //__STACKBY2QUEUE_H__