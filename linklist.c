#define _CRT_SECURE_NO_WARNINGS 1

#include"linklist.h"

void InitLinkList(pList* pplist)//初始化时，只需要赋为空值就行，不需要重新创建新的节点再赋为空
{
	assert(pplist != NULL);
	(*pplist) = NULL;
}

pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	if (newNode)
	{
		newNode->data = d;
		newNode->next = NULL;
		return newNode;
	}
	else
	{
		printf("创建节点失败\n");
		return NULL;
	}
}

void PrintLinkList(pList plist)
{
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("OVER\n");
}

void DestroyLinkList(pList* pplist)
{
	assert(pplist);
	pNode cur = *pplist;
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}

void PushBack(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		*pplist = BuyNode(d);
		return;
	}
	else
	{
		pNode cur = (*pplist);
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = BuyNode(d);
	}
}

void PopBack(pList* pplist)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	if ((*pplist) == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		(*pplist) = NULL;
		return;
	}
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void PushFront(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	if ((*pplist) == NULL)
	{
		(*pplist) = BuyNode(d);
	}
	else
	{
		pNode cur = BuyNode(d);
		cur->next = *pplist;
		*pplist = cur;
	}
}

void PopFront(pList* pplist)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	if ((*pplist) == NULL)
	{
		return;
	}
	else
	{
		*pplist = cur->next;
		free(cur);
		cur = NULL;
	}
}

pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Insert(pList* pplist, pNode pos, DataType d)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);//链表不为空
	assert(pos != NULL);
	pNode cur = *pplist;
	pNode newNode = BuyNode(d);
	if ((*pplist) == pos)//在第一个节点前插入
	{
		PushFront(pplist, d);
	}
	else
	{
		while (cur && (cur->next != pos))
		{
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
}

void Erase(pList* pplist, pNode pos)
{
	assert(pplist != NULL);
	assert((*pplist) != NULL);
	assert(pos != NULL);
	pNode pre = *pplist;
	pNode cur = pre->next;
	if ((*pplist) == pos)//删除第一个节点
	{
		PopFront(pplist);
	}
	while (pre && (cur != pos))
	{
		pre = pre->next;
		cur = pre->next;
	}
	if (cur != NULL)
	{
		pre->next = cur->next;
		free(cur);
		cur = NULL;
	}
}

void Remove(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	pNode prev = NULL;
	if ((*pplist)->data == d)//若要删除的节点是第一个
	{
		pNode del = cur;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else
	{
		while (cur && (cur->data != d))
		{
			prev = cur;
			cur = cur->next;
		}
		if (cur != NULL)
		{
			prev->next = cur->next;
			free(cur);
			cur = NULL;
		}
		return;
	}
}

void RemoveAll(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	pNode prev = NULL;
	while (cur)
	{
		if ((*pplist)->data == d)//若要删除的节点是第一个
		{
			PopFront(pplist, d);
			cur = (*pplist);
			continue;
		}
		else if (cur->data = d)
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		prev = cur;
		cur = cur->next;
	}
}

int GetListLength(pList plist)
{
	int count = 0;
	pNode cur = plist;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

////递归方法
//void PrintTailToHead(pList plist)
//{
//	if (plist == NULL)
//	{
//		return;
//	}
//	else
//		PrintTailToHead(plist->next);
//		printf("%d->", plist->data);
//}

void PrintTailToHead(pList plist)
{
	pList tail = NULL;
	pList cur = plist;
	while (plist != tail)//这里的tail不是NULL，只是一个向前走的指针
	{
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d->", cur->data);
		tail = cur;
		cur = plist;
	}
	printf("OVER\n");
}

void EraseNotTailNode(pList* pplist, pNode pos)
{
	assert(pplist != NULL);
	assert(pos && (pos->next != NULL));
	pNode del = NULL;
	del = pos->next;
	pos->data = del->data;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void InsertPosFront(pNode pos, DataType d)
{
	pNode NewNode = NULL;
	if (pos == NULL)
		return;
	NewNode = BuyNode(pos->data);
	NewNode->next = pos->next;
	pos->next = NewNode;
	pos->data = d;
}

pNode JosephCircle(pList plist, int m)
{
	pNode cur = plist;
	pNode del = NULL;
	while (cur->next != cur)
	{
		int M = m;
		while (--M)
		{
			cur = cur->next;
		}
		del = cur->next;
		cur->next = del->next;
		cur->data = del->data;
		free(del);
		del = NULL;
	}
	return cur;
}

pNode FindTail(pList plist)
{
	pNode cur = plist;
	while (cur->next)
	{
		cur = cur->next;
	}
	return cur;
}

void BubbleSort(pList plist)
{
	pNode Tail = NULL;
	if (NULL == plist || NULL == plist->next)
		return;
	while (plist != Tail)
	{
		pNode pre = plist;
		pNode cur = plist->next;
		while (cur != Tail)
		{
			if (pre->data < cur->data)
			{
				DataType tmp = pre->data;
				pre->data = cur->data;
				cur->data = tmp;
			}
			pre = cur;
			cur = cur->next;
		}
		Tail = pre;
	}
}

pNode FindMiddleNode(pList plist)
{
	pNode Fast = plist;
	pNode Slow = plist;
	while (Fast && Fast->next)
	{
		Fast = Fast->next->next;
		Slow = Slow->next;
	}
	return Slow;
}

pNode FindLastKNode(pList plist, int k)
{
	pNode Fast = NULL;
	pNode Slow = NULL;
	if (NULL == plist || k <= 0)
		return;
	Fast = plist;
	Slow = plist;
	while (k--)//先让Fast向后走k步
	{
		Fast = Fast->next;
	}
	while (Fast)
	{
		Fast = Fast->next;
		Slow = Slow->next;
	}
	return Slow;
}

void ReverseList(pList* pplist)
{
	pNode pPre = NULL;
	pNode pCur = *pplist;
	pNode pNext = NULL;
	assert(pplist);
	if (NULL == *pplist)
		return;
	while (pCur)
	{
		pNext = pCur->next;//这个语句放在最前边是防止程序崩溃，若放在最后一句，NULL的next程序就会崩溃
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	*pplist = pPre;//要改变头节点的指向，所以上边会传二级指针
}

pNode ReverseListOP(pList plist)
{
	pNode NewHead = NULL;
	pNode pCur = plist;
	pNode pNext = NULL;
	while (pCur)
	{
		pNext = pCur->next;
		pCur->next = NewHead;
		NewHead = pCur;
		pCur = pNext;
	}
	return NewHead;
}

pNode MergeList(pNode pHead1, pNode pHead2)
{
	pNode pL1 = pHead1;
	pNode pL2 = pHead2;
	pNode NewNode = NULL;
	pNode Tail = NULL;
	if (NULL == pHead1)
		return pHead2;
	if (NULL == pHead2)
		return pHead1; 
	if (pL1->data <= pL2->data)
	{
		NewNode = Tail = pL1;
		pL1 = pL1->next;
	}
	else
	{
		NewNode = Tail = pL2;
		pL2 = pL2->next;
	}
	while (pL1 && pL2)
	{
		if (pL1->data <= pL2->data)
		{
			Tail->next = pL1;
			pL1 = pL1->next;
		}
		else
		{
			Tail->next = pL2;
			pL2 = pL2->next;
		}
		Tail = Tail->next;
	}
	if (pL1)
		Tail->next = pL1;
	if (pL2)
		Tail->next = pL2;
	return NewNode;
}

void EraseTailK(pList *pplist, int k, pNode pos)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	if (count < k)
		printf("该结点不存在\n");
	else
	{
		pos->data = pos->next->data;
		pos->next = pos->next->next;
	}
}

pNode HastListCircle(pList plist)
{
	assert(plist != NULL);
	pNode Fast = plist;
	pNode Slow = plist;
	while (Fast && Fast->next)
	{
		Fast = Fast->next->next;
		Slow = Slow->next;
		if (Fast == Slow)
		{
			return Slow; //(带环)
		}
	}
	return NULL;
}

int CircleLength(pList pMeetNode)
{
	int count = 1;
	pNode cur = pMeetNode->next;
	while (cur->data != pMeetNode->data)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

pNode EnterNode(pList pHead, pList pMeetNode)
{
	if (NULL == pHead || NULL == pMeetNode)
		return NULL;
	while (pHead != pMeetNode)
	{
		pHead = pHead->next;
		pMeetNode = pMeetNode->next;
	}
	return pMeetNode;
}

pNode IsCrossList(pList plist1, pList plist2)
{
	assert(plist1 != NULL);
	assert(plist2 != NULL);
	pNode pl1 = plist1;
	pNode pl2 = plist2;
	while (pl1->next)
	{
		pl1 = pl1->next;
	}
	while (pl2->next)
	{
		pl2 = pl2->next;
	}
	if (pl1 == pl2)
	{
		return pl1;
	}
	return NULL;
}

pNode CrossNode(pList plist1, pList plist2)
{
	assert(plist1 != NULL);
	assert(plist2 != NULL);
	int gap = 0;
	int sz1 = GetListLength(plist1);
	int sz2 = GetListLength(plist2);
	gap = sz1 - sz2;
	if (gap > 0)
	{
		while (gap--)
		{
			plist1 = plist1->next;
		}
	}
	else if (gap < 0)
	{
		while (gap++)
		{
			plist2 = plist2->next;
		}
	}
	while (plist1 && plist2)
	{
		plist1 = plist1->next;
		plist2 = plist2->next;
		if (plist1 == plist2)
		{
			return plist1;
		}
	}
	return NULL;
}

pNode IsCrossNodeCircle(pList plist1, pList plist2)
{
	assert(plist1 != NULL);
	assert(plist2 != NULL);
	pNode pM1 = HastListCircle(plist1);
	pNode pM2 = HastListCircle(plist2);
	pNode cur = NULL;
	if ((pM1 && pM2) == NULL)
		return NULL;
	else
	{
		cur = pM1;
		while (cur->next != pM1)
		{
			cur = cur->next;
			if (cur == pM2)
			{
				return pM2;
			}
		}
		return NULL;
	}
}

pNode CrossNodeCircle(pList plist1, pList plist2)//两个都带环，交点在外边
{
	assert(plist1 != NULL);
	assert(plist2 != NULL);
	int sz1 = 0;
	int sz2 = 0;
	pNode cur1 = NULL;
	pNode cur2 = NULL;
	pNode pE = NULL;//环的入口点
	pNode pM1 = HastListCircle(plist1);
	pE = EnterNode(plist1, pM1);
	cur1 = plist1;
	cur2 = plist2;
	while (cur1 != pE)
	{
		sz1++;
		cur1 = cur1->next;
	}
	while (cur2 != pE)
	{
		sz2++;
		cur2 = cur2->next;
	}
	int gap = 0;
	gap = sz1 - sz2;
	if (gap > 0)
	{
		while (gap--)
		{
			plist1 = plist1->next;
		}
	}
	else if (gap < 0)
	{
		while (gap++)
		{
			plist2 = plist2->next;
		}
	}
	while (plist1 && plist2)
	{
		plist1 = plist1->next;
		plist2 = plist2->next;
		if (plist1 == plist2)
		{
			return plist1;
		}
	}
	return NULL;
}