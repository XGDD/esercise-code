#include"Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	PrintQueue(&q);
	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	int ret = QueueIsEmpty(&q);
	if (1 == ret)
	{
		printf("¶Ó¿Õ\n");
	}
	else
	{
		printf("¶Ó²»¿Õ\n");
	}

	return 0;
}