#include"RPN.h"

void test()
{
	Cell RPN[] = { { Data, 12 }, { Data, 3 }, { Data, 4 }, { Add, 0 }, { Mul, 0 }, { Data, 6 }, { Sub, 0 }, { Data, 8 }, { Data, 2 }, { Div, 0 }, { Add, 0 } };
	int size = sizeof(RPN) / sizeof(RPN[0]);
	int ret = CalcRPN(RPN, size);
	printf("%d\n", ret);
}

int main()
{
	test();
	return 0;
}