#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTreeNodeKV.h"

BSTNKV* BuyNode(k key, v value)
{
	BSTNKV* newNode = (BSTNKV*)malloc(sizeof(BSTNKV));
	if (NULL == newNode)
	{
		printf("�������ʧ��\n");
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
		//�ҵ���ɾ�����

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
		//ɾ�����

		//��ɾ�����Ҷ�ӽڵ����ֻ���Һ���
		if (NULL == pCur->_pLeft)
		{
			if (pCur == *pRoot)//����ɾ�����Ǹ����
				*pRoot = pCur->_pRight;
			else if (pCur == pParent->_pLeft)
				pParent->_pLeft = pCur->_pRight;
			else
				pParent->_pRight = pCur->_pRight;
		}
		//ֻ������
		else if (NULL == pCur->_pRight)
		{
			if (pCur == *pRoot)//����ɾ�����Ǹ����
				*pRoot = pCur->_pLeft;
			else if (pCur == pParent->_pLeft)
				pParent->_pLeft = pCur->_pLeft;
			else
				pParent->_pRight = pCur->_pLeft;
		}
		//���Һ��Ӷ�����
		else
		{
			//����������ɾ�����������������ߵ�������С��/���ɾ����������������ұߵ�������󣩣�����ɾ�����������/���ұߵ���������ɾ�������/���ұߵ���
			BSTNKV* Inorder = pCur->_pRight;
			pParent = Inorder;
			while (Inorder->_pLeft)//����ѭ��������Inorder������������
			{
				pParent = Inorder;
				Inorder = Inorder->_pLeft;
			}
			pCur->_data._value = Inorder->_data._value;//����
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