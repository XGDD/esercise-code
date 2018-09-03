#include"BinTree.h"

BTNode* BuyBTNode(BDataType data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == NewNode)
	{
		printf("创建结点失败！\n");
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
		//创建根结点
		(*pRoot) = BuyBTNode(str[*index]);

		//创建左子树
		(*index)++;
		CreateBinTree(&(*pRoot)->_pLeft, str, size, index, invalid);

		//创建右子树
		(*index)++;
		CreateBinTree(&(*pRoot)->_pRight, str, size, index, invalid);
	}
}

void PreOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	//遍历根结点
	printf("%c ", pRoot->_data);

	//遍历根结点的左子树
	PreOrder(pRoot->_pLeft);

	//遍历根结点的右子树
	PreOrder(pRoot->_pRight);
}

void InOrder(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;

	//遍历根结点的左子树
	InOrder(pRoot->_pLeft);

	//遍历根结点
	printf("%c ", pRoot->_data);

	//遍历根结点的右子树
	InOrder(pRoot->_pRight);
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
	printf("%c ", pRoot->_data);
}

BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* NewRoot = NULL;
	if (pRoot != NULL)
	{
		//复制根结点
		NewRoot = pRoot;
		//复制左子树
		CopyBinTree(pRoot->_pLeft);
		//复制右子树
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
	//删除左子树
	DestroyBinTree(&(*pRoot)->_pLeft);

	//删除右子树
	DestroyBinTree(&(*pRoot)->_pRight);

	//删除根结点
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
		if (IsFlag == 1)//如果是完全二叉树，说明后边的结点没有左右孩子
		{
			if (ret->_pLeft || ret->_pRight)
				return 0;
		}
		if (ret->_pLeft && ret->_pRight)
		{
			QueuePush(&q, ret->_pLeft);
			QueuePush(&q, ret->_pRight);
		}
		else if (ret->_pLeft)   //该结点只有左孩子，没有右孩子，说明该结点是那个临界结点，它之后的所有结点都没有左右孩子的话，这课树就是完全二叉树，IsFlag标记为1
		{
			QueuePush(&q, ret->_pLeft);
			IsFlag = 1;
		}
		else if (ret->_pRight)
		{
			return 0;
		}
		else   //该结点左右孩子都不存在
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
	//找以pCur为根的二叉树的最左侧的一个结点，并保存所经过路径的所以结点
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
	SDataType pPrev = NULL;//标记最近访问过的结点
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
		//以Top为根的二叉树的根节点不能遍历，除非它的右子树为空/右子树已经遍历了
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
