#define _CRT_SECURE_NO_WARNINGS 1

#include"JudgeWord.h"

void InitBSTKNode(BSTKNode** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

BSTKNode* BuyNode(KeyType key)
{
	BSTKNode* newNode = NULL;
	newNode = (BSTKNode*)malloc(sizeof(BSTKNode));
	if (NULL == newNode)
	{
		printf("创建结点失败\n");
		return NULL;
	}
	newNode->_key = key;
	newNode->_pLeft = NULL;
	newNode->_pRight = NULL;
	return newNode;
}

void InsertBSTKNode(BSTKNode** pRoot, KeyType key)
{
	assert(pRoot);
	if (NULL == *pRoot)
	{
		*pRoot = BuyNode(key);
		return;
	}
	int tmp = 0;
	tmp = strcmp((*pRoot)->_key, key);
	if (tmp > 0)
	{
		return InsertBSTKNode(&(*pRoot)->_pRight, key);
	}
	else if (tmp < 0)
	{
		return InsertBSTKNode(&(*pRoot)->_pLeft, key);
	}
	else
		return;
}

BSTKNode* FindBSTKNode(BSTKNode* pRoot, KeyType key)
{
	if (NULL == pRoot)
		return NULL;
	int tmp = strcmp(pRoot->_key, key);
	if (tmp > 0)
		return FindBSTKNode(pRoot->_pLeft, key);
	else if (tmp < 0)
		return FindBSTKNode(pRoot->_pRight, key);
	else
		return pRoot;
}