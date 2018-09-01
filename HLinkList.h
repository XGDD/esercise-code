#ifndef __HLinkList_H__
#define __HLinkList_H__

#include<stdio.h>
#include<assert.h>

typedef int DataType;

typedef struct HLinkListNode
{
	struct HLinkListNode* next;
	DataType data;
}Node;

void HLinkListInit(Node **pHead);
void HLinkListPushBack(Node *pHead, DataType data);
void HLinkListPopBack(Node *pHead);
void HLinkListPushFront(Node *pHead, DataType data);
void HLinkListPopFront(Node *pHead);
void HLinkListDestory(Node **pHead);
Node* BuyHLinkList(DataType data);
void PrintHLinkList(Node *pHead);



#endif //__HLinkList_H__