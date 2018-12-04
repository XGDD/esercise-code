#ifndef _DPAR_H__
#define _DPAR_H__
#include<stdio.h>
#include<stdlib.h>
typedef struct Node //空闲分区链结点的定义
{
	struct Node* pre;
	struct Node* next;
	int size;//大小
	int address;//始址
	int state;//状态  0--空闲  1--已分配
}Node;
Node L;
typedef struct usenode
{
	struct usenode* next;
	int num;
	int add;
	int size;
}U, *N;
U u;
N n;
#endif //_DPAR_H__