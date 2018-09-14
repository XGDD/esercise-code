#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__

#include"BitMap.h"
#include<assert.h>
#include"Common.h"
#include<stdio.h>

typedef int(*PSTRTINT)(const char*);//����ָ�룬ָ�������ϣ����
typedef struct BloomFilter
{
	BitMap _bmp;
	int _size;
	PSTRTINT _HashFunc[5];
}BloomFilter;

void InitBloomFilter(BloomFilter* bf, int capacity, PSTRTINT hashFunc);
void InsertBloomFilter(BloomFilter* bf, const char* str);
int IsInBloomFilter(BloomFilter* bf, const char* str);
int SizeBloomFilter(BloomFilter* bf);
void DestroyBloomFilter(BloomFilter* bf);


#endif //__BLOOMFILTER_H__