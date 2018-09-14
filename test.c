#define _CRT_SECURE_NO_WARNINGS 1

#include"BloomFilter.h"

void test()
{
	PSTRTINT HashFunc[] = { StrToINT1, StrToINT2, StrToINT3, StrToINT4, StrToINT5 };
	BloomFilter bf;
	InitBloomFilter(&bf, 5, &HashFunc);
	InsertBloomFilter(&bf, "小牛");
	InsertBloomFilter(&bf, "小李");
	InsertBloomFilter(&bf, "小王");
	InsertBloomFilter(&bf, "小找");
	InsertBloomFilter(&bf, "小熊");

	int ret = 0;
	ret = SizeBloomFilter(&bf);
	printf("%d\n", ret);

	if (1 == IsInBloomFilter(&bf, "小牛"))
	{
		printf("找到了\n");
	}
	else
		printf("没找到了\n");

	if (1 == IsInBloomFilter(&bf, "老田"))
	{
		printf("找到了\n");
	}
	else 
		printf("没找到了\n");


}

int main()
{
	test();

	return 0;
}