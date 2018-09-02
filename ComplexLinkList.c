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
		printf("�����ڵ�ʧ��\n");
		return NULL;
	}
}

pNode CopyComplexLinkList(pList plist)
{
	//1.��ԭ����ÿ���������ֵ��ȵ��½�� 
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
	//2.���½�����ָ����ֵ
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
	//3.���½���ԭ�����в�����
	pre = plist;
	pNode pre2 = pre->next;//�������ͷ
	pNode next = pre->next;
	while (next)
	{
		pre->next = next->next;
		pre = next;
		next = pre->next;
	}
	return pre2;
}