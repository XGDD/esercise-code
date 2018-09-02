#ifndef __COMPLEXLINKLIST_H__
#define __COMPLEXLINKLIST_H__

#include<stdio.h>

typedef int DataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* random;
	DataType data;
}Node, *pNode, *pList;

pNode BuyNode(DataType d);
pNode CopyComplexLinkList(pList plist);






#endif //__COMPLEXLINKLIST_H__