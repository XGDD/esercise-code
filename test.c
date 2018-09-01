#define _CRT_SECURE_NO_WARNINGS 1

#include"linklist.h"

void Back_test()
{
	pList plist;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	//DestroyLinkList(&plist);
	PrintLinkList(plist);
	PopBack(&plist);
	PopBack(&plist);
	PrintLinkList(plist);
}

void Front_test()
{
	pList plist;
	InitLinkList(&plist);
    PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	PopFront(&plist);
	PrintLinkList(plist);
}

void Find_test()
{
	pList plist;
	pNode tmp = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	tmp = Find(plist, 2);
	printf("%d\n", tmp->data);
}

void Insert_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 3);
    Insert(&plist, pos, 5);
	PrintLinkList(plist);
}

void Erase_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	Erase(&plist, pos);
	PrintLinkList(plist);
}

void Remove_test()
{
	pList plist;
	//int ret = 0;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 1);
	PushFront(&plist, 3);
	PushFront(&plist, 1);
	PrintLinkList(plist);
	//Remove(&plist, 1);
    //RemoveAll(&plist, 3);
	//ret = GetListLength(plist);
	//printf("%d\n", ret);
	PrintTailToHead(plist);
	//PrintLinkList(plist);
}

EraseNotTailNode_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	EraseNotTailNode(&plist, pos);
	PrintLinkList(plist);

}

void InsertPosFront_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	InsertPosFront(pos, 5);
	PrintLinkList(plist);
}

void JosephCircle_test()
{
	pList plist;
	pNode Tail = NULL;
	pNode Head = NULL;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PrintLinkList(plist);
	Tail = FindTail(plist);
	//构环
	Tail->next = plist;
	//解环
	plist = JosephCircle(plist, 3);
	plist->next = NULL;
	PrintLinkList(plist);
}

void BubbleSort_test()
{
	pList plist;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintLinkList(plist);
	BubbleSort(plist);
	PrintLinkList(plist);
}

void FindMiddleNode_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PrintLinkList(plist);
	pos = FindMiddleNode(plist);
	printf("%d\n", pos->data);
}

void FindLastKNode_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PrintLinkList(plist);
	pos = FindLastKNode(plist, 3);
	printf("%d\n", pos->data);
}

void ReverseList_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PrintLinkList(plist);
	ReverseList(&plist);
	PrintLinkList(plist);
	pos = ReverseListOP(plist);
	PrintLinkList(pos);
}

void MergeList_test()
{
	pList plist1;
	pList plist2;
	pNode NewNode;
	InitLinkList(&plist1);
	InitLinkList(&plist2);
	PushBack(&plist1, 1);
	PushBack(&plist1, 3);
	PushBack(&plist1, 5);
	PushBack(&plist1, 7);
	PrintLinkList(plist1);
	PushBack(&plist2, 2);
	PushBack(&plist2, 4);
	PushBack(&plist2, 6);
	PushBack(&plist2, 7);
	PushBack(&plist2, 8);
	PrintLinkList(plist2);
	NewNode = MergeList(plist1, plist2);
	PrintLinkList(NewNode);
}

void EraseTailK_test()
{
	pList plist;
	pNode pos = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PrintLinkList(plist);
	pos = FindLastKNode(plist, 3);
	EraseTailK(&plist, 3, pos);
	PrintLinkList(plist);
}

void HastListCircle_test()
{
	pList plist;
	pNode Tail = NULL;
	pNode pos = NULL;
	pNode ret = NULL;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	//PrintLinkList(plist);
	//构环
	Tail = FindTail(plist);
	pos = FindLastKNode(plist, 4);
	Tail->next = pos;
	//PrintLinkList(plist);
	ret = HastListCircle(plist);
	if (NULL == ret)
		printf("该链表无环\n");
	printf("该链表带环\n");
}

void CircleLength_test()
{
	pList plist;
	pNode Tail = NULL;
	pNode pos = NULL;
	int ret = 0;
	pNode pM = NULL;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	//PrintLinkList(plist);
	//构环
	Tail = FindTail(plist);
	pos = FindLastKNode(plist, 4);
	Tail->next = pos;
	pM = HastListCircle(plist);
	ret = CircleLength(pM);
	printf("该环长度为：%d\n", ret);
}

