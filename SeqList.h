#ifndef SeqList_h
#define SeqList_h
#include<stdio.h>
#include<stdlib.h>
#include<assert.h> 

#define MAX 10

typedef int DataType;

typedef struct SeqList
{
	int sz;
	DataType data[MAX];
}SeqList,*PSeqList;

//��ʼ�� 
void InitSeqList(PSeqList pSeq);
//β������ 
void PushBack(PSeqList pSeq, DataType data);
//β��ɾ�� 
void PopBack(PSeqList pSeq);
//ͷ������ 
void PushFront(PSeqList pSeq, DataType data);
//ͷ��ɾ�� 
void PopFront(PSeqList pSeq);
//����ָ��Ԫ�� 
int Find(PSeqList pSeq, DataType data);
//ָ��λ�ò��� 
void Insert(PSeqList pSeq, int pos, DataType data);
//ɾ��ָ��λ��Ԫ�� 
void Erase(PSeqList pSeq, int pos);
//ɾ��ָ��Ԫ�� 
void Remove(PSeqList pSeq, DataType data);
//ɾ�����е�ָ��Ԫ�� 
void RemoveAll(PSeqList pSeq, DataType data);
//����˳���Ĵ�С 
int Size(PSeqList pSeq);
//�ж�˳����Ƿ�Ϊ�� 
int Empty(PSeqList pSeq);
//ð������ 
void BubbleSort(PSeqList pSeq);
//ѡ������ 
void SelectSort(PSeqList pSeq);
//ѡ��������Ż� 
void SelectSortOP(PSeqList pSeq);
//���ֲ��� 
int BinarySearch(PSeqList pSeq, DataType data);
//���ֲ��ҵݹ�д�� 
int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d);

//��ӡ 
void PrintSeqList(PSeqList pSeq);



#endif
