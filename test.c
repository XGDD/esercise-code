#define _CRT_SECURE_NO_WARNINGS 1

#include"HashTable.h"

void test()
{
	HashBucket pHB;
	InitHashTable(&pHB, 10, DefToINT);
	InsertHashTable(&pHB, 1);
	InsertHashTable(&pHB, 11);
	InsertHashTable(&pHB, 21);
	InsertHashTable(&pHB, 23);
	InsertHashTable(&pHB, 34);
	InsertHashTable(&pHB, 45);
	InsertHashTable(&pHB, 36);
	InsertHashTable(&pHB, 78);
	InsertHashTable(&pHB, 17);
	InsertHashTable(&pHB, 19);
	Print(&pHB);

	DeleteHashTable(&pHB, 11);
	Print(&pHB);

	InsertHashTable(&pHB, 10);
	Print(&pHB);

	DestroyHashTable(&pHB);
}

int main()
{
	test();

	return 0;
}