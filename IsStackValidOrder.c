#include"IsStackValidOrder.h"

int IsStackValidOrder(int* InArr, int InSize, int* OutArr, int OutSize)
{
	int inIdx = 0;
	int outIdx = 0;
	Stack s;
	StackInit(&s);
	if (OutSize != InSize)
	{
		return 0;
	}
	while (outIdx < OutSize)
	{
		if (inIdx>InSize)
		{
			return;
		}
		else
		{
			while (StackEmpty(&s) || OutArr[outIdx] != StackTop(&s))
			{
				StackPush(&s, InArr[inIdx++]);
			}
			StackPop(&s);
			outIdx++;
		}
	}
	return 1;
}