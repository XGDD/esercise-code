#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include<assert.h>
#include<stdio.h>
#include<malloc.h>
#include"Common.h"

typedef int HBDataType;
typedef struct HashBucketNode
{
	struct HashBucketNode* _pNext;
	HBDataType _data;
}Node,*pNode;

typedef int(*PDTInt)(HBDataType data);

typedef struct HashBucket
{
	pNode* _table;
	int _capacity;
	int _size;
	PDTInt _pDTInt;
}HashBucket;

void InitHashTable(HashBucket* pHB, int capacity, PDTInt pDTInt);
int InsertHashTable(HashBucket* pHB, HBDataType data);
int DeleteHashTable(HashBucket* pHB, HBDataType data);
int FindHashTable(HashBucket* pHB, HBDataType data);
int SizeHashTable(HashBucket* pHB);
int EmptyHashTable(HashBucket* pHB);
void DestroyHashTable(HashBucket* pHB);
void Print(HashBucket* pHB);
int HashFun(HashBucket* pHB, HBDataType data);
pNode BuyNode(HBDataType data);
void CheckCapacity(HashBucket* pHB);


#endif //__HASHTABLE_H__