#include"Stack.h"

void StackPush_test()
{
	int sz = 0;
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	sz = StackSize(&s);
	printf("%d\n", sz);
	StackPop(&s);
	sz = StackSize(&s);
	printf("%d\n", sz);
	Print(&s);
}

void StackEmpty_test()
{
	Stack s;
	int ret = 0;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	ret = StackEmpty(&s);
	if (ret)
		printf("Õ»Îª¿Õ\n");
	else
	{
		printf("Õ»²»Îª¿Õ\n");
	}
}

int main()
{
	//StackPush_test();
	StackEmpty_test();
	return 0;
}