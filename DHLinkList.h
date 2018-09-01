#ifndef __DHLINKLIST_H__
#define __DHLINKLIST_H__

#include<stdio.h>
#include<assert.h>

typedef int DataType;

typedef struct DHLinkListNode
{
	struct DHLinkListNode* pre;
	struct DHLinkListNode* next;
	DataType data;
}Node;

void DHLinkListInit(Node **pHead);
void DHLinkListPushBack(Node *pHead, DataType data);
void DHLinkListPopBack(Node *pHead);
void DHLinkListPushFront(Node *pHead, DataType data);
void DHLinkListPopFront(Node *pHead);
Node* BuyDHLinkListNode(DataType data);
void PrintLinkList(Node* pHead);



#endif //__DHLINKLIST_H__