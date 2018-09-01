#include"StackBy2Queue.h"

void StackBy2QueueInit(StackBy2Queue* q)
{
	assert(q);
	QueueInit(&q->q1);
	QueueInit(&q->q2);
}

void StackBy2QueuePush(StackBy2Queue* q, QDataType data)
{
	assert(q);
	if (!QueueIsEmpty(&q->q1))//队1中有数据
	{
		QueuePush(&q->q1, data);
	}
	else//队2中有数据或两个队都为空
	{
		QueuePush(&q->q2, data);
	}
}

void StackBy2QueuePop(StackBy2Queue* q)
{
	assert(q);
	if (!QueueIsEmpty(&q->q1))//队1中有数据
	{
		while (QueueSize(&q->q1)>2)//因为带有头结点，是所以是>2
		{
			QueuePush(&q->q2, QueueFront(&q->q1));
			QueuePop(&q->q1);
		}
		QueuePop(&q->q1);
	}
	else
	{
		while (QueueSize(&q->q2)>2)//因为带有头结点，是所以是>2
		{
			QueuePush(&q->q1, QueueFront(&q->q2));
			QueuePop(&q->q2);
		}
		QueuePop(&q->q2);
	}
}

QDataType StackBy2QueueTop(StackBy2Queue* q)
{
	assert(q);
	if (!QueueIsEmpty(&q->q1))
	{
		return QueueBack(&q->q1);
	}
	else
	{
		return QueueBack(&q->q2);
	}
}

int StackBy2QueueSize(StackBy2Queue* q)
{
	assert(q);
	return QueueSize(&q->q1) + QueueSize(&q->q2) - 1;
}

int StackBy2QueueEmpty(StackBy2Queue* q)
{
	if (2 == QueueSize(&q->q1) + (QueueSize(&q->q2)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}