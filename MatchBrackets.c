#include"MatchBrackets.h"

int IsBrackets(char arry[], int i)
{
	if (('(' == arry[i]) || (')' == arry[i]) || ('[' == arry[i]) || (']' == arry[i]) || ('{' == arry[i]) || ('}' == arry[i]))
		return 1;//������
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
		if (IsBrackets(arry, i))//������
		{
			//����������ţ���ջ
			if (('(' == arry[i]) || ('[' == arry[i]) || ('{' == arry[i]))
			{
				StackPush(ps, arry[i]);
				i++;
				continue;
			}
			else if ((')' == arry[i]) || (']' == arry[i]) || ('}' == arry[i]))
			{
				if (0 == ps->top)  //�ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ��������ű������Ŷ�
				{
					printf("�����ű������Ŷ�!\n");
					return;
				}
				else
				{
					k = ps->top;
					char ch = ps->_arry[--k];
					//�����������������ƥ�䣬�����ų�ջ
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
						printf("����ƥ�����\n");
						return;
					}
				}
			}
		}
		else   //�������ţ����ò�����ֱ�������
		{
			i++;
		}
	}
	if (!StackEmpty(ps))
	{
		printf("�����ű������Ŷ࣡\n");
	}
	else
	{
		printf("ƥ����ȷ!\n");
	}

}