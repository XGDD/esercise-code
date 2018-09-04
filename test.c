#include"StackBy2Queue.h"

int main()
{
	StackBy2Queue q;
	StackBy2QueueInit(&q);
	StackBy2QueuePush(&q, 1);
	StackBy2QueuePush(&q, 2);
	StackBy2QueuePush(&q, 3);
	StackBy2QueuePush(&q, 4);
	printf("top = %d\n", StackBy2QueueTop(&q));
	printf("size = %d\n", StackBy2QueueSize(&q));

	StackBy2QueuePop(&q);
	StackBy2QueuePop(&q);
	StackBy2QueuePop(&q);
	StackBy2QueuePop(&q);
	printf("top = %d\n", StackBy2QueueTop(&q));
	printf("size = %d\n", StackBy2QueueSize(&q));
	int ret = StackBy2QueueEmpty(&q);
	if (ret == 1)
	{
		printf("Õ»Îª¿Õ\n");
	}
	else
	{
		printf("Õ»²»Îª¿Õ\n");
	}

	return 0;
}