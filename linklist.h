#ifndef __LINKLIST_H__ 
#define __LINKLIST_H__ 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;

void InitLinkList(pList* pplist);
pNode BuyNode(DataType d);
void DestroyLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
pNode Find(pList plist, DataType d);
pNode FindTail(pList plist);
pNode FindHead(pList plist);

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d);
//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos);
void Remove(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void EraseNotTailNode(pNode pos);
void PrintLinkList(pList plist);
int GetListLength(pList plist);

//���������� 

//1. �����ӡ�������� 
void PrintTailToHead(pList plist);
//2.ɾһ����ͷ������ķ�β�ڵ㣨���ܱ�������
void EraseNotTailNode(pList* pplist, pNode pos);
//3.����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
void InsertPosFront(pNode pos,DataType d);
//4.������ʵ��Լɪ��
pNode JosephCircle(pList plist, int m);
//5.����������ð������
void BubbleSort(pList plist);
//6.���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
pNode FindMiddleNode(pList plist);
//7.���ҵ�����ĵ�����K���ڵ㣬Ҫ��ֻ�ܱ���һ������
pNode FindLastKNode(pList plist, int k);
//8.����/��ת������
void ReverseList(pList* pplist);
pNode ReverseListOP(pList plist);
//9.�ϲ��������������ϲ�����Ȼ����
pNode MergeList(pNode pHead1, pNode pHead2);
//10.ɾ������ĵ�����K�����
void EraseTailK(pList *pplist, int k, pNode pos);
//11.�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿
pNode HastListCircle(pList plist);//�Ƿ����
int CircleLength(pList pMeetNode);//���ĳ���
pNode EnterNode(pList pHead, pList pMeetNode);//������ڵ�
//12.�ж����������Ƿ��ཻ�����ཻ���󽻵�(������������)
pNode IsCrossList(pList plist1, pList plist2);//�ж��Ƿ��ཻ
pNode CrossNode(pList plist1, pList plist2);//�󽻵�
//13.�ж����������Ƿ��ཻ�����ཻ���󽻵�(����������ܴ���)
pNode IsCrossNodeCircle(pList plist1, pList plist2);//�ж��Ƿ��ཻ
pNode CrossNodeCircle(pList plist1, pList plist2);//�󽻵�


#endif //__LINKLIST_H__ 