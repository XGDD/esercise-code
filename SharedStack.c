#include"SharedStack.h"

void SharedStackInit(SharedStack* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < MaxSize; i++)
	{
		ps->arry[i] = 0;
	}
	ps->top1 = 0;
	ps->top2 = MaxSize - 1;
}

void SharedStackPush(SharedStack* ps, SDataType data, int which)
{
	assert(ps);
	if (ps->top1 > ps->top2)
	{
		return;
	}
	else
	{
		if (1 == which)
		{
			ps->arry[ps->top1++] = data;
		}
		else
		{
			ps->arry[ps->top2--] = data;
		}
	}
}


void SharedStackPop(SharedStack* ps, int which)
{
	assert(ps);
	if (0 == ps->top1  && ps->top2 == MaxSize - 1)//如果栈里没有元素，不要出栈
	{
		return;
	}
	else
	{
		if (1 == which)
		{
			ps->top1--;
		}
		else
		{
			ps->top2++;
		}
	}
}