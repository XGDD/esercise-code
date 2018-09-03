#include"BinTree.h"

BTNode* BuyBTNode(BDataType data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == NewNode)
	{
		printf("�������ʧ�ܣ�\n");
		return;
	}
	else
	{
		NewNode->_data = data;
		NewNode->_pLeft = NULL;
		NewNode->_pRight = NULL;
	}
	return NewNode;
}

void CreateBinTree(BTNode** pRoot, BDataType* str, int size, int* index, BDataType invalid)
{
	assert(pRoot);
	while ((*index) < size && str[*index] != invalid)
	{
		//���������
		(*pRoot) = BuyBTNode(str[*index]);

		//����������
		(*index)++;
		CreateBinTree(&(*pRoot)->_pLeft, str, size, index, invalid);

		//����������
		(*index)++;
		CreateBinTree(&(*pRoot)->_pRight, str, size, index, invalid);
	}
}

void PreOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	//���������
	printf("%c ", pRoot->_data);

	//����������������
	PreOrder(pRoot->_pLeft);

	//����������������
	PreOrder(pRoot->_pRight);
}

void InOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;

	//����������������
	InOrder(pRoot->_pLeft);

	//���������
	printf("%c ", pRoot->_data);

	//����������������
	InOrder(pRoot->_pRight);
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
	printf("%c ", pRoot->_data);
}

BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* NewRoot = NULL;
	if (pRoot != NULL)
	{
		//���Ƹ����
		NewRoot = pRoot;
		//����������
		CopyBinTree(pRoot->_pLeft);
		//����������
		CopyBinTree(pRoot->_pRight);
	}
	else
		return NULL;
	return NewRoot;
}

void DestroyBinTree(BTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot == NULL)
	{
		return;
	}
	//ɾ��������
	DestroyBinTree(&(*pRoot)->_pLeft);

	//ɾ��������
	DestroyBinTree(&(*pRoot)->_pRight);

	//ɾ�������
	free(*pRoot);
	(*pRoot) = NULL;
}

int GetBTNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	else
		return GetBTNodeCount(pRoot->_pLeft) + GetBTNodeCount(pRoot->_pRight) + 1;
}

int GetLeafNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	else if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;
	else
		return GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight);
}

int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (pRoot == NULL)
		return 0;
	else if (K == 0)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

int Height(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	return Height(pRoot->_pLeft) > Height(pRoot->_pRight) ? Height(pRoot->_pLeft) + 1 : Height(pRoot->_pRight) + 1;
}

BTNode* LeftChild(BTNode* pNode, BTNode** ch, BDataType data)
{
	if (pNode == NULL)
		return NULL;
	if (pNode->_data == data)
		return *ch = pNode->_pLeft;
	else
	{
		LeftChild(pNode->_pLeft, ch, data);
		LeftChild(pNode->_pRight, ch, data);
	}
}

BTNode* RightChild(BTNode* pNode, BTNode** ch, BDataType data)
{
	if (pNode == NULL)
		return NULL;
	if (pNode->_data == data)
		return *ch = pNode->_pRight;
	else
	{
		RightChild(pNode->_pLeft, ch, data);
		RightChild(pNode->_pRight, ch, data);
	}
}

int IsBTNodeInBiTree(BTNode* pRoot, BDataType data)
{
	if (NULL == pRoot)
		return 0;
	if (pRoot->_data == data)
		return 1;
	IsBTNodeInBiTree(pRoot->_pLeft, data);
	IsBTNodeInBiTree(pRoot->_pRight, data);
}

BTNode* GetBTNodeParent(BTNode* pRoot, BTNode** ch, BDataType data)
{
	if (NULL == pRoot)
		return NULL;
	if (pRoot->_pLeft && pRoot->_pLeft->_data == data)
		return *ch = pRoot;
	if (pRoot->_pRight && pRoot->_pRight->_data == data)
		return *ch = pRoot;
	GetBTNodeParent(pRoot->_pLeft, ch, data);
	GetBTNodeParent(pRoot->_pRight, ch, data);
}

void Swap(BTNode** left, BTNode** right)
{
	BTNode* tmp = NULL;
	tmp = *left;
	*left = *right;
	*right = tmp;
}

