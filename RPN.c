#include"RPN.h"

void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->top = 0;
}

void StackPush(Stack* ps, SDataType data)
{
	assert(ps != NULL);
	ps->arry[ps->top] = data;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps != NULL);
	ps->top--;
}

int CalcRPN(Cell* RPN, int size)
{
	Stack s;
	StackInit(&s);
	int right = 0;
	int left = 0;
	int i = 0;
	int ret = 0;
	assert(RPN != NULL);
	while (i < size)
	{
		//�����ݣ���ջ
		if (Data == RPN[i]._op)
		{
			StackPush(&s, RPN[i].data);
			i++;
		}
		else       //�����������������
		{
			StackPop(&s);
			right = (&s)->arry[(&s)->top];
			StackPop(&s);
			left = (&s)->arry[(&s)->top];
			switch (RPN[i]._op)
			{
			case Add:
				ret = left + right;
				StackPush(&s, ret);
				i++;
				break;
			case Sub:
				ret = left - right;
				StackPush(&s, ret);
				i++;
				break;
			case Mul:
				ret = left * right;
				StackPush(&s, ret);
				i++;
				break;
			case Div:
				ret = left / right;
				StackPush(&s, ret);
				i++;
				break;
			}
		}
	}
	return (&s)->arry[--(&s)->top];//���ص�ǰջ��Ԫ�أ���������Ԫ�ؽ����[--(&s)->top]ΪʲôҪ--�أ�����Ϊ��ջ��ʱ��top��--����ȡԪ�أ�topָ�����ջ��Ԫ�ص��ϱߣ��������ǰ�ߵĲ������н���
}