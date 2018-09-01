#include"HLinkList.h"

void HLinkListPushBack_test()
{
	Node *pHead;
	HLinkListInit(&pHead);
	HLinkListPushBack(pHead, 1);
	HLinkListPushBack(pHead, 2);
	HLinkListPushBack(pHead, 3);
	HLinkListPushBack(pHead, 4);
	PrintHLinkList(pHead);
}

void HLinkListPopBack_test()
{
	Node *pHead;
	HLinkListInit(&pHead);
	HLinkListPushBack(pHead, 1);
	HLinkListPushBack(pHead, 2);
	HLinkListPushBack(pHead, 3);
	HLinkListPushBack(pHead, 4);
	PrintHLinkList(pHead);
	HLinkListPopBack(pHead);
	HLinkListPopBack(pHead);
	PrintHLinkList(pHead);
}

void HLinkListPushFront_test()
{
	Node *pHead;
	HLinkListInit(&pHead);
	HLinkListPushFront(pHead, 1);
	HLinkListPushFront(pHead, 2);
	HLinkListPushFront(pHead, 3);
	HLinkListPushFront(pHead, 4);
	PrintHLinkList(pHead);
}

void HLinkListPopFront_test()
{
	Node *pHead;
	HLinkListInit(&pHead);
	HLinkListPushFront(pHead, 1);
	HLinkListPushFront(pHead, 2);
	HLinkListPushFront(pHead, 3);
	HLinkListPushFront(pHead, 4);
	PrintHLinkList(pHead);
	HLinkListPopFront(pHead);
	HLinkListPopFront(pHead);
	PrintHLinkList(pHead);
}

void HLinkListDestory_test()
{
	Node *pHead;
	HLinkListInit(&pHead);
	HLinkListPushFront(pHead, 1);
	HLinkListPushFront(pHead, 2);
	HLinkListPushFront(pHead, 3);
	HLinkListPushFront(pHead, 4);
	PrintHLinkList(pHead);
	HLinkListDestory(&pHead);
	PrintHLinkList(pHead);
}

int main()
{
	//HLinkListPushBack_test();
	//HLinkListPopBack_test();
	//HLinkListPushFront_test();
	//HLinkListPopFront_test();
	HLinkListDestory_test();

	return 0;
}