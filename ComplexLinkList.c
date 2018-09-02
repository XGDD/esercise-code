#include"ComplexLinkList.h"

pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	if (newNode)
	{
		newNode->data = d;
		newNode->next = NULL;
		newNode->random = NULL;
		return newNode;
	}
	else
	{
		printf("创建节点失败\n");
		return NULL;
	}
}

pNode CopyComplexLinkList(pList plist)
{
	//1.在原链表每个结点后插入值相等的新结点 
	pNode pre = plist;
	pNode NewNode = NULL;
	pNode cur = NULL;
	while (pre)
	{
		NewNode = BuyNode(pre->data);
		NewNode->next = pre->next;
		pre->next = NewNode;
		pre = NewNode->next;
	}
	//2.给新结点随机指针域赋值
	pre = plist;
	while (pre)
	{
		cur = pre->next;
		if (NULL == pre->random)
			cur->random = NULL;
		else
			cur->random = pre->random->next;
		
		pre = cur->next;
	}
	//3.将新结点从原链表中拆下来
	pre = plist;
	pNode pre2 = pre->next;//新链表的头
	pNode next = pre->next;
	while (next)
	{
		pre->next = next->next;
		pre = next;
		next = pre->next;
	}
	return pre2;
}