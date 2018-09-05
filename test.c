#define _CRT_SECURE_NO_WARNINGS 1

#include"HashTable.h"

int main()
{
	HT pHT;
	InitHashTable(&pHT);
	InsertHashTable(&pHT, 23);
	InsertHashTable(&pHT, 33);
	InsertHashTable(&pHT, 44);
	InsertHashTable(&pHT, 43);
	InsertHashTable(&pHT, 54);
	InsertHashTable(&pHT, 3);
	DeleteHashTable(&pHT, 33);
	int ret = FindHashTable(&pHT, 33);
	if (-1 != ret)
	{
		printf("该数在哈希表中\n");
	}
	else
	{
		printf("该数不在哈希表中\n");

	}

	InsertHashTable(&pHT, 33);

	return 0;
}