void MirrorBinTree(BTNode* pRoot)
{
	if (NULL == pRoot)
		return NULL;
	Swap(&pRoot->_pLeft, &pRoot->_pRight);
	MirrorBinTree(pRoot->_pLeft);
	MirrorBinTree(pRoot->_pRight);
}

void MirrorBinTreeNor(BTNode* pRoot)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueIsEmpty(&q))
	{
		QDataType cur = QueueFront(&q);
		if (cur->_pLeft)
			QueuePush(&q, cur->_pLeft);
		if (cur->_pRight)
			QueuePush(&q, cur->_pRight);
		Swap(&cur->_pLeft, &cur->_pRight);
		QueuePop(&q);
	}
}

void LevelOrder(BTNode* pRoot)
{
	Queue q;
	QDataType ret = NULL;
	if (NULL == pRoot)
		return NULL;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueIsEmpty(&q))
	{
		ret = QueueFront(&q);
		printf("%c ", ret->_data);
		if (ret->_pLeft)
			QueuePush(&q, ret->_pLeft);
		if (ret->_pRight)
			QueuePush(&q, ret->_pRight);
		QueuePop(&q);
	}
}

int IsCompleteBinTree(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 1;
	int IsFlag = 0;
	Queue q;
	QDataType ret = NULL;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueIsEmpty(&q))
	{
		ret = QueueFront(&q);
		if (IsFlag == 1)//�������ȫ��������˵����ߵĽ��û�����Һ���
		{
			if (ret->_pLeft || ret->_pRight)
				return 0;
		}
		if (ret->_pLeft && ret->_pRight)
		{
			QueuePush(&q, ret->_pLeft);
			QueuePush(&q, ret->_pRight);
		}
		else if (ret->_pLeft)   //�ý��ֻ�����ӣ�û���Һ��ӣ�˵���ý�����Ǹ��ٽ��㣬��֮������н�㶼û�����Һ��ӵĻ��������������ȫ��������IsFlag���Ϊ1
		{
			QueuePush(&q, ret->_pLeft);
			IsFlag = 1;
		}
		else if (ret->_pRight)
		{
			return 0;
		}
		else   //�ý�����Һ��Ӷ�������
		{
			IsFlag = 1;
			//return;
		}
		QueuePop(&q);
	}
	return 1;
}



void PreOrderNor(BTNode* pRoot)
{
	Stack s;
	SDataType pCur = NULL;
	StackInit(&s);
	StackPush(&s, pRoot);
	while (!StackEmpty(&s))
	{
		pCur = StackTop(&s);
		StackPop(&s);
		while (pCur)
		{
			printf("%c ", pCur->_data);
			if (pCur->_pRight)
			{
				StackPush(&s, pCur->_pRight);
			}
			pCur = pCur->_pLeft;
		}
	}
}

void InOrderNor(BTNode* pRoot)
{
	Stack s;
	SDataType pCur = NULL;
	SDataType Top = NULL;
	StackInit(&s);
	StackPush(&s, pRoot);
	pCur = StackTop(&s);
	StackPop(&s);
	//����pCurΪ���Ķ�������������һ����㣬������������·�������Խ��
	while (!StackEmpty(&s) || pCur)
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		Top = StackTop(&s);
		printf("%c ", Top->_data);
		StackPop(&s);
		if (Top->_pRight)
			pCur = Top->_pRight;
	}
}

void PosOrderNor(BTNode* pRoot)
{
	Stack s;
	SDataType pCur = NULL;
	SDataType pPrev = NULL;//���������ʹ��Ľ��
	SDataType Top = NULL;
	StackInit(&s);
	StackPush(&s, pRoot);
	pCur = StackTop(&s);
	StackPop(&s);
	while (!StackEmpty(&s) || pCur)
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		Top = StackTop(&s);
		//��TopΪ���Ķ������ĸ��ڵ㲻�ܱ�������������������Ϊ��/�������Ѿ�������
		if (Top->_pRight == NULL || Top->_pRight == pPrev)
		{
			printf("%c ", Top->_data);
			pPrev = Top;
			StackPop(&s);
		}
		else
			pCur = Top->_pRight;
	}
}
