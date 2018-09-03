#ifndef __BINTREE_H__
#define __BINTREE_H__

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include"Queue.h"
#include"Stack.h"

typedef char BDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BDataType _data;
}BTNode;

void CreateBinTree(BTNode** pRoot, BDataType* str, int size, int* index, BDataType invalid);
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PosOrder(BTNode* pRoot);
BTNode* CopyBinTree(BTNode* pRoot);
void DestroyBinTree(BTNode** pRoot);
int GetBTNodeCount(BTNode* pRoot);
int GetLeafNodeCount(BTNode* pRoot);
int GetKLevelNodeCount(BTNode* pRoot, int K);
int Height(BTNode* pRoot);
BTNode* LeftChild(BTNode* pNode, BTNode** ch, BDataType data);
BTNode* RightChild(BTNode* Node, BTNode** ch, BDataType data);
//判断一个结点是否在二叉树中
int IsBTNodeInBiTree(BTNode* pRoot, BDataType data);
//求一个结点的双亲结点
BTNode* GetBTNodeParent(BTNode* pRoot, BDataType data);
//求二叉树的镜像
void MirrorBinTree(BTNode* pRoot);
void MirrorBinTreeNor(BTNode* pRoot);//非递归，用队
void Swap(BTNode** left, BTNode** right);
//层序遍历二叉树
void LevelOrder(BTNode* pRoot);
//判断一棵树是否是完全二叉树
int IsCompleteBinTree(BTNode* pRoot);
////根据前序和中序遍历结果，还原二叉树
//void RebuildBinTree(BTNode** pRoot, BDataType* str1, BDataType* str2, int size, int* index);
//前/中/后遍历二叉树（非递归）
void PreOrderNor(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PosOrderNor(BTNode* pRoot);

#endif //__BINTREE_H__