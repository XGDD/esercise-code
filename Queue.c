#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	QListNode* p = (QListNode*)malloc(sizeof(QListNode));
	if (NULL == p)
	{
		printf("创建结点失败\n");
		return;
	}
	else
	{
		p->data = 0;
		p->next = NULL;
	}
	q->Back = q->Front = p;
}

void PrintQueue(Queue* q)
{
	assert(q);
	QListNode* cur = q->Front;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("OVER\n");
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QListNode* NewNode = BuyQListNode(data);
	q->Back->next = NewNode;
	q->Back = NewNode;
}

void QueuePop(Queue* q)
{
	assert(q);
	QListNode* Del;
	if (q->Back != q->Front)//说明队中有元素，可以删除
	{
		Del = q->Front->next;
		q->Front->next = Del->next;
		free(Del);
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->Front->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->Back->data;
}

int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QListNode* cur = q->Front;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int QueueIsEmpty(Queue* q);
QListNode* BuyQListNode(QDataType data)
{
	QListNode* NewNode = (QListNode*)malloc(sizeof(QListNode));
	if (NULL == NewNode)
	{
		printf("创建结点失败！\n");
		return;
	}
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}