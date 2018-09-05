#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTree.h"

void InitBSTree(BSTNode** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

BSTNode* BuyBSTNode(BSDataType data)
{
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (NULL == newNode)
	{
		printf("�����ڵ�ʧ��\n");
		return NULL;
	}
	newNode->_data = data;
	newNode->_pLeft = NULL;
	newNode->_pRight = NULL;
	return newNode;
}

void InOrder(BSTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	InOrder(pRoot->_pLeft);
	printf("%d ", pRoot->_data);
	InOrder(pRoot->_pRight);
}

bool InsertBSTree(BSTNode** pRoot, BSDataType data)
{
	assert(pRoot);
	if (*pRoot == NULL)
	{
		(*pRoot) = BuyBSTNode(data);
		return true;
	}
	else
	{
		BSTNode* pCur = (*pRoot);
		BSTNode *pParent = NULL;
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data == data)
			{
				return false;
			}
			else if (pCur->_data > data)
			{
				pCur = pCur->_pLeft;
			}
			else
			{
				pCur = pCur->_pRight;
			}
		}
		if (data > pParent->_data)
		{
			pParent->_pRight = BuyBSTNode(data);
			return true;
		}
		if (data < pParent->_data)
		{
			pParent->_pLeft = BuyBSTNode(data);
			return true;
		}
	}
	return false;
}

bool DelectBSTree(BSTNode** pRoot, BSDataType data)
{
	assert(pRoot);
	BSTNode* pCur = NULL;
	BSTNode* pParent = NULL;
	if (NULL == *pRoot)
		return false;
	else
	{
		//�ҵ���ɾ�����

		pCur = *pRoot;
		while (pCur)
		{
			if (data > pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else if (data < pCur->_data)
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
			BSTNode* Inorder = pCur->_pRight;
			
			while (Inorder->_pLeft)//����ѭ��������Inorder������������
			{
				pParent = Inorder;
				Inorder = Inorder->_pLeft;
			}
			pCur->_data = Inorder->_data;//����
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

BSTNode* FindBSTree(BSTNode* pRoot, BSDataType data)
{
	BSTNode* pCur = NULL;
	if (NULL == pRoot)
		return NULL;
	
	pCur = pRoot;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		else if (pCur->_data > data)
		{
			pCur = pCur->_pLeft;
		}
		else
		{
			pCur = pCur->_pRight;
		}
	}
	return NULL;
}

void DestroyBSTree(BSTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBSTree(&(*pRoot)->_pLeft);
		DestroyBSTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

BSTNode* FindBSTreeNor(BSTNode* pRoot, BSDataType data)
{
	if (NULL == pRoot)
		return NULL;
	else if (data == pRoot->_data)
		return pRoot;
	else if (data < pRoot->_data)
		return FindBSTreeNor(pRoot->_pLeft, data);
	else
		return FindBSTreeNor(pRoot->_pRight, data);
		
}

bool InsertBSTreeNor(BSTNode** pRoot, BSDataType data)
{
	assert(pRoot);
	if (NULL == *pRoot)
		*pRoot = BuyBSTNode(data);
	else
	{
		if (data == (*pRoot)->_data)
		{
			return false;
		}
		else if (data < (*pRoot)->_data)
			return InsertBSTree(&(*pRoot)->_pLeft, data);
		else
			return InsertBSTree(&(*pRoot)->_pRight, data);

	}
	return true;
}

bool DelectBSTreeNor(BSTNode** pRoot, BSDataType data)
{
	assert(pRoot);
	BSTNode* pCur = NULL;
	if (NULL == *pRoot)
		return false;
	else
	{
		pCur = *pRoot;
		if (data > pCur->_data)
		{
			return DelectBSTree(&pCur->_pRight, data);//Ϊʲô���ⲻ��return�����ԣ����ڱ���ʱ�ǿ��Ե�
		}
		else if (data < pCur->_data)
		{
			return DelectBSTree(&pCur->_pLeft, data);
		}
		else //data == pCur->_data
		{
			//��ʱ�Ѿ��ҵ��˴�ɾ�����
			BSTNode* pDel = pCur;
			if (NULL == pDel->_pLeft)
			{

			}
		}
	}
}