#define _CRT_SECURE_NO_WARNINGS 1

#include"RebuildBinTree.h"

int main()
{
	int index = 7;
	BTNode* pRoot = NULL;
	int PosOrder[] = { 7, 4, 2, 5, 8, 6, 3, 1 };
	int InOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	pRoot = RebuildBinTree(PosOrder, InOrder, 8, &index, 0, 8);
	preOrder(pRoot);
	printf("\n");
	
	inOrder(pRoot);
	printf("\n");
	posOrder(pRoot);
	printf("\n");

	return 0;
}