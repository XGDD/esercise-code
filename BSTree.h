#ifndef __BSTREE_H__
#define __BSTREE_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#define bool int
#define true 1
#define false 0

typedef char BSDataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	BSDataType _data;
}BSTNode;

void InitBSTree(BSTNode** pRoot);
bool InsertBSTree(BSTNode** pRoot, BSDataType data);
bool InsertBSTreeNor(BSTNode** pRoot, BSDataType data);
bool DelectBSTree(BSTNode** pRoot, BSDataType data);
bool DelectBSTreeNor(BSTNode** pRoot, BSDataType data);
BSTNode* FindBSTree(BSTNode* pRoot, BSDataType data);
BSTNode* FindBSTreeNor(BSTNode* pRoot, BSDataType data);
void DestroyBSTree(BSTNode** pRoot);
void InOrder(BSTNode* pRoot);

#endif //__BSTREE_H__ 