#ifndef __JUDGEWORD_H__
#define __JUDGEWORD_H__

#include<string.h>
#include<assert.h>

typedef char* KeyType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	KeyType _key;
}BSTKNode;

void InitBSTKNode(BSTKNode** pRoot);
void InsertBSTKNode(BSTKNode** pRoot, KeyType key);
BSTKNode* FindBSTKNode(BSTKNode* pRoot, KeyType key);

#endif //__JUDGEWORD_H__