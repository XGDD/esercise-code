#include"HLinkList.h"

void PrintHLinkList(Node *pHead)
{
	if (pHead == NULL)
		return;
	while (pHead)
	{
		printf("%d--->", pHead->data);
		pHead = pHead->next;
	}
	printf("OVER\n");
}

Node* BuyHLinkList(DataType data)
{
	Node *NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode)
	{
		NewNode->data = data;
		NewNode->next = NULL;
	}
	else
	{
		printf("创建结点失败！\n");
		return NULL;
	}
}

void HLinkListInit(Node **pHead)
{
	assert(pHead != NULL);
	(*pHead) = (Node*)malloc(sizeof(Node));
	(*pHead)->data = 0;
	(*pHead)->next = NULL;
}

void HLinkListPushBack(Node *pHead, DataType data)
{
	Node *NewNode = NULL;
	while (pHead->next)
	{
		pHead = pHead->next;
	}
	NewNode = BuyHLinkList(data);
	pHead->next = NewNode;

}

void HLinkListPopBack(Node *pHead)
{
	Node *pre = pHead;
	Node *cur = pHead->next;
	if (NULL == pHead)
		return;
	while (cur->next)
	{
		pre = cur;
		cur = pre->next;
	}
	pre->next = NULL;
}

void HLinkListPushFront(Node *pHead, DataType data)
{
	Node *pre = pHead;
	Node *cur1 = pHead->next;
	Node *cur2 = pHead->next;
	Node *NewNode = BuyHLinkList(data);
	if (NULL == pHead)
		return;
	if (NULL == pHead->next)
	{
		pHead->next = NewNode;
	}
	else
	{
		while (cur2->next)
		{
			pre = cur2;
			cur2 = pre->next;
		}
		NewNode->next = cur1;
		pHead->next = NewNode;
	}
}

void HLinkListPopFront(Node *pHead)
{
	Node *pre = pHead;
	Node *cur = pHead->next;
	if (NULL == pHead)
		return;
	pre->next = cur->next;
}

void HLinkListDestory(Node **pHead)
{
	Node *cur = *pHead;
	assert(pHead != NULL);
	if (NULL == (*pHead))
		return;
	while (cur)
	{
		Node *del = cur;
		cur = del->next;
		free(del);
		del = NULL;
	}
	cur = NULL;
}