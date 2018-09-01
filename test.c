#include"DHLinkList.h"

void DHLinkListPushBack_test()
{
	Node *pHead;
	DHLinkListInit(&pHead);
	DHLinkListPushBack(pHead, 1);
	DHLinkListPushBack(pHead, 2);
	DHLinkListPushBack(pHead, 3);
	DHLinkListPushBack(pHead, 4);
	PrintLinkList(pHead);
}

void DHLinkListPopBack_test()
{
	Node *pHead;
	DHLinkListInit(&pHead);
	DHLinkListPushBack(pHead, 1);
	DHLinkListPushBack(pHead, 2);
	DHLinkListPushBack(pHead, 3);
	DHLinkListPushBack(pHead, 4);
	PrintLinkList(pHead);
	DHLinkListPopBack(pHead);
	DHLinkListPopBack(pHead);
	PrintLinkList(pHead);
}

void DHLinkListPushFront_test()
{
	Node *pHead;
	DHLinkListInit(&pHead);
	DHLinkListPushFront(pHead, 1);
	DHLinkListPushFront(pHead, 2);
	DHLinkListPushFront(pHead, 3);
	DHLinkListPushFront(pHead, 4);
	PrintLinkList(pHead);
}

void DHLinkListPopFront_test()
{
	Node *pHead;
	DHLinkListInit(&pHead);
	DHLinkListPushFront(pHead, 1);
	DHLinkListPushFront(pHead, 2);
	DHLinkListPushFront(pHead, 3);
	DHLinkListPushFront(pHead, 4);
	PrintLinkList(pHead);
	DHLinkListPopFront(pHead);
	PrintLinkList(pHead);
}

int main()
{
	//DHLinkListPushBack_test();
	//DHLinkListPopBack_test();
	//DHLinkListPushFront_test();
	DHLinkListPopFront_test();

	return 0;
}