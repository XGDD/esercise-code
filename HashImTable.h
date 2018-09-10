#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include"Common.h"

//typedef int HTDataType;
typedef char* HTDataType;
typedef int(*PDTInt)(HTDataType data);
typedef enum{ EMPTY, EXIST, DELETE }State;
typedef struct HTElem
{
	HTDataType _data;
	State _state;
}HTElem;

typedef struct HashTable
{
	HTElem* _ht;
	int _size;//哈希表中有效元素的个数
	int _capacity;
	int _total;//表示存在和删除的个数之和，因为在计算负载因子的时候，我们用size算的话，删除后的位置是不能存储的，如果不算删除的个数，负载因子就会计算错误
	PDTInt _PDTInt;//函数指针
}HT;

void InitHashTable(HT* pHT, int capacity, PDTInt pDTInt);
int InsertHashTable(HT* pHT, HTDataType data);
int DeleteHashTable(HT* pHT, HTDataType data);
int FindHashTable(HT* pHT, HTDataType data);
int EmptyHashTable(HT* pHT);
int SizeHashTable(HT* pHT);
int HashFun(HT* pHT, HTDataType data);
void CheckCapacity(HT* pHT, HTDataType data);
void DestroyHashTable(HT* pHT);

#endif //__HASHTABLE_H__