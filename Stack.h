#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<assert.h>

#define MaxSize 10

typedef struct BTNode* SDataType;

typedef struct Stack
{
	SDataType _arry[MaxSize];
	int top;//size
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps, SDataType data);
void StackPop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void Print(Stack* ps);
SDataType StackTop(Stack* ps);

#endif //__STACK_H__