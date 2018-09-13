#define _CRT_SECURE_NO_WARNINGS 1

#include"BitMap.h"

void test()
{
	BitMap pBmp;
	int ret = 0;
	InitBitMap(&pBmp, 10);
	SetMap(&pBmp, 8);
	ret = TestBitMap(&pBmp, 8);
	printf("%d\n", ret);
	ReSetMap(&pBmp, 8);
	TestBitMap(&pBmp, 8);

}

int main()
{
	test();

	return 0;
}