#include"BinTree.h"

void test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	int ret = 0;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);

	BTNode* ch = NULL;
	RightChild(pRoot,&ch,'C');
	printf("%c\n", ch->_data);


	ret = Height(pRoot);
	printf("%d\n", ret);

	NewRoot = CopyBinTree(pRoot);
	DestroyBinTree(&NewRoot);

	printf("前序遍历：");
	PreOrder(NewRoot);
	printf("\n");

	printf("中序遍历：");
	InOrder(NewRoot);
	printf("\n");

	printf("后序遍历：");
	PosOrder(NewRoot);
	printf("\n");
}

void IsBTNodeInBiTree_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	int ret = 0;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	ret = IsBTNodeInBiTree(pRoot, 'G');
	if (1 == ret)
		printf("该结点在二叉树中\n");
	else
	{
		printf("该结点不在二叉树中\n");
	}
}

void GetBTNodeParent_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	BTNode* ch = NULL;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	GetBTNodeParent(pRoot, &ch, 'C');
	printf("%c\n", ch->_data);
}

void MirrorBinTree_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	BTNode* ch = NULL;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");

	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");

	printf("后序遍历：");
	PosOrder(pRoot);
	printf("\n");

	MirrorBinTreeNor(pRoot);
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");
}

void LevelOrder_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	BTNode* ch = NULL;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");

	printf("层序遍历：");
	LevelOrder(pRoot);
	printf("\n");
}

void IsCompleteBinTree_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	//BDataType str[] = "ABD###CE##F";
	BDataType str[] = "ABD##E##CF";
	int size = strlen(&str);
	int index = 0;
	BTNode* ch = NULL;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");

	int ret = IsCompleteBinTree(pRoot);
	if (1 == ret)
		printf("是完全二叉树\n"); 
	else
		printf("不是完全二叉树\n");
}


void PreOrderNor_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	BTNode* ch = NULL;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");

	printf("非递归前序遍历：");
	PreOrderNor(pRoot);
	printf("\n");
}

void InOrdreNor_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	BTNode* ch = NULL;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");

	printf("非递归中序遍历：");
	InOrderNor(pRoot);
	printf("\n");
}

void PosOrdreNor_test()
{
	BTNode* pRoot;
	BTNode* NewRoot;
	BDataType str[] = "ABD###CE##F";
	int size = strlen(&str);
	int index = 0;
	BTNode* ch = NULL;
	BDataType invalid = '#';
	CreateBinTree(&pRoot, str, size, &index, invalid);
	printf("后序遍历：");
	PosOrder(pRoot);
	printf("\n");

	printf("非递归后序遍历：");
	PosOrderNor(pRoot);
	printf("\n");
}


int main()
{
	//test();
	//IsBTNodeInBiTree_test();
	//GetBTNodeParent_test();
	//MirrorBinTree_test();
	//LevelOrder_test();
	//IsCompleteBinTree_test();
	//RebuildBinTree_test();
	//PreOrderNor_test();
	//InOrdreNor_test();
	PosOrdreNor_test();

	return 0;
}