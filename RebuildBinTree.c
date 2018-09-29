#define _CRT_SECURE_NO_WARNINGS 1

#include"RebuildBinTree.h"

BTNode* BuyBTNode(BDataType data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == NewNode)
	{
		printf("�������ʧ�ܣ�\n");
		return NULL;
	}
	else
	{
		NewNode->_data = data;
		NewNode->_pLeft = NULL;
		NewNode->_pRight = NULL;
	}
	return NewNode;
}

void inOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;

	//����������������
	inOrder(pRoot->_pLeft);

	//���������
	printf("%d ", pRoot->_data);

	//����������������
	inOrder(pRoot->_pRight);
}


BTNode* RebuildBinTree(BDataType* PreOrder, BDataType* InOrder, int size, int* index, int left, int right)
{
	if ((*index) >= size || left >= right)
		return NULL;
	int p = PreOrder[(*index)];
	int pre = left; 
	int i = 0;
	BTNode* pRoot = NULL;
	while (pre < right)
	{
		//������������Ҹ�����λ��
		if (p == InOrder[pre])
			break;
		pre++;
	}
	if (pre == right)
		return NULL;
	//���������
	pRoot = BuyBTNode(p);

	//��������������
	if (left < pre)
	{
		++(*index);
		pRoot->_pLeft = RebuildBinTree(PreOrder, InOrder, size, index, left, pre);
	}
	
	//��������������
	if (pre+1 < right)
	{
		++(*index);
		pRoot->_pRight = RebuildBinTree(PreOrder, InOrder, size, index, pre + 1, right);
	}
	
	return pRoot;
}

void preOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	//���������
	printf("%d ", pRoot->_data);

	//����������������
	preOrder(pRoot->_pLeft);

	//����������������
	preOrder(pRoot->_pRight);
}

void PosOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;

	//����������������
	PosOrder(pRoot->_pLeft);

	//����������������
	PosOrder(pRoot->_pRight);

	//���������
	printf("%d ", pRoot->_data);
}
