#include"MatchBrackets.h"

int IsBrackets(char arry[], int i)
{
	if (('(' == arry[i]) || (')' == arry[i]) || ('[' == arry[i]) || (']' == arry[i]) || ('{' == arry[i]) || ('}' == arry[i]))
		return 1;//是括号
	else
		return 0;
}

int StackSize(Stack* ps)
{
	assert(ps != NULL);
	return ps->top;
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

int StackEmpty(Stack* ps)
{
	assert(ps != NULL);
	if (0 == ps->top)
		return 1;
	else
		return 0;
}

void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->top = 0;
}

void MatchBrackets(Stack* ps, int sz, char arry[])
{
	int i = 0;
	int k = 0;
	assert(ps != NULL);
	//char ch = 0;
	while (i < sz)
	{
		if (IsBrackets(arry, i))//是括号
		{
			//如果是左括号，入栈
			if (('(' == arry[i]) || ('[' == arry[i]) || ('{' == arry[i]))
			{
				StackPush(ps, arry[i]);
				i++;
				continue;
			}
			else if ((')' == arry[i]) || (']' == arry[i]) || ('}' == arry[i]))
			{
				if (0 == ps->top)  //判断栈是否为空，若为空，则右括号比左括号多
				{
					printf("右括号比左括号多!\n");
					return;
				}
				else
				{
					k = ps->top;
					char ch = ps->_arry[--k];
					//如果右括号与左括号匹配，左括号出栈
					if (((')' == arry[i]) && ('(' == ch)) ||
						((']' == arry[i]) && ('[' == ch)) ||
						(('}' == arry[i]) && ('{' == ch)))
					{

						StackPop(ps);
						i++;
						continue;
					}
					else
					{
						printf("括号匹配出错！\n");
						return;
					}
				}
			}
		}
		else   //不是括号，不用操作，直接向后走
		{
			i++;
		}
	}
	if (!StackEmpty(ps))
	{
		printf("左括号比右括号多！\n");
	}
	else
	{
		printf("匹配正确!\n");
	}

}