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

	printf("ǰ�������");
	PreOrder(NewRoot);
	printf("\n");

	printf("���������");
	InOrder(NewRoot);
	printf("\n");

	printf("���������");
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
		printf("�ý���ڶ�������\n");
	else
	{
		printf("�ý�㲻�ڶ�������\n");
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
	printf("ǰ�������");
	PreOrder(pRoot);
	printf("\n");

	printf("���������");
	InOrder(pRoot);
	printf("\n");

	printf("���������");
	PosOrder(pRoot);
	printf("\n");

	MirrorBinTreeNor(pRoot);
	printf("ǰ�������");
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
	printf("ǰ�������");
	PreOrder(pRoot);
	printf("\n");

	printf("���������");
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
	printf("ǰ�������");
	PreOrder(pRoot);
	printf("\n");

	int ret = IsCompleteBinTree(pRoot);
	if (1 == ret)
		printf("����ȫ������\n"); 
	else
		printf("������ȫ������\n");
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
	printf("ǰ�������");
	PreOrder(pRoot);
	printf("\n");

	printf("�ǵݹ�ǰ�������");
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
	printf("���������");
	InOrder(pRoot);
	printf("\n");

	printf("�ǵݹ����������");
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
	printf("���������");
	PosOrder(pRoot);
	printf("\n");

	printf("�ǵݹ���������");
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