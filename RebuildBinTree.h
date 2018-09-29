#ifndef __REBUILDBINTREE_H__
#define __REBUILDBINTREE_H__

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>

typedef int BDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BDataType _data;
}BTNode;

BTNode* BuyBTNode(BDataType data);

//����ǰ�����������������ԭ������
BTNode* RebuildBinTree(BDataType* PreOrder, BDataType* InOrder, int size, int* index, int left, int right);
void preOrder(BTNode* pRoot);
void PosOrder(BTNode* pRoot);
void inOrder(BTNode* pRoot);

#endif //__REBUILDBINTREE_H__