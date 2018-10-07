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


BTNode* RebuildBinTree(BDataType* PosOrder, BDataType* InOrder, int size, int* index, int left, int right)
{
	if ((*index) < 0 || left >= right)
		return NULL;
	int p = PosOrder[(*index)];
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
	if (pre + 1 < right)
	{
		--(*index);
		pRoot->_pRight = RebuildBinTree(PosOrder, InOrder, size, index, pre + 1, right);
	}

	//��������������
	if (left < pre)
	{
		--(*index);
		pRoot->_pLeft = RebuildBinTree(PosOrder, InOrder, size, index, left, pre);
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

void posOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;

	//����������������
	posOrder(pRoot->_pLeft);

	//����������������
	posOrder(pRoot->_pRight);

	//���������
	printf("%d ", pRoot->_data);
}
