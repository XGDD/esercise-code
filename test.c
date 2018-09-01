#include"QueueBy2Stack.h"

int main()
{
	Queue q;
	InitQueueBy2Stack(&q);
	QueueBy2StackPush(&q, 1);
	QueueBy2StackPush(&q, 2);
	QueueBy2StackPush(&q, 3);
	printf("Size = %d\n", QueueBy2StackSize(&q));
	printf("Front = %d\n", QueueBy2StackTop(&q));
	printf("Back = %d\n", QueueBy2StackBack(&q));

	QueueBy2StackPop(&q);
	printf("Size = %d\n", QueueBy2StackSize(&q));
	printf("Front = %d\n", QueueBy2StackTop(&q));
	printf("Back = %d\n", QueueBy2StackBack(&q));

	QueueBy2StackPush(&q, 4);
	QueueBy2StackPush(&q, 5);
	printf("Size = %d\n", QueueBy2StackSize(&q));
	printf("Front = %d\n", QueueBy2StackTop(&q));
	printf("Back = %d\n", QueueBy2StackBack(&q));

	return 0;
}