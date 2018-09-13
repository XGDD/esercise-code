#ifndef __BITMAP_H__
#define __BITMAP_H__

#include<assert.h>
#include<stdio.h>

typedef struct BitMap
{
	int* _pBit;
	int _capacit;//Ҫ�����ֽڵĴ�С
	int _size;//bitλΪ1�ĸ���
}BitMap;

void InitBitMap(BitMap* pBmp, int totalBit);
void SetMap(BitMap* pBmp, int which);//��1
void ReSetMap(BitMap* pBmp, int which);//��0
int TestBitMap(BitMap* pBmp, int which);
int SizeBitMap(BitMap* pBmp);
void DestroyBitMap(BitMap* pBmp);

#endif //__BITMAP_H__