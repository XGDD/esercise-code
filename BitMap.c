#define _CRT_SECURE_NO_WARNINGS 1

#include"BitMap.h"

void InitBitMap(BitMap* pBmp, int totalBit)
{
	assert(pBmp);
	int N = ((totalBit >> 5) + 1);
	pBmp->_pBit = (int*)malloc(N);
	memset(pBmp->_pBit, 0, sizeof(int)* N);
	pBmp->_capacit = totalBit;
	pBmp->_size = 0;
}

void SetMap(BitMap* pBmp, int which)
{
	assert(pBmp);
	int index = 0;
	int pos = 0;
	if (which > pBmp->_capacit)
		return;
	index = which >> 5;
	pos = which % 32;
	pBmp->_pBit[index] |= (1 << pos);
	pBmp->_size++;
}

void ReSetMap(BitMap* pBmp, int which)
{
	assert(pBmp);
	int index = 0;
	int pos = 0;
	if (which > pBmp->_capacit)
		return;
	index = which >> 5;
	pos = which % 32;
	pBmp->_pBit[index] &= ~(1 << pos);
	pBmp->_size--;
}

int TestBitMap(BitMap* pBmp, int which)
{
	assert(pBmp);
	int index = 0;
	int pos = 0;
	index = which >> 5;
	pos = which % 32;
	return pBmp->_pBit[index] & (1 << pos);
}

int SizeBitMap(BitMap* pBmp)
{
	assert(pBmp);
	return pBmp->_size;
}

void DestroyBitMap(BitMap* pBmp)
{
	assert(pBmp);
	free(pBmp->_pBit);
	pBmp->_pBit = NULL;
	pBmp->_capacit = 0;
}