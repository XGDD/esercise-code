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
		//是数据，入栈
		if (Data == RPN[i]._op)
		{
			StackPush(&s, RPN[i].data);
			i++;
		}
		else       //是运算符，进行运算
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
	return (&s)->arry[--(&s)->top];//返回当前栈顶元素，就是最后的元素结果，[--(&s)->top]为什么要--呢，是因为出栈的时候top先--，再取元素，top指向的是栈顶元素的上边，这个我在前边的博客中有解释
}