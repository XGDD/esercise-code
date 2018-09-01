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
	if (StackEmpty(&s->_min))//���minջΪ�գ�˵��ѹ����ǵ�һ��Ԫ�أ��ѵ�һ��Ԫ��Ҳѹ��minջ��
	{
		StackPush(&s->_min, data);
	}
	else//��ѹ������ݺ�minջջ��Ԫ�رȽϣ���data<minջ��Ԫ�أ�dataѹ��minջ
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