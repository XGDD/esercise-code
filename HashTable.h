#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include<stdio.h>
#include<assert.h>

#define MAX_SIZE 10

typedef int HTDataType;
typedef enum{EMPTY,EXIST,DELETE}State;
typedef struct HTElem
{
	HTDataType _data;
	State _state;
}HTElem;

typedef struct HashTable
{
	HTElem _ht[MAX_SIZE];
	int _size;//哈希表中有效元素的个数
}HT;

void InitHashTable(HT* pHT);
int InsertHashTable(HT* pHT, HTDataType data);
int DeleteHashTable(HT* pHT, HTDataType data);
int FindHashTable(HT* pHT, HTDataType data);
int EmptyHashTable(HT* pHT);
int SizeHashTable(HT* pHT);
int HashFun(HTDataType data);

#endif //__HASHTABLE_H__