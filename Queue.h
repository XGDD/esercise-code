#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef struct BTNode* QDataType;

typedef struct QListNode
{
	QDataType data;
	struct QListNode* next;
}QListNode;

typedef struct Queue
{
	struct QListNode* Front;
	struct QListNode* Back;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueIsEmpty(Queue* q);
QListNode* BuyQListNode(QDataType data);
void PrintQueue(Queue* q);

#endif //__QUEUE_H__