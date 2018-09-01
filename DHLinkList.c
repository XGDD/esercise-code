#include"DHLinkList.h"

void DHLinkListInit(Node **pHead)
{
	assert(pHead != NULL);
	(*pHead) = (Node *)malloc(sizeof(Node));
	(*pHead)->data = 0;
	(*pHead)->next = NULL;
	(*pHead)->pre = NULL;
}

void PrintLinkList(Node* pHead)
{
	while (pHead)
	{
		printf("%d->", pHead->data);
		pHead = pHead->next;
	}
	printf("OVER\n");
}

Node* BuyDHLinkListNode(DataType data)
{
	Node *NewNode = NULL;
	NewNode = (Node *)malloc(sizeof(Node));
	if (NULL == NewNode)
		printf("创建结点失败！\n");
	else
	{
		NewNode->data = data;
		NewNode->next = NULL;
		NewNode->pre = NULL;
	}
	return NewNode;
}

void DHLinkListPushBack(Node *pHead, DataType data)
{
	Node *NewNode = BuyDHLinkListNode(data);
	Node *cur = pHead;
	if (NULL == pHead)
		return;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = NewNode;
	NewNode->pre = cur;
	NewNode->next = NULL;
}

void  DHLinkListPopBack(Node *pHead)
{
	Node *pre = pHead;
	Node *cur = pHead->next;
	if (NULL == pHead)
		return;
	while (cur && (cur->next))
	{
		pre = cur;
		cur = pre->next;
	}
	pre->next = NULL;
}

void DHLinkListPushFront(Node *pHead, DataType data)
{
	Node *pre = pHead;
	Node *cur = pHead->next;
	Node *NewNode = BuyDHLinkListNode(data);
	if (NULL == pHead)
		return;
	if (NULL == cur)
	{
		NewNode->next = cur;
		NewNode->pre = pre;
		pre->next = NewNode;
	}
	else
	{
		NewNode->next = cur;
		NewNode->pre = pre;
		cur->pre = NewNode;
		pre->next = NewNode;
	}
}

void DHLinkListPopFront(Node *pHead)
{
	assert(pHead != NULL);
	if (pHead->next)
	{
		Node *cur = pHead->next;
		pHead->next = cur->next;
		cur->next->pre = pHead;
		free(cur);
	}
}