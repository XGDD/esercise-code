#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->top = 0;
}

void Print(Stack* ps)
{
	assert(ps != NULL);
	while (ps->top--)
	{
		printf("%d ", ps->_arry[ps->top]);
	}
	printf("\n");
}

void StackPush(Stack* ps, SDataType data)
{
	assert(ps != NULL);
	if (ps->top == MaxSize)
		return;
	else
	{	
		ps->_arry[ps->top] = data;
		ps->top++;
	}
}

void StackPop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top)
		ps->top--;
}

int StackSize(Stack* ps)
{
	assert(ps != NULL);
	return ps->top;
}

int StackEmpty(Stack* ps)
{
	assert(ps != NULL);
	if (0 == ps->top)
		return 1;
	else
		return 0;
}

SDataType StackTop(Stack* ps)
{
	assert(ps != NULL);
	return ps->_arry[ps->top - 1];
}