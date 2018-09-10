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
	int _size;//��ϣ������ЧԪ�صĸ���
	int _capacity;
	int _total;//��ʾ���ں�ɾ���ĸ���֮�ͣ���Ϊ�ڼ��㸺�����ӵ�ʱ��������size��Ļ���ɾ�����λ���ǲ��ܴ洢�ģ��������ɾ���ĸ������������Ӿͻ�������
	PDTInt _PDTInt;//����ָ��
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