void EnterNode_test()
{
	pList plist;
	pNode Tail = NULL;
	pNode pos = NULL;
	pNode pM = NULL;
	pNode ret = NULL;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	//PrintLinkList(plist);
	//构环
	Tail = FindTail(plist);
	pos = FindLastKNode(plist, 4);
	Tail->next = pos;
	pM = HastListCircle(plist);
	ret = EnterNode(plist, pM);
	printf("%d\n", ret->data);
}

void IsCrossList_test()
{
	pList plist1;
	pList plist2;
	pNode ret = NULL;
	pNode Tail = NULL;
	InitLinkList(&plist1);
	InitLinkList(&plist2);
	PushBack(&plist1, 1);
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 9);
	PushBack(&plist1, 10);
	PrintLinkList(plist1);
	PushBack(&plist2, 6);
	PushBack(&plist2, 7);
	PushBack(&plist2, 8);
	Tail = FindTail(plist2);
	Tail->next = FindLastKNode(plist1, 3);
	PrintLinkList(plist2);
	ret = IsCrossList(plist1, plist2);
	if (NULL == ret)
	{
		printf("这两个链表不相交\n");
	}
	else
	{
		printf("这两个链表相交\n");
	}
}

void CrossNode_test()
{
	pList plist1;
	pList plist2;
	pNode ret = NULL;
	pNode Tail = NULL;
	InitLinkList(&plist1);
	InitLinkList(&plist2);
	/*PushBack(&plist1, 1);
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 9);
	PushBack(&plist1, 10);
	PrintLinkList(plist1);
	PushBack(&plist2, 6);
	PushBack(&plist2, 7);
	PushBack(&plist2, 8);
	Tail = FindTail(plist2);
	Tail->next = FindLastKNode(plist1, 3);*/
	PushBack(&plist1, 1);
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 4);
	PrintLinkList(plist1);
	PushBack(&plist2, 5);
	PushBack(&plist2, 6);
	PushBack(&plist2, 7);
	PushBack(&plist2, 8);
	Tail = FindTail(plist2);
	Tail->next = FindTail(plist1);
	PrintLinkList(plist2);
	ret = CrossNode(plist1, plist2);
	printf("交点为:%d\n", ret->data);
}

void IsCrossNodeCircle_test()
{
	pList plist1;
	pList plist2;
	pNode Tail1 = NULL;
	pNode Tail2 = NULL;
	pNode pos = NULL;
	pNode ret = NULL;
	InitLinkList(&plist1);
	InitLinkList(&plist2);
	PushBack(&plist1, 1);
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 4);
	PushBack(&plist1, 5);
	PushBack(&plist1, 6);
	//PrintLinkList(plist);
	//构环
	Tail1 = FindTail(plist1);
	pos = FindLastKNode(plist1, 4);
	Tail1->next = pos;

	PushBack(&plist2, 7);
	PushBack(&plist2, 8);
	Tail2 = FindTail(plist2);
	Tail2->next = Find(plist1, 2);

	ret = IsCrossNodeCircle(plist1, plist2);

	if (ret == NULL)
	{
		printf("不相交\n");
	}
	printf("相交\n");
}

void CrossNodeCircle_test()
{
	pList plist1;
	pList plist2;
	pNode Tail1 = NULL;
	pNode Tail2 = NULL;
	pNode pos = NULL;
	pNode ret = NULL;
	InitLinkList(&plist1);
	InitLinkList(&plist2);
	PushBack(&plist1, 1);
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 4);
	PushBack(&plist1, 5);
	PushBack(&plist1, 6);
	//PrintLinkList(plist);
	//构环
	Tail1 = FindTail(plist1);
	pos = FindLastKNode(plist1, 4);
	Tail1->next = pos;

	PushBack(&plist2, 7);
	PushBack(&plist2, 8);
	Tail2 = FindTail(plist2);
	Tail2->next = Find(plist1, 2);

	ret = CrossNodeCircle(plist1, plist2);
	printf("交点为:%d\n", ret->data);
}

int main()
{
	//Back_test();
	//Front_test();
	//Find_test();
	//Insert_test();
	//Erase_test();
	//Remove_test();
	//EraseNotTailNode_test();
	//InsertPosFront_test();
	//JosephCircle_test();
	//BubbleSort_test();
	//FindMiddleNode_test();
	//FindLastKNode_test();
	//ReverseList_test();
	//MergeList_test();
	//EraseTailK_test();
	//HastListCircle_test();
	//CircleLength_test();
	//EnterNode_test();
	//IsCrossList_test();
	//CrossNode_test();
	//IsCrossNodeCircle_test();
	CrossNodeCircle_test();

	return 0;
}