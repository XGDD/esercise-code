#include"MinStack.h"

int main()
{
	MinStack s;
	MinStackInit(&s);
	MinStackPush(&s, 1);
	MinStackPush(&s, 2);
	MinStackPush(&s, 3);
	MinStackPush(&s, 4);
	printf("top = %d\n", MinStackTop(&s));
	printf("size = %d\n", MainSatckSize(&s));
	printf("min = %d\n", MinStackMin(&s));

	MinStackPop(&s);
	MinStackPush(&s, 0);
	MinStackPush(&s, 4);
	printf("top = %d\n", MinStackTop(&s));
	printf("size = %d\n", MainSatckSize(&s));
	printf("min = %d\n", MinStackMin(&s));

	return 0;
}