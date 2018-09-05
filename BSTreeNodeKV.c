#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTreeNodeKV.h"

BSTNKV* BuyNode(k key, v value)
{
	BSTNKV* newNode = (BSTNKV*)malloc(sizeof(BSTNKV));
	if (NULL == newNode)
	{
		printf("创建结点失败\n");
		return NULL;
	}
	newNode->_data._key = key;
	newNode->_data._value = value;
	newNode->_pLeft = NULL;
	newNode->_pRight = NULL;
}

void InitBSTNKV(BSTNKV** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

void InsertBSTNKV(BSTNKV** pRoot, k key, v value)
{
	assert(pRoot);
	if (*pRoot == NULL)
		*pRoot = BuyNode(key, value);
	int tmp = strcmp((*pRoot)->_data._key, key);
	if (tmp > 0)
	{
		return InsertBSTNKV(&(*pRoot)->_pLeft, key, value);
	}
	else if (tmp < 0)
		return InsertBSTNKV(&(*pRoot)->_pRight, key, value);
	else
		return;
}

BSTNKV* FindBSTNKV(BSTNKV* pRoot, k key)
{
	if (pRoot == NULL)
		return NULL;
	int tmp = strcmp(pRoot->_data._key, key);
	if (tmp > 0)
		return FindBSTNKV(pRoot->_pLeft, key);
	else if (tmp < 0)
		return FindBSTNKV(pRoot->_pRight, key);
	else
		return pRoot;
}

void DestroyBSTNKV(BSTNKV** pRoot)
{
	assert(pRoot);
	while (*pRoot)
	{
		DestroyBSTNKV(&(*pRoot)->_pLeft);
		DestroyBSTNKV(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void DelectBSTNKV(BSTNKV** pRoot, k key)
{
	assert(pRoot);
	BSTNKV* pCur = NULL;
	BSTNKV* pParent = NULL;
	if (NULL == *pRoot)
		return false;
	else
	{
		//找到待删除结点

		pCur = *pRoot;
		while (pCur)
		{
			if (key > pCur->_data._key)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else if (key < pCur->_data._key)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
				break;
		}
		//删除结点

		//待删结点是叶子节点或者只有右孩子
		if (NULL == pCur->_pLeft)
		{
			if (pCur == *pRoot)//若果删除的是根结点
				*pRoot = pCur->_pRight;
			else if (pCur == pParent->_pLeft)
				pParent->_pLeft = pCur->_pRight;
			else
				pParent->_pRight = pCur->_pRight;
		}
		//只有左孩子
		else if (NULL == pCur->_pRight)
		{
			if (pCur == *pRoot)//若果删除的是根结点
				*pRoot = pCur->_pLeft;
			else if (pCur == pParent->_pLeft)
				pParent->_pLeft = pCur->_pLeft;
			else
				pParent->_pRight = pCur->_pLeft;
		}
		//左右孩子都存在
		else
		{
			//替代法，向待删除点的右子树找最左边的数（最小）/向待删除点的左子树找最右边的数（最大），将待删除点与最左边/最右边的数交换，删除最左边/最右边的数
			BSTNKV* Inorder = pCur->_pRight;
			pParent = Inorder;
			while (Inorder->_pLeft)//除了循环函数，Inorder不可能有左孩子
			{
				pParent = Inorder;
				Inorder = Inorder->_pLeft;
			}
			pCur->_data._value = Inorder->_data._value;//交换
			if (Inorder == pParent->_pLeft)
				pParent->_pLeft = Inorder->_pRight;
			else if (Inorder == pParent->_pRight)
				pParent->_pRight = Inorder->_pRight;
			pCur = Inorder;
		}
	}
	free(pCur);
	pCur = NULL;
	return true;
}