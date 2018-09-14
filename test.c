#define _CRT_SECURE_NO_WARNINGS 1

#include"BloomFilter.h"

void test()
{
	PSTRTINT HashFunc[] = { StrToINT1, StrToINT2, StrToINT3, StrToINT4, StrToINT5 };
	BloomFilter bf;
	InitBloomFilter(&bf, 5, &HashFunc);
	InsertBloomFilter(&bf, "Сţ");
	InsertBloomFilter(&bf, "С��");
	InsertBloomFilter(&bf, "С��");
	InsertBloomFilter(&bf, "С��");
	InsertBloomFilter(&bf, "С��");

	int ret = 0;
	ret = SizeBloomFilter(&bf);
	printf("%d\n", ret);

	if (1 == IsInBloomFilter(&bf, "Сţ"))
	{
		printf("�ҵ���\n");
	}
	else
		printf("û�ҵ���\n");

	if (1 == IsInBloomFilter(&bf, "����"))
	{
		printf("�ҵ���\n");
	}
	else 
		printf("û�ҵ���\n");


}

int main()
{
	test();

	return 0;
}