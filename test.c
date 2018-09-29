#define _CRT_SECURE_NO_WARNINGS 1

#include"RebuildBinTree.h"

int main()
{
	int index = 0;
	BTNode* pRoot = NULL;
	int PreOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int InOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	pRoot = RebuildBinTree(PreOrder, InOrder, 8, &index, 0, 8);
	preOrder(pRoot);
	printf("\n");
	
	inOrder(pRoot);
	printf("\n");
	PosOrder(pRoot);

	return 0;
}