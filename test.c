#include"IsStackValidOrder.h"

int main()
{
	int InArr[] = { 1, 2, 3, 4, 5 };
	int OutArr[] = { 4, 5, 3, 2, 1 };
	int ret = 0;
	ret = IsStackValidOrder(InArr, 5, OutArr, 5);
	if (1 == ret)
	{
		printf("∆•≈‰≥…π¶\n");
	}
	else
	{
		printf("∆•≈‰ ß∞‹\n");
	}

	return 0;
}