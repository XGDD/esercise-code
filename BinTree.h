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
//�ж�һ������Ƿ��ڶ�������
int IsBTNodeInBiTree(BTNode* pRoot, BDataType data);
//��һ������˫�׽��
BTNode* GetBTNodeParent(BTNode* pRoot, BDataType data);
//��������ľ���
void MirrorBinTree(BTNode* pRoot);
void MirrorBinTreeNor(BTNode* pRoot);//�ǵݹ飬�ö�
void Swap(BTNode** left, BTNode** right);
//�������������
void LevelOrder(BTNode* pRoot);
//�ж�һ�����Ƿ�����ȫ������
int IsCompleteBinTree(BTNode* pRoot);
////����ǰ�����������������ԭ������
//void RebuildBinTree(BTNode** pRoot, BDataType* str1, BDataType* str2, int size, int* index);
//ǰ/��/��������������ǵݹ飩
void PreOrderNor(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PosOrderNor(BTNode* pRoot);

#endif //__BINTREE_H__