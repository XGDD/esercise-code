#define _CRT_SECURE_NO_WARNINGS 1

#include"RebuildBinTree.h"

BTNode* BuyBTNode(BDataType data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == NewNode)
	{
		printf("创建结点失败！\n");
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

	//遍历根结点的左子树
	inOrder(pRoot->_pLeft);

	//遍历根结点
	printf("%d ", pRoot->_data);

	//遍历根结点的右子树
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
		//在中序遍历中找根结点的位置
		if (p == InOrder[pre])
			break;
		pre++;
	}
	if (pre == right)
		return NULL;
	//创建根结点
	pRoot = BuyBTNode(p);

	//创建根的左子树
	if (left < pre)
	{
		++(*index);
		pRoot->_pLeft = RebuildBinTree(PreOrder, InOrder, size, index, left, pre);
	}
	
	//创建根的右子树
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
	//遍历根结点
	printf("%d ", pRoot->_data);

	//遍历根结点的左子树
	preOrder(pRoot->_pLeft);

	//遍历根结点的右子树
	preOrder(pRoot->_pRight);
}

void PosOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;

	//遍历根结点的左子树
	PosOrder(pRoot->_pLeft);

	//遍历根结点的右子树
	PosOrder(pRoot->_pRight);

	//遍历根结点
	printf("%d ", pRoot->_data);
}
