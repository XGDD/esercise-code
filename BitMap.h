#ifndef __BITMAP_H__
#define __BITMAP_H__

#include<assert.h>
#include<stdio.h>

typedef struct BitMap
{
	int* _pBit;
	int _capacit;//要开辟字节的大小
	int _size;//bit位为1的个数
}BitMap;

void InitBitMap(BitMap* pBmp, int totalBit);
void SetMap(BitMap* pBmp, int which);//置1
void ReSetMap(BitMap* pBmp, int which);//置0
int TestBitMap(BitMap* pBmp, int which);
int SizeBitMap(BitMap* pBmp);
void DestroyBitMap(BitMap* pBmp);

#endif //__BITMAP_H__