#ifndef __BSTREENODEKV_H__
#define __BSTREENODEKV_H__

#define false 0
#define true 1

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef char* k;//ÖÐÎÄ
typedef char* v;//Ó¢ÎÄ

typedef struct Pair
{
	k _key;
	v _value;
}Pair;

typedef struct BSTreeNodeKV
{
	struct BSTreeNodeKV* _pLeft;
	struct BSTreeNodeKV* _pRight;
	Pair _data;
}BSTNKV;

void InitBSTNKV(BSTNKV** pRoot);
void InsertBSTNKV(BSTNKV** pRoot, k key, v value);
BSTNKV* FindBSTNKV(BSTNKV* pRoot, k key);
void DestroyBSTNKV(BSTNKV** pRoot);
void DelectBSTNKV(BSTNKV** pRoot, k key);


#endif //__BSTREENODEKV_H__