#define _CRT_SECURE_NO_WARNINGS 1

#include"BloomFilter.h"

void InitBloomFilter(BloomFilter* bf, int capacity, PSTRTINT* HashFunc)
{
	assert(bf);
	int i = 0;
	InitBitMap(&bf->_bmp, capacity * 5);//一个字符串对应5个比特位
	bf->_size = 0;
	for (i = 0; i < 5; i++)
	{
		bf->_HashFunc[i] = HashFunc[i];
	}
}

void InsertBloomFilter(BloomFilter* bf, const char* str)
{
	assert(bf);
	int hashAddr1, hashAddr2, hashAddr3, hashAddr4, hashAddr5;
	hashAddr1 = bf->_HashFunc[0](str) % bf->_bmp._capacit;
	SetMap(&bf->_bmp, hashAddr1);
	hashAddr2 = bf->_HashFunc[1](str) % bf->_bmp._capacit;
	SetMap(&bf->_bmp, hashAddr2);
	hashAddr3 = bf->_HashFunc[2](str) % bf->_bmp._capacit;
	SetMap(&bf->_bmp, hashAddr3);
	hashAddr4 = bf->_HashFunc[3](str) % bf->_bmp._capacit;
	SetMap(&bf->_bmp, hashAddr4);
	hashAddr5 = bf->_HashFunc[4](str) % bf->_bmp._capacit;
	SetMap(&bf->_bmp, hashAddr5);
	bf->_size++;
}

int IsInBloomFilter(BloomFilter* bf, const char* str)
{
	assert(bf);
	int hashAddr1, hashAddr2, hashAddr3, hashAddr4, hashAddr5;
	hashAddr1 = bf->_HashFunc[0](str) % bf->_bmp._capacit;
	hashAddr2 = bf->_HashFunc[1](str) % bf->_bmp._capacit;
	hashAddr3 = bf->_HashFunc[2](str) % bf->_bmp._capacit;
	hashAddr4 = bf->_HashFunc[3](str) % bf->_bmp._capacit;
	hashAddr5 = bf->_HashFunc[4](str) % bf->_bmp._capacit;
	if (TestBitMap(&bf->_bmp, hashAddr1) == 0)
		return 0;
	else if (TestBitMap(&bf->_bmp, hashAddr2) == 0)
		return 0;
	else if (TestBitMap(&bf->_bmp, hashAddr3) == 0)
		return 0;
	else if (TestBitMap(&bf->_bmp, hashAddr4) == 0)
		return 0;
	else if (TestBitMap(&bf->_bmp, hashAddr5) == 0)
		return 0;
	return 1;
}

int SizeBloomFilter(BloomFilter* bf)
{
	assert(bf);
	return bf->_size;
}

void DestroyBloomFilter(BloomFilter* bf)
{
	assert(bf);
	DestroyBitMap(&bf->_bmp);
	bf->_size = 0;
}