#ifndef _DPAR_H__
#define _DPAR_H__
#include<stdio.h>
#include<stdlib.h>
typedef struct Node //���з��������Ķ���
{
	struct Node* pre;
	struct Node* next;
	int size;//��С
	int address;//ʼַ
	int state;//״̬  0--����  1--�ѷ���
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