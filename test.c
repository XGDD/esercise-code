#include"SharedStack.h"

int main()
{
	SharedStack s;
	SharedStackInit(&s);
	SharedStackPush(&s, 1, 1);
	SharedStackPush(&s, 2, 1);

	SharedStackPush(&s, 6, 2);
	SharedStackPush(&s, 7, 2);
	SharedStackPop(&s, 2);


	return 0;
}