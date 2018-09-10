#define _CRT_SECURE_NO_WARNINGS 1

#include"HashImTable.h"

void test()
{
	HT ht;
	InitHashTable(&ht, 10, DefToINT);
	InsertHashTable(&ht, "9527", StrToINT);
	InsertHashTable(&ht, "秋香", StrToINT);
	InsertHashTable(&ht, "石榴姐", StrToINT);
//	InsertHashTable(&ht, "管家", StrToINT);
	printf("%d\n", SizeHashTable(&ht));

	if (FindHashTable(&ht, "石榴姐") != -1)
		printf("是 唐伯虎点秋香中的人物\n");
	else 
		printf("不是 唐伯虎点秋香中的人物\n");

	if (FindHashTable(&ht, "轮轮") != -1)
		printf("是 唐伯虎点秋香中的人物\n");
	else
		printf("不是 唐伯虎点秋香中的人物\n");

	DestroyHashTable(&ht);
}

int main()
{
	test();

	return 0;
}