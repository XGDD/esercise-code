#include"MinStack.h"

void MinStackInit(MinStack* s)
{
	assert(s);
	StackInit(&s->_data);
	StackInit(&s->_min);
}

void MinStackPush(MinStack* s, SDataType data)
{
	assert(s);
	StackPush(&s->_data, data);
	if (StackEmpty(&s->_min))//如果min栈为空，说明压入的是第一个元素，把第一个元素也压入min栈中
	{
		StackPush(&s->_min, data);
	}
	else//用压入的数据和min栈栈顶元素比较，若data<min栈顶元素，data压入min栈
	{
		if (data <= StackTop(&s->_min))
		{
			StackPush(&s->_min, data);
		}
	}
}

void MinStackPop(MinStack* s)
{
	assert(s);
	if (StackTop(&s->_data) == StackTop(&s->_min))
	{
		StackPop(&s->_data);
		StackPop(&s->_min);
	}
	StackPop(&s->_data);
}

SDataType MinStackTop(MinStack* s)
{
	assert(s);
	return StackTop(&s->_data);
}

SDataType MinStackMin(MinStack* s)
{
	assert(s);
	return StackTop(&s->_min);
}

int MainSatckSize(MinStack* s)
{
	return StackSize(&s->_data);
}

int IsEmpty(MinStack* s)
{
	return StackEmpty(&s->_data);